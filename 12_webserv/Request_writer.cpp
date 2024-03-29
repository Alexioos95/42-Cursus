/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request_writer.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:56:04 by apayen            #+#    #+#             */
/*   Updated: 2024/03/27 11:53:43 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Request.hpp"
#include "Client.hpp"

//////////////////////////////
// Function: writer
int	Request::writer(void)
{
	if (this->_inparse)
	{
		this->parsing();
		this->_inparse = false;
		this->_inprocess = true;
	}
	if (this->_inprocess && this->processing() == 1)
		return (1);
	if (this->_inbuild)
	{
		this->buildResponse();
		this->_inbuild = false;
		this->_inwrite = true;
		return (1);
	}
	if (this->_inwrite)
		return (this->writing());
	return (1);
}

void	Request::parsing(void)
{
	this->_status = this->parse();
	if (this->_status == "102 Processing")
	{
		if (this->_iscgi)
			return ;
		else if (this->_method == "GET")
		{
			if (this->_autoindex)
			{
				std::string tmp;

				if (autoindex(this->_dir.c_str(), this->_serv.getRoot(), tmp))
				{
					this->_bodyresponse.insert(this->_bodyresponse.end(), tmp.begin(), tmp.end());
					this->_contentlength = this->_bodyresponse.size();
					this->_stat.st_mtime = std::time(0);
					this->_status = "200 OK";
				}
				else
					this->_status = "500 Internal Server Error";
			}
			else
				this->_status = this->openf();
		}
		else if (this->_method == "DELETE")
			this->_status = this->del();
		else if (this->_method == "POST" && !this->_multi)
			this->_status = this->create();
	}
}

int	Request::processing(void)
{
	if (this->_status == "102 Processing")
	{
		if (this->_iscgi)
		{
			this->processCGI();
			return (1);
		}
		else if (this->_multi)
		{
			this->_status = this->multipost();
			if (this->_status == "102 Processing")
				return (1);
		}
		else if (this->_method == "GET")
			this->_status = this->get();
		else if (this->_method == "POST" && !this->_multi)
			this->_status = this->post();
	}
	if (this->_status == "200 OK" || this->_status == "202 Created")
	{
		this->_inprocess = false;
		this->_inbuild = true;
	}
	else if (this->_status != "102 Processing")
	{
		std::string tmp;

		if (this->_status == "400 Bad Request" || this->_status == "500 Internal Server Error")
			this->_client->setKeepAlive(false);
		if (this->_status != "301 Moved Permanently")
			tmp = this->error();
		if (tmp != "102 Processing")
		{
			this->_inprocess = false;
			this->_inbuild = true;
		}
	}
	return (0);
}

void	Request::processCGI(void)
{
	try
	{
		char						buffer[4096];
		ssize_t						bytes;
		int							status;
		std::vector<char>::iterator	it;
		std::vector<std::string>	env;

		status = 0;
		if (this->_cgi == NULL)
		{
			env.push_back("HTTP_COOKIE=" + this->_cookie);
			env.push_back("REQUEST_METHOD=" + this->_method);
			env.push_back("FD=" + itoa(this->_client->getFD()));
			env.push_back("PORT=" + itoa(this->_client->getPort()));
			this->_cgi = new Cgi(*this->_client->getManager(), env);
		}
		if (!this->_body.empty())
		{
			bytes = this->_body.size();
			if (bytes >= 4096)
				bytes = 4096;
			if (write(this->_cgi->getFdWrite(), this->_body.data(), bytes) < bytes)
			{
				errno = 0;
				this->_body.erase(this->_body.begin(), this->_body.end());
				this->_status = "500 Internal Server Error";
				return ;
			}
			this->_body.erase(this->_body.begin(), this->_body.begin() + bytes);
			if (!this->_body.empty())
				return ;
		}
		if (this->_cgi->getPid() == -1)
			this->_cgi->launchCgi(this->_filepath);
		if (this->_inreadcgi || waitpid(this->_cgi->getPid(), &status, WNOHANG) > 0)
		{
			if (WIFEXITED(status))
				status = (WEXITSTATUS(status));
			if (status > 0)
			{
				this->_status = "500 Internal Server Error";
				return ;
			}
			bytes = read(this->_cgi->getFdRead(), buffer, 4096);
			if (bytes < 0)
			{
				errno = 0;
				this->_response.erase(this->_response.begin(), this->_response.end());
				this->_status = "500 Internal Server Error";
			}
			else
			{
				this->_inreadcgi = true;
				this->_response.insert(this->_response.end(), &buffer[0], &buffer[bytes]);
				if (bytes < 4096)
				{
					this->_inprocess = false;
					this->_inwrite = true;
					this->delCGI();
				}
			}
		}
	}
	catch (const std::string &error)
	{
		this->_status = error;
	}
	catch (const std::exception &e)
	{
		std::cerr << "[!] Couldn't execute a CGI for client (fd " << this->_client->getFD() << ") on port " << this->_client->getPort() << "\n" << std::endl;
		this->_status = "500 Internal Server Error";
	}
}

int	Request::writing(void)
{
	size_t	len;

	if (!this->_response.empty())
	{
		len = this->_response.size();
		if (len > 4096)
			len = 4096;
		if (send(this->_client->getFD(), this->_response.data(), len, 0) <= 0)
		{
			errno = 0;
			return (-1);
		}
		this->_response.erase(this->_response.begin(), this->_response.begin() + len);
		if (this->_response.empty())
			return (0);
		return (1);
	}
	return (0);
}

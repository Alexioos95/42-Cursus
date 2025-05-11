/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request_parsing.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:15:58 by apayen            #+#    #+#             */
/*   Updated: 2024/03/28 08:52:13 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Request.hpp"
#include "Client.hpp"

#define	CRLF "\r\n"
#define	CONTLEN "Content-Length: "
#define	CONNECTION "Connection: keep-alive"
#define COOKIE "Cookie: "

//////////////////////////////
// Function: writer - parser
std::string	Request::parse(void)
{
	size_t							pos;
	std::vector<char>::iterator		it;
	std::vector<char>::iterator		ite;
	std::string						line;
	std::string						root;
	std::string						version;
	std::string						length;

	if (this->_header.size() < 26)
		return ("400 Bad Request");
	it = std::search(this->_header.begin(), this->_header.end(), CRLF, &CRLF[2]);
	line = std::string(this->_header.begin(), it);
	if (line.empty())
		return ("400 Bad Request");
	if (!this->searchServ())
		return ("400 Bad Request");
	root = this->_serv.getRoot();
	this->_method = line.substr(0, line.find(' '));
	if (this->_method != "GET" && this->_method != "POST" && this->_method != "DELETE")
		return ("405 Method Not Allowed");
	pos = this->_method.length() + 1;
	this->_filename = line.substr(pos, (line.find(' ', pos) - (pos)));
	if (this->_filename.empty())
		return ("400 Bad Request");
	else if (this->_filename.find("..") != std::string::npos)
		return ("403 Forbidden");
	this->_filepath = "Servers/" + root + '/' + this->_filename;
	pos = this->_filename.length() + 2;
	version = line.substr((this->_method.length() + pos), (line.find("\r\n") - (this->_method.length() + pos + 1)));
	if (version != "HTTP/1.1")
		return ("505 HTTP Version not supported");
	it = std::search(this->_header.begin(), this->_header.end(), CONTLEN, &CONTLEN[16]);
	if (it != this->_header.end())
	{
		if (this->_method == "DELETE")
			return ("400 Bad Request");
		it = std::search(this->_header.begin(), this->_header.end(), CONTLEN, &CONTLEN[16]);
		ite = std::search(it, this->_header.end(), CRLF, &CRLF[2]);
		length = std::string(it + 16, ite);
		if (this->_serv.getBodymax() < std::atoi(length.c_str()))
			return ("413 Request Entity Too Large");
	}
	else if (this->_method == "POST")
		return ("400 Bad Request");
	it = std::search(this->_header.begin(), this->_header.end(), COOKIE, &COOKIE[8]);
	if (it != this->_header.end())
	{
		ite = std::search(it, this->_header.end(), CRLF, &CRLF[2]);
		this->_cookie = std::string(it + 8, ite);
	}
	if (std::search(this->_header.begin(), this->_header.end(), CONNECTION, &CONNECTION[22]) == this->_header.end())
		this->_client->setKeepAlive(false);
	else
		this->_client->setKeepAlive(true);
	return (this->checkLocation());
}

bool	Request::searchServ()
{
	std::vector<char>::iterator	it;
	std::vector<char>::iterator	ite;
	std::string					host;
	std::string					port;

	host = "\r\nHost: ";
	it = std::search(this->_header.begin(), this->_header.end(), host.begin(), host.end());
	if (it == this->_header.end())
		return (false);
	ite = std::search(it + 2, this->_header.end(), CRLF, &CRLF[2]);
	host = std::string(it + 8, ite);
	if (host.empty() || host.find(':') == std::string::npos || host.find(':') == 0)
		return (false);
	this->_name = host.substr(0, host.find(':'));
	if (this->_name.empty())
		return (false);
	port = host.substr(this->_name.length() + 1, host.find("\r\n") - this->_name.length());
	if (port.empty())
		return (false);
	try
	{
		this->_serv = this->_client->getManager()->getServ(this->_name, std::atoi(port.c_str()));
	}
	catch (const std::exception &e)
	{
		return (false);
	}
	return (true);
}

std::string	Request::checkLocation(void)
{
	Location 	l;
	struct stat st;
	std::string	status;

	status = "102 Processing";
	ft_memset(&st, 0, sizeof(st));
	l = this->_serv.getLocation(this->_filename);
	if (!l.allowMethod(this->_method, this->_get, this->_post, this->_del))
		return ("405 Method Not Allowed");
	if (this->_filename.length() > 4 \
		&& (this->_filename.substr(this->_filename.length() - 4, 4) == ".php" \
		|| this->_filename.substr(this->_filename.length() - 5, 5) == ".ruby" \
		|| this->_filename.substr(this->_filename.length() - 3, 3) == ".py"))
	{
		if (!l.allowCgi() || this->_method == "DELETE")
			return ("403 Forbidden");
		else
			this->_iscgi = true;
	}
	if (this->_method == "POST" && !this->_iscgi)
	{
		if (l.getDirPost().first)
		{
			if (this->_multi)
				this->_filename = l.getDirPost().second + '/';
			else
				this->_filename = l.getDirPost().second + '/' + this->_filename;
		}
		this->_filepath = "Servers/" + this->_serv.getRoot() + '/' + this->_filename;
	}
	if (l.getAlias().first)
	{
		this->_filename.replace(this->_filename.find(l.getPath()), l.getPath().length(), l.getAlias().second);
		this->_filepath = "Servers/" + this->_serv.getRoot() + '/' + this->_filename;
	}
	if (this->_method == "GET")
	{
		if (stat(this->_filepath.c_str(), &st) == -1)
		{
			if (errno > 0 && errno != ENOENT)
			{
				errno = 0;
				return ("500 Internal Server Error");
			}
			errno = 0;
		}
		if (S_ISDIR(st.st_mode))
		{
			this->_dir = "Servers/" + this->_serv.getRoot() + '/' + this->_filename;
			if (l.getIndex().first)
			{
				this->_filename = l.getIndex().second;
				this->_filepath = "Servers/" + this->_serv.getRoot() + '/' + this->_filename;
			}
			else if (l.allowAutoindex())
				this->_autoindex = true;
			else
				status = "403 Forbidden";
		}
	}
	if (l.getReturn().first)
	{
		this->_filename = l.getReturn().second;
		if (this->simulateRedirect(this->_filename) == -1)
			status = "310 Too many Redirects";
		status = "301 Moved Permanently";
	}
	return (status);
}

int	Request::simulateRedirect(std::string path)
{
	Location	l;

	this->_redirected++;
	if (this->_redirected >= 9)
		return (-1);
	l = this->_serv.getLocation(path);
	if (l.getReturn().first)
		return (this->simulateRedirect(l.getReturn().second));
	return (0);
}

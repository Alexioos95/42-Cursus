/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request_reader.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:14:12 by apayen            #+#    #+#             */
/*   Updated: 2024/03/26 11:49:47 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Request.hpp"
#include "Client.hpp"

#define	CRLF "\r\n"
#define	CRLF2 "\r\n\r\n"
#define	CONTLEN "Content-Length: "
#define FILENAME "filename=\""
#define MULTI "\r\nContent-Type: multipart/form-data"
#define BOUND "boundary="

//////////////////////////////
// Function: reader
int	Request::reader(void)
{
	char						buffer[2048];
	int							bytes;
	std::vector<char>::iterator	pos;

	bytes = recv(this->_client->getFD(), buffer, 2048, 0);
	if (bytes <= 0)
	{
		errno = 0;
		return (bytes);
	}
	this->_request.insert(this->_request.end(), &buffer[0], &buffer[bytes]);
	pos = std::search(this->_request.begin(), this->_request.end(), CRLF2, &CRLF2[4]);
	if (!this->_multi && (pos == this->_request.end() || this->_contentlength + bytes < this->_maxcontentlength))
		return (bytes);
	if (this->_request.empty() || std::search(this->_header.begin(), this->_header.end(), CRLF2, &CRLF2[4]) == this->_header.end())
		this->fillHeader(pos, bytes);
	else
		this->fillBody(pos, bytes);
	return (bytes);
}

void	Request::fillHeader(std::vector<char>::iterator pos, int bytes)
{
	std::vector<char>::iterator	it;
	std::string					nb;

	this->_header.insert(this->_header.end(), this->_request.begin(), pos + 4);
	this->_request.erase(this->_request.begin(), pos + 4);
	std::cout << "[*] Header of client (fd " << this->_client->getFD() << ") on port " << this->_client->getPort() << "\n"; printvector(this->_header, 2);
	pos = std::search(this->_header.begin(), this->_header.end(), CONTLEN, &CONTLEN[16]);
	if (pos == this->_header.end())
	{
		this->_client->setToRead(false);
		return ;
	}
	it = std::search(pos + 16, this->_header.end(), CRLF, &CRLF[2]);
	nb = std::string(pos + 16, it);
	this->_maxcontentlength = std::atoi(nb.c_str());
	pos = std::search(this->_header.begin(), this->_header.end(), MULTI, &MULTI[35]);
	if (pos != this->_header.end())
	{
		std::vector<char>::iterator	it;

		this->_multi = true;
		pos = std::search(pos, this->_header.end(), BOUND, &BOUND[9]);
		it = std::search(pos + 10, this->_header.end(), CRLF, &CRLF[2]);
		std::string	tmp(pos + 10, it);
		this->_boundary = tmp;
	}
	if (!this->_request.empty())
	{
		pos = std::search(this->_request.begin(), this->_request.end(), CRLF2, &CRLF2[4]);
		this->fillBody(pos, bytes);
	}
}

void	Request::fillBody(std::vector<char>::iterator pos, int bytes)
{
	if (!this->_multi)
	{
		if (std::search(this->_request.begin(), this->_request.end(), CRLF, &CRLF[2]) != this->_request.end())
		{
			this->_body.insert(this->_body.end(), this->_request.begin(), pos + 4);
			this->_request.erase(this->_request.begin(), pos + 4);
		}
		else
		{
			this->_body.insert(this->_body.end(), this->_request.begin(), this->_request.end());
			this->_request.erase(this->_request.begin(), this->_request.end());
		}
		this->_contentlength = this->_contentlength + bytes;
		if (this->_contentlength > this->_maxcontentlength && this->_maxcontentlength > -1)
			this->_body.resize(this->_maxcontentlength);
		if ((this->_contentlength >= this->_maxcontentlength && this->_maxcontentlength > -1) \
			|| (std::search(this->_body.begin(), this->_body.end(), CRLF, &CRLF[2]) != this->_body.end()))
		{
			this->_contentlength = 0;
			this->_client->setToRead(false);
		}
	}
	else if (this->_request.size() < static_cast<unsigned long>(this->_maxcontentlength) \
		&& (std::find_end(this->_request.begin(), this->_request.end(), this->_boundary.begin(), this->_boundary.end()) + this->_boundary.length() + 5) != this->_request.end())
		return ;
	else
		this->parseMultiEncoded();
}

void	Request::parseMultiEncoded(void)
{
	std::string							bound;
	std::vector<char>::iterator			it;
	std::vector<char>::iterator			ite;
	std::string							name;
	std::vector<char>					content;

	bound = "--" + this->_boundary;
	while (1)
	{
		it = std::search(this->_request.begin(), this->_request.end(), bound.begin(), bound.end());
		if (it == this->_request.end())
			break ;
		this->_request.erase(this->_request.begin(), (it + bound.length() + 2));
		it = std::search(this->_request.begin(), this->_request.end(), FILENAME, &FILENAME[10]);
		if (it == this->_request.end())
			break ;
		ite = std::search(it, this->_request.end(), CRLF, &CRLF[2]);
		if (ite == this->_request.end())
			break ;
		name = std::string(it + 10, ite - 1);
		it = std::search(this->_request.begin(), this->_request.end(), CRLF2, &CRLF2[4]);
		if (it == this->_request.end())
			break ;
		this->_request.erase(this->_request.begin(), it + 4);
		it = std::search(this->_request.begin(), this->_request.end(), bound.begin(), bound.end());
		if (it == this->_request.end())
			break ;
		content.insert(content.end(), this->_request.begin(), it - 3);
		this->_files.push_back(std::pair<std::string, std::vector<char> >(name, content));
		content.erase(content.begin(), content.end());
		this->_request.erase(this->_request.begin(), it);
		if (this->_request.size() == 2)
			break ;
	}
	this->_client->setToRead(false);
}

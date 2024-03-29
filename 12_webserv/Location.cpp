/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Location.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 08:54:55 by apayen            #+#    #+#             */
/*   Updated: 2024/03/25 13:23:22 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Location.hpp"

//////////////////////////////
// Constructors and Destructor
Location::Location(void) : _get(true), _post(false), _del(false), _cgi(false), _autoindex(false)
{
	this->_index = std::pair<bool, std::string>(false, "");
	this->_dirpost = std::pair<bool, std::string>(false, "");
	this->_ret = std::pair<bool, std::string>(false, "");
	this->_alias = std::pair<bool, std::string>(false, "");
}

Location::Location(std::string path, bool get, bool post, bool del, bool cgi, bool autoindex, \
	std::pair<bool, std::string> index, std::pair<bool, std::string> dirpost, \
	std::pair<bool, std::string> ret, std::pair<bool, std::string> alias) \
	: _path(path), _get(get), _post(post), _del(del), _cgi(cgi), _autoindex(autoindex), \
	_index(index), _dirpost(dirpost), _ret(ret), _alias(alias) { }

Location::Location(Location const &rhs)
{
	this->_path = rhs._path;
	this->_get = rhs._get;
	this->_post = rhs._post;
	this->_del = rhs._del;
	this->_cgi = rhs._cgi;
	this->_autoindex = rhs._autoindex;
	this->_index = rhs._index;
	this->_dirpost = rhs._dirpost;
	this->_ret = rhs._ret;
	this->_alias = rhs._alias;
}

Location::~Location(void) { }

//////////////////////////////
// Overloads
Location	&Location::operator=(Location const &rhs)
{
	if (this != &rhs)
	{
		this->_path = rhs._path;
		this->_get = rhs._get;
		this->_post = rhs._post;
		this->_del = rhs._del;
		this->_cgi = rhs._cgi;
		this->_autoindex = rhs._autoindex;
		this->_index = rhs._index;
		this->_dirpost = rhs._dirpost;
		this->_ret = rhs._ret;
		this->_alias = rhs._alias;
	}
	return (*this);
}

//////////////////////////////
// Getters
bool	Location::allowMethod(std::string method, bool &get, bool &post, bool &del) const
{
	get = this->_get;
	post = this->_post;
	del = this->_del;
	if (method == "GET")
		return (get);
	else if (method == "POST")
		return (post);
	else if (method == "DELETE")
		return (del);
	return (false);
}

bool	Location::allowCgi(void) const
{ return (this->_cgi); }

bool	Location::allowAutoindex(void) const
{ return (this->_autoindex); }

std::string	Location::getPath(void) const
{ return (this->_path); }

std::pair<bool, std::string>	Location::getIndex(void) const
{ return (this->_index); }

std::pair<bool, std::string>	Location::getDirPost(void) const
{ return (this->_dirpost); }

std::pair<bool, std::string>	Location::getReturn(void) const
{ return (this->_ret); }

std::pair<bool, std::string>	Location::getAlias(void) const
{ return (this->_alias); }

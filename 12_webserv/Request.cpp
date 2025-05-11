/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 08:54:06 by apayen            #+#    #+#             */
/*   Updated: 2024/03/26 08:53:07 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Request.hpp"
#include "Client.hpp"

//////////////////////////////
// Constructors and Destructor
Request::Request(Client *cl) : _client(cl), _inparse(true), _inprocess(false), _inreadcgi(false), \
	_inerror(false), _inbuild(false), _inwrite(false), _fdfile(-1), _contentlength(0), \
	_maxcontentlength(-1), _multi(false), _postsuccess(false), _iscgi(false), _cgi(NULL), \
	_get(true), _post(true), _del(true), _autoindex(false), _redirected(0) { }

Request::Request(Client *cl, Request *rhs) : _client(cl), _serv(rhs->_serv), _inparse(rhs->_inparse), \
	_inprocess(rhs->_inprocess), _inreadcgi(rhs->_inreadcgi), _inerror(rhs->_inerror), _inbuild(rhs->_inbuild), \
	_inwrite(rhs->_inwrite), _request(rhs->_request), _header(rhs->_header), _body(rhs->_body), \
	_bodyresponse(rhs->_bodyresponse), _response(rhs->_response), _status(rhs->_status), \
	_name(rhs->_name), _method(rhs->_method), _filename(rhs->_filename), _filepath(rhs->_filepath), \
	_fdfile(rhs->_fdfile), _stat(rhs->_stat), _contentlength(rhs->_contentlength), \
	_maxcontentlength(rhs->_maxcontentlength), _multi(rhs->_multi), _boundary(rhs->_boundary), \
	_files(rhs->_files), _postsuccess(rhs->_postsuccess), _iscgi(rhs->_iscgi), _cgi(rhs->_cgi), \
	_cookie(rhs->_cookie), _get(rhs->_get), _post(rhs->_post), _del(rhs->_del), _dir(rhs->_dir), \
	_autoindex(rhs->_autoindex), _redirect(rhs->_redirect), _redirected(rhs->_redirected) { }

Request::~Request(void)
{
	if (this->_fdfile != -1)
		close (this->_fdfile);
}

//////////////////////////////
// Functions
void	Request::delCGI(void)
{
	if (this->_cgi)
		delete this->_cgi;
	this->_cgi = NULL;
}

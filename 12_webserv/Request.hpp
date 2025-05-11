/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madaguen <madaguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 08:54:12 by apayen            #+#    #+#             */
/*   Updated: 2024/03/26 13:46:32 by madaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REQUEST_HPP
#define REQUEST_HPP

# include <ctime>			// functions time
# include <string>			// string
# include <vector>			// vector
# include <cstdlib>			// atoi
# include <utility>			// pair
# include <iostream>		// cout
# include <algorithm>		// STL
							// stat
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/socket.h>	// recv

# include "Manager.hpp"
# include "Server.hpp"
# include "Cgi.hpp"

class Request
{
	public:
	// Constructors and Destructor
		Request(Client *cl);
		Request(Client *cl, Request *rhs);
		~Request(void);
	// Functions
		int															reader(void);
		int															writer(void);
		void														delCGI(void);

	private:
	// Attributes
		int															_errno;
		Client														*_client;
		Server														_serv;
		// States
		bool														_inparse;
		bool														_inprocess;
		bool														_inreadcgi;
		bool														_inerror;
		bool														_inbuild;
		bool														_inwrite;
		// Request
		std::vector<char>											_request;
		std::vector<char>											_header;
		std::vector<char>											_body;
		std::vector<char>											_bodyresponse;
		std::vector<char>											_response;
		// Parse
		std::string													_status;
		std::string													_name;
		std::string													_method;
		std::string													_filename;
		std::string													_filepath;
		int															_fdfile;
		struct stat 												_stat;
		int															_contentlength;
		int															_maxcontentlength;
		bool														_multi;
		std::string													_boundary;
		std::vector<std::pair<std::string, std::vector<char> > >	_files;
		bool														_postsuccess;
		bool														_iscgi;
		Cgi															*_cgi;
		std::string													_cookie;
		// Location
		bool														_get;
		bool														_post;
		bool														_del;
		std::string													_dir;
		bool														_autoindex;
		std::string													_redirect;
		int															_redirected;
	// Functions
		// Parsing
		std::string													parse(void);
		void														fillHeader(std::vector<char>::iterator pos, int bytes);
		void														fillBody(std::vector<char>::iterator pos, int bytes);
		void														parseMultiEncoded(void);
		bool														searchServ(void);
		std::string													checkLocation(void);
		int															simulateRedirect(std::string path);
		// States
		void														parsing(void);
		int															processing(void);
		void														processCGI(void);
		int															writing(void);
		// Methods
		std::string													openf(void);
		std::string													create(void);
		std::string													multipost(void);
		void														createFilesMultipost(void);
		std::string													get(void);
		std::string													del(void);
		std::string													post(void);
		std::string													error(void);
		void														generateError(void);
		// Response
		void														buildResponse(void);
		void														generateSuccess(void);

		std::string													getMethods(void);
		std::string													getTime(std::time_t time);
		std::string													getMime(void);
};

void		*ft_memset(void *s, int c, size_t n);
std::string	itoa(int nbi);
int			autoindex(const char *directory_name, std::string root, std::string &res);
void		printvector(std::vector<char> v, int minus);

#endif

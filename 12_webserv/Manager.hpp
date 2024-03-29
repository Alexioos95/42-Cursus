/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Manager.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:33:30 by apayen            #+#    #+#             */
/*   Updated: 2024/01/10 09:07:27 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGER_HPP
# define MANAGER_HPP

# include <map>				// map
# include <ctime>			// functions time
# include <cerrno>			// errno
# include <vector>			// vector
# include <fcntl.h>			// fcntl
# include <fstream>			// fstream
# include <string.h>		// strerror
# include <signal.h>		// signal
# include <dirent.h>		// opendir
# include <iostream>		// cout/cerr
# include <exception>		// exceptions
# include <sys/stat.h>		// stat
# include <arpa/inet.h>		// functions HostTONetwork
# include <sys/socket.h>	// sockets
# include <netinet/in.h>	// struct sockaddr_in
							// select
# include <unistd.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/select.h>

# include "Parsing.hpp"

extern bool g_sigint;

class Server;
class Client;

class Manager
{
	public:
	// Constructors and Destructor
		Manager(void);
		~Manager(void);
	// Exceptions
		class SigintException : public std::exception { };
	// Getters
		Server						getServ(std::string name, int port);
	// Functions
		void						defaultconfig(void);
		void						parse(char *config);
		void						run(void);
		void						shutdown(bool delcgi);

	private:
	// Functions
		void						manageFDSets(void);
		void						managePorts(void);
		void						acceptClient(int fdsock, int port);
		void						manageClients(void);
		void						manageTimeout(void);
	// Attributes
		struct timeval				_timeout;
		time_t						_timer;
		std::map<int, int>			_sockets;
		std::vector<Server>			_servs;
		std::vector<Client>			_clients;
		fd_set						_rset;
		fd_set						_wset;
		fd_set						_errset;
};

void			sig_handler(int sig);
void			*ft_memset(void *s, int c, size_t n);
std::string		asciiart(void);

#endif

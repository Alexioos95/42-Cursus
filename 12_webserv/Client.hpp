/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:41:38 by apayen            #+#    #+#             */
/*   Updated: 2024/03/25 09:48:23 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP

# include <ctime>			// functions time
# include <cerrno>			// errno
# include <iostream>		// cout

# include "Manager.hpp"
# include "Request.hpp"

class Client
{
	public:
	// Constructors and Destructor
		Client(Manager *main, int fd, int port);
		Client(Client const &rhs);
		~Client(void);
	// Overloads
		Client				&operator=(Client &rhs);
	// Setters
		void				setKeepAlive(bool state);
		void				setToRead(bool state);
	// Getters
		// Info
		Manager				*getManager(void);
		int					getFD(void) const;
		int					getPort(void) const;
		time_t				getTimer(void) const;
		// State
		bool				toRead(void) const;
		bool				keepAlive(void) const;
	// Functions
		void				deleteCGI(void);
		void				clear(void);
		void				actualizeTime(void);
		int					readRequest(void);
		int					writeResponse(void);

	private:
	// Attributes
		Manager				*_manager;
		Request				*_request;
		int					_fd;
		int					_port;
		time_t				_timer;
		bool				_toread;
		bool				_keepalive;
};

#endif

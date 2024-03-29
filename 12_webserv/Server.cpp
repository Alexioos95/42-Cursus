/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:38:00 by apayen            #+#    #+#             */
/*   Updated: 2024/03/27 09:55:44 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

//////////////////////////////
// Constructors and Destructor
Server::Server(void) { }

Server::Server(std::string name, std::string root, std::vector<int> ports, \
	std::map<std::string, std::string> errors, std::vector<Location> locations, \
	int bodymax, std::map<int, int> &m) : _name(name), _root(root), _errors(errors), \
	_locations(locations), _bodymax(bodymax)
{
	size_t						i;
	size_t						err;
	std::vector<int>::iterator	it;

	i = 0;
	err = 0;
	it = ports.begin();
	while (it != ports.end())
	{
		if (this->bindPort(m, (*it)))
			this->_ports.push_back((*it));
		else
			err++;
		it++;
	}
	if (err == ports.size())
	{
		std::cerr << "[!] Server " << name << " couldn't be created\n" << std::endl;
		throw (CreationException());
	}
	std::cout << "[+] Succesfully created server " << name << "\n";
	std::cout << "[*] Listening on port";
	if (this->_ports.size() > 1)
		std::cout << "s";
	std::cout << " ";
	while (i < this->_ports.size())
	{
		std::cout << this->_ports[i];
		if (i != this->_ports.size() - 1)
			std::cout << ", ";
		i++;
	}
	std::cout << "\n" << std::endl;;
}

Server::Server(Server const &rhs)
{
	this->_name = rhs._name;
	this->_root = rhs._root;
	this->_ports = rhs._ports;
	this->_errors = rhs._errors;
	this->_locations = rhs._locations;
	this->_bodymax = rhs._bodymax;
}

Server::~Server(void) { }

//////////////////////////////
// Overloads
Server	&Server::operator=(Server const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_root = rhs._root;
		this->_ports = rhs._ports;
		this->_errors = rhs._errors;
		this->_locations = rhs._locations;
		this->_bodymax = rhs._bodymax;
	}
	return (*this);
}

//////////////////////////////
// Getters
std::string	Server::getName(void) const
{ return (this->_name); }

std::string	Server::getRoot(void) const
{ return (this->_root); }

std::vector<int>	&Server::getPorts(void)
{ return (this->_ports); }

std::map<std::string, std::string>	Server::getErrors(void) const
{ return (this->_errors); }

Location	Server::getLocation(std::string path) const
{
	std::vector<Location>::const_iterator	it;

	while (path != "/")
	{
		it = this->_locations.begin();
		while (it != this->_locations.end())
		{
			if (path == (*it).getPath())
				return ((*it));
			if (*(path.end() - 1) == '/')
			{
				if (path.substr(0, path.length() - 1) == (*it).getPath())
					return ((*it));
			}
			it++;
		}
		if (path.length() >= 1 && *(path.end() - 1) == '/')
			path.erase(path.end() - 1);
		path.resize(path.find_last_of('/') + 1);
	}
	it = this->_locations.begin();
	while (it != this->_locations.end())
	{
		if (path == (*it).getPath())
			return ((*it));
		it++;
	}
	return (Location());
}

int	Server::getBodymax(void) const
{ return (this->_bodymax); }

//////////////////////////////
// Functions
bool	Server::bindPort(std::map<int, int> &m, int port)
{
	std::map<int, int>::iterator	it;
	int								fdsock;
	struct sockaddr_in				ssock;

	it = m.begin();
	while (it != m.end())
	{
		if ((*it).first == port)
			return (true);
		it++;
	}
	fdsock = socket(AF_INET, SOCK_STREAM, 0);
	if (fdsock == -1)
	{
		std::cerr << "[!] Failed creating socket for port " << port << " for " << this->_name;
		std::cerr << ": " << strerror(errno) << std::endl;
		errno = 0;
		return (false);
	}
	ft_memset(ssock.sin_zero, 0, sizeof(ssock.sin_zero));
	ssock.sin_family = AF_INET;
	ssock.sin_addr.s_addr = htonl(INADDR_ANY);
	ssock.sin_port = htons(port);
	if (bind(fdsock, reinterpret_cast<struct sockaddr *>(&ssock), sizeof(ssock)) == -1)
	{
		std::cerr << "[!] Failed binding socket to port " << port << " for " << this->_name << ": " << strerror(errno) << std::endl;
		close(fdsock);
		errno = 0;
		return (false);
	}
	if (listen(fdsock, SOMAXCONN) == -1)
	{
		std::cerr << "[!] Failed to listen on port " << port << " for " << this->_name;
		std::cerr << ": " << strerror(errno) << std::endl;
		close(fdsock);
		errno = 0;
		return (false);
	}
	m.insert(std::pair<int, int>(port, fdsock));
	return (true);
}

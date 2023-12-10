/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:06:11 by apayen            #+#    #+#             */
/*   Updated: 2023/12/02 07:58:26 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// ** Constructors and Destructor ** //
BitcoinExchange::BitcoinExchange(void) { }

BitcoinExchange::BitcoinExchange(BitcoinExchange const &rhs) { *this = rhs; }

BitcoinExchange::~BitcoinExchange(void)
{
	if (this->_infile.is_open())
		this->_infile.close();
	if (this->_outfile.is_open())
		this->_outfile.close();
}

// ** Overload ** //
BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	static_cast<void>(rhs);
	this->_line = rhs._line;
	this->_map = rhs._map;
	this->_it = rhs._it;
	if (this->_infile.is_open())
		this->_infile.close();
	if (this->_outfile.is_open())
		this->_outfile.close();
	return (*this);
}

// ** Exceptions ** //
const char	*BitcoinExchange::NotCSVException::what(void) const throw()
{ return ("Error: one of the database is not a .csv file"); }

const char	*BitcoinExchange::CantOpenException::what(void) const throw()
{ return ("Error: Failed to open one of the databases"); }

const char	*BitcoinExchange::InvalidFormatException::what(void) const throw()
{ return ("Error: Invalid format for the databases"); }

// ** Functions ** //
void	BitcoinExchange::parsing(std::string a1, std::string a2)
{
	float	dpair;

	// Check that the files are in .csv format.
	if (a1.find(".csv", a1.length() - 4) == std::string::npos	\
		|| a2.find(".csv", a2.length() - 4) == std::string::npos)
	{
		throw (NotCSVException());
		return ;
	}
	// Open them
	this->_infile.open(a1.c_str(), std::ios_base::in);
	if (this->_infile.fail())
	{
		throw (CantOpenException());
		return ;
	}
	this->_outfile.open(a2.c_str(), std::ios_base::in);
	if (this->_outfile.fail())
	if (this->_infile.fail())
	{
		this->_infile.close();
		throw (CantOpenException());
		return ;
	}
	// Fill map container
	while (std::getline(this->_infile, this->_line))
	{
		if (this->_line.find('|', 0) != 11 || this->_line[10] != ' ' || this->_line[12] != ' ')
			continue ;
		const std::string	key(this->_line.substr(0, 10));
		std::string	pair(this->_line.substr(13, this->_line.length() - 12));
		dpair = std::strtod(pair.c_str(), NULL);
		this->_map.insert(std::pair<std::string, float>(key, dpair));
	}
	// Check format line
	std::getline(this->_outfile, this->_line);
	if (this->_line != "date | value")
	{
		this->_infile.close();
		this->_outfile.close();
		throw (InvalidFormatException());
		return ;
	}
}

int	BitcoinExchange::run(std::string a1, std::string a2)
{
	int		i;
	int		j;
	int		k;
	int		dot;
	float	val;
	int		toll;
	float	d;

	// Parse the arguments, and fill the container
	try
	{
		this->parsing(a1, a2);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	// Loop of getline
	while (std::getline(this->_outfile, this->_line))
	{
		i = 0;
		j = 5;
		k = 8;
		d = 0;
		dot = -1;
		val = 0;
		toll = 0;
		// Verify format
		if (this->_line.empty())
			continue ;
		if (this->_line.find('|', 0) != 11 || this->_line[10] != ' ' || this->_line[12] != ' ')
		{
			std::cout << "Error: Invalid format" << std::endl;
			continue ;
		}
		// Separe date and value
		std::string	date(this->_line.substr(0, 10));
		std::string	value(this->_line.substr(13, this->_line.length() - 12));
		// Verify conformity of date
		if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		{
			std::cout << "Error: Invalid format date" << std::endl;
			continue ;
		}
		while (i < 4 && std::isdigit(date[i]))
			i++;
		while (j < 7 && std::isdigit(date[j]))
			j++;
		while (k < 8 && std::isdigit(date[k]))
			k++;
		if (i != 4 || j != 7 || k != 8)
		{
			std::cout << "Error: Unexpected character in date" << std::endl;
			continue ;
		}
		if (std::atoi(&date.c_str()[5]) > 12 || std::atoi(&date.c_str()[5]) > 31)
		{
			std::cout << "Error: Invalid date" << std::endl;
			continue ;
		}
		// Verify conformity of value
		if (value.find('.') != std::string::npos)
			dot = value.find('.');
		if (dot == static_cast<int>(value.length() - 1))
		{
			std::cout << "Error: No value after the dot" << std::endl;
			continue ;
		}
		i = 0;
		if (value[0] == '-')
		{
			std::cout << "Error: Negatif value" << std::endl;
			continue ;
		}
		while ((i < static_cast<int>(value.length()) && std::isdigit(value[i])) \
			|| (dot != -1 && i == dot))
			i++;
		if (i != static_cast<int>(value.length()))
		{
			std::cout << "Error: Unexpected character in value" << std::endl;
			continue ;
		}
		if (dot == -1)
		{
			val = std::atoi(value.c_str());
			toll = std::atoll(value.c_str());
			if (val != toll || val > 1000 || val == -1 || toll == -1)
			{
				std::cout << "Error: Value too large" << std::endl;
				continue ;
			}
		}
		else
		{
			val = atof(value.c_str());
			if (val > 1000 || val == INFINITY)
			{
				std::cout << "Error: Value too large" << std::endl;
				continue ;
			}
		}
		// Print Value
		if (this->_map.find(date) != this->_map.end())
			d = this->_map.find(date)->second;
		else
		{
			this->_it = this->_map.lower_bound(date);
			this->_it--;
			d = this->_it->second;
		}
		if (d * val == INFINITY)
			std::cout << "Error: Result too large to be printable" << std::endl;
		else
			std::cout << date << " => " << value << " = " << d * val << std::endl; // Scientist
			// std::cout << date << " => " << value << " = " << std::fixed << std::showpoint << std::setprecision(2) << d * val << std::endl; // Lose
	}
	this->_infile.close();
	this->_outfile.close();
	return (0);
}

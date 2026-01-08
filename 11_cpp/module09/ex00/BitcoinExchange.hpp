/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:05:19 by apayen            #+#    #+#             */
/*   Updated: 2023/12/02 07:51:45 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <exception>
# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <fstream>
# include <sstream>
# include <cmath>
# include <map>

class BitcoinExchange
{
	public:
	// ** Constructors and Destructor ** //
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &rhs);
		~BitcoinExchange(void);
	// ** Overload ** /
		BitcoinExchange		&operator=(BitcoinExchange const &rhs);
	// ** Exceptions ** //
		class NotCSVException : public std::exception
			{ public: const char	*what(void) const throw(); };
		class CantOpenException : public std::exception
			{ public: const char	*what(void) const throw(); };
		class InvalidFormatException : public std::exception
			{ public: const char	*what(void) const throw(); };
	// ** Functions ** //
		int		run(std::string a1, std::string a2);

	private:
	// ** Functions ** //
		void	parsing(std::string a1, std::string a2);
	// ** Attributes ** //
		std::string								_line;
		std::map<std::string, float>			_map;
		std::map<std::string, float>::iterator	_it;
		std::fstream							_infile;
		std::fstream							_outfile;
};

#endif

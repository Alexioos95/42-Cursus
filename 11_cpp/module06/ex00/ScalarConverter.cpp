/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:00:13 by apayen            #+#    #+#             */
/*   Updated: 2023/11/29 10:30:23 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// constructors and destructor
ScalarConverter::ScalarConverter(void)
{
	std::cout << "Default constructor of ScalarConverter called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &rhs)
{
	std::cout << "Copy constructor of ScalarConverter called" << std::endl;
	(void)rhs;
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "Destructor of ScalarConverter called" << std::endl;
}

// overload
ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &rhs)
{
	std::cout << "Copy assignement operator of ScalarConverter called" << std::endl;
	(void)rhs;
	return (*this);
}

// function
bool	parsing(std::string lit)
{
	long unsigned int	i;
	int					dot;

	i = 0;
	dot = 0;
	std::string sp[] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	if (lit.empty())
	{
		std::cout << "The parameter is empty" << std::endl;
		return (false);
	}
	if (lit.length() == 1)
		return (true);
	while (i < 6)
	{
		if (lit == sp[i])
			return (true);
		i++;
	}
	i = 0;
	if (lit[0] == '+' || lit[0] == '-')
		i++;
	while (i < lit.length())
	{
		if (lit[i] == '.')
		{
			if (dot == 1 || i == 0 || i == lit.length() - 1)
			{
				std::cout << "The parameter is invalid" << std::endl;
				return (false);
			}
			dot++;
		}
		else if ((!isdigit(lit[i]) && lit[i] != 'f') \
			|| (lit[i] == 'f' && i != lit.length() - 1))
		{
			std::cout << "The parameter is invalid" << std::endl;
			return (false);
		}
		i++;
	}
	return (true);
}

void	ScalarConverter::convert(std::string lit)
{
	long unsigned int	i;
	size_t				predot;
	std::string sp[] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	std::string			toc;
	std::string 		ctmp;
	int					toi;
	long long int		tolli;
	bool				toiimp;
	float				tof;
	double				tod;


	i = 0;
	toiimp = false;
	if (parsing(lit) == false)
		return ;
	predot = lit.find('.');
	i = 0;
	// CHAR INPUT
	if (lit.length() == 1 && !isdigit(lit[0]))
	{
		std::cout << "char: " << "'" << lit[0] << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(lit[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(lit[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(lit[0]) << ".0" << std::endl;
		return ;
	}
	// CHAR & INT
	while (i < 6 && lit != sp[i])
		i++;
	if (i != 6)
	{
		toc = "impossible";
		toiimp = true;
	}
	else
	{
		toi = atoi(lit.c_str());
		tolli = atoll(lit.c_str());
		if ((predot != std::string::npos && predot > 3) || toi < 0 || toi > 127)
			toc = "impossible";
		else if (!isprint(toi))
			toc = "Non displayable";
		else
		{
			ctmp.push_back(static_cast<char>(toi));
			toc = "'" + ctmp + "'";
		}
		if (toi != tolli)
			toiimp = true;
	}
	// FLOAT & DOUBLE
	if (lit[lit.length() - 1] == 'f')
	{
		tof = strtof(lit.c_str(), NULL);
		tod = static_cast<double>(tof);
	}
	else
	{
		tod = strtod(lit.c_str(), NULL);
		tof = static_cast<float>(tod);
	}
	// PRINT
	std::cout << "char: " << toc << std::endl;
	if (toiimp == true)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << toi << std::endl;
	if (i == 6 && (tof == INFINITY || tod == INFINITY))
	{
		if (tof == INFINITY)
			std::cout << "float: impossible" << std::endl;
		else
			std::cout << "float: " << tof << ".0f" << std::endl;
		if (tod == INFINITY)
			std::cout << "double: impossible" << std::endl;
		else
			std::cout << "double: " << tod << ".0" << std::endl;
	}
	else if ((toiimp == false && tof - toi == 0) || (toiimp == true && i == 6))
	{
		std::cout << "float: " << tof << ".0f" << std::endl;
		std::cout << "double: " << tod << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << tof << "f" << std::endl;
		std::cout << "double: " << tod << std::endl;
	}
}

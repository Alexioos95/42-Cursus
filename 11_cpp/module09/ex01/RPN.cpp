/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 22:22:26 by root              #+#    #+#             */
/*   Updated: 2023/12/02 14:16:32 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// ** Constructors and Destructor ** //
RPN::RPN(void) { }

RPN::RPN(RPN const &rhs) { *this = rhs; }

RPN::~RPN(void) { }

// ** Overload ** //
RPN	&RPN::operator=(RPN const &rhs)
{
	this->stack = rhs.stack;
	return (*this);
}

// ** Exceptions ** //
const char	*RPN::EmptyArgException::what(void) const throw()
{ return ("Error: Argument is empty"); }

const char	*RPN::UnexpectedCharException::what(void) const throw()
{ return ("Error: Argument contains an unexpected character"); }

const char	*RPN::InvalidFormatException::what(void) const throw()
{ return ("Error: Invalid format of argument.\nExample: \"<number between 0 and 9, or expression +-*/> <number between 0 and 9, or expression +-*/> ...\""); }

// ** Functions ** //
void	RPN::parsing(std::string arg)
{
	std::size_t	i;

	i = 0;
	if (arg.empty() || arg.find_first_of("0123456789", 0) == std::string::npos)
	{
		throw (EmptyArgException());
		return ;
	}
	if (arg.find_first_not_of("0123456789+-*/ ", 0) != std::string::npos)
	{
		throw (UnexpectedCharException());
		return ;
	}
	if (arg[arg.length() - 1] == ' ')
	{
		throw (InvalidFormatException());
		return ;
	}
	while (i < arg.length())
	{
		if (i != arg.length() - 1 \
			&& arg.find("0123456789+-*/", i) != i && arg.find(' ', i) != i + 1)
		{
			throw (InvalidFormatException());
			return ;
		}
		i = i + 2;
	}
}

int	RPN::run(std::string arg)
{
	int				i;
	int				len;
	char			c;
	long long int	res;
	long long int	lhs;
	long long int	rhs;

	i = 0;
	len = arg.length();
	// Parsing
	try
	{
		this->parsing(arg);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	// Loop of calculation
	while (i < len)
	{
		c = arg[i];
		if (c == ' ')
		{
			i++;
			continue ;
		}
		// If number
		if (c >= '0' && c <= '9')
			this->stack.push(std::atoi(&arg[i]));
		// Else, if operator
		else
		{
			if (this->stack.size() < 2)
			{
				std::cout << "Error: Not enough number in stack to do this operation.";
				std::cout << " Calculation was aborted" << std::endl;
				return (1);
			}
			lhs = this->stack.top();
			this->stack.pop();
			rhs = this->stack.top();
			this->stack.pop();
			if (c == '+')
				res = rhs + lhs;
			if (c == '-')
				res = rhs - lhs;
			if (c == '*')
				res = rhs * lhs;
			if (c == '/')
			{
				if (lhs == 0)
				{
					std::cout << "Error: Tried to divide by 0. Calculation was aborted" << std::endl;
					return (1);
				}
				res = rhs / lhs;
			}
			if (res > INT_MAX || res < INT_MIN)
			{
					std::cout << "Error: Result of operation overflow an int. Calculation was aborted" << std::endl;
					return (1);
			}
			this->stack.push(res);
		}
		i++;
	}
	// Print
	std::cout << "Result: " << this->stack.top() << std::endl;
	this->stack.pop();
	if (this->stack.size() > 0)
	{
		std::cout << "Notice: More numbers were left in stack: ";
		while (this->stack.size() > 0)
		{
			std::cout << this->stack.top();
			if (this->stack.size() > 1)
				std::cout << ", ";
			this->stack.pop();
		}
		std::cout << std::endl;
	}
	return (0);
}

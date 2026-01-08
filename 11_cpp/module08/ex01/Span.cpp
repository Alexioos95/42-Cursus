/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:25:53 by apayen            #+#    #+#             */
/*   Updated: 2023/11/21 13:59:09 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// constructors and destructor
Span::Span(void)
{
	std::cout << "Default constructor of Span called" << std::endl;
	this->_v.reserve(0);
}

Span::Span(unsigned int N)
{
	std::cout << "Unsigned int constructor of Span called" << std::endl;
	this->_v.reserve(N);
}

Span::Span(Span const &rhs)
{
	std::cout << "Copy constructor of Span called" << std::endl;
	*this = rhs;
}

Span::~Span(void)
{
	std::cout << "Destructor of Span called" << std::endl;
}

// overload
Span	&Span::operator=(Span const &rhs)
{
	std::cout << "Copy assignement of Span called" << std::endl;
	this->_v = rhs._v;
	return (*this);
}

// exceptions
const char	*Span::MaxSizeException::what(void) const throw()
{
	return ("The Span is already full");
}

// exceptions
const char	*Span::NotEnoughException::what(void) const throw()
{
	return ("The Span doesn't contain enough number to do this");
}

// functions
void	Span::addNumber(unsigned int nb)
{
	if (this->_v.size() == this->_v.capacity())
	{
		throw (MaxSizeException());
		return ;
	}
	this->_v.push_back(nb);
	std::cout << "Succesfully added " << nb << " to Span" << std::endl;
	if (this->_v.size() == this->_v.capacity())
		std::cout << "The Span is now full" << std::endl;
}

void	Span::addRange(std::vector<unsigned int> newv, std::vector<unsigned int>::iterator begin, std::vector<unsigned int>::iterator end)
{
	static_cast<void>(newv);
	while (begin != end)
	{
		this->addNumber(*begin);
		begin++;
	}
}

unsigned int	Span::shortestSpan(void)
{
	unsigned int						res;
	std::vector<unsigned int>			newv(this->_v);
	std::vector<unsigned int>::iterator	it;

	if (this->_v.size() <= 1)
	{
		throw (NotEnoughException());
		return (0);
	}
	std::sort(newv.begin(), newv.end());
	it = newv.begin();
	res = *(it + 1) - *it;
	it++;
	while (it + 1 != newv.end())
	{
		if (*it == *(it + 1))
			return (0);
		else if (*(it + 1) - *it < res)
			res = *(it + 1) - *it;
		it++;
	}
	return (res);
}

unsigned int	Span::longestSpan(void)
{
	unsigned int	res;

	if (this->_v.size() <= 1)
	{
		throw (NotEnoughException());
		return (0);
	}
	res = *std::max_element(this->_v.begin(), this->_v.end()) - *std::min_element(this->_v.begin(), this->_v.end());
	return (res);
}

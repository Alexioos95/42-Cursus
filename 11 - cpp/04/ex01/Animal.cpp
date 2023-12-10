/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:40:40 by apayen            #+#    #+#             */
/*   Updated: 2023/11/03 12:16:08 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// constructors and destructor
Animal::Animal(void) : _type("")
{
	std::cout << "Default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "String constructor called" << std::endl;
}

Animal::Animal(Animal const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Animal::~Animal(void)
{
	std::cout << "Destructor called" << std::endl;
}

// overload
Animal	&Animal::operator=(Animal const &rhs)
{
	std::cout << "Copy assignement operator called" << std::endl;
	this->_type = rhs.getType();
	return (*this);
}

// setterd and getters
std::string	Animal::getType(void) const
{
	return (this->_type);
}

// functions
void	Animal::makeSound(void) const
{
	;
}

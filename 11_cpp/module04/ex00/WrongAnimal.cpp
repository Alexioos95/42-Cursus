/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:40:40 by apayen            #+#    #+#             */
/*   Updated: 2023/11/03 12:21:46 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// constructors and destructor
WrongAnimal::WrongAnimal(void) : _type("")
{
	std::cout << "Default constructor of WrongAnimal called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "String constructor of WrongAnimal called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	std::cout << "Copy constructor of WrongAnimal called" << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Destructor of WrongAnimal called" << std::endl;
}

// overload
WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &rhs)
{
	std::cout << "Copy assignement operator of WrongAnimal called" << std::endl;
	this->_type = rhs.getType();
	return (*this);
}

// setterd and getters
std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

// functions
void	WrongAnimal::makeSound(void) const
{
	std::cout << "There is no sound, this is wrong!" << std::endl;
}

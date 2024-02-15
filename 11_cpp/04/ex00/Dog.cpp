/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:40:40 by apayen            #+#    #+#             */
/*   Updated: 2023/11/03 12:53:05 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// constructors and destructor
Dog::Dog(void) : Animal()
{
	std::cout << "Default constructor of Dog called" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(Dog const &src)
{
	std::cout << "Copy constructor of Dog called" << std::endl;
	*this = src;
}

Dog::~Dog(void)
{
	std::cout << "Destructor of Dog called" << std::endl;
}

// overload
Dog	&Dog::operator=(Dog const &rhs)
{
	std::cout << "Copy assignement operator of Dog called" << std::endl;
	this->_type = rhs.getType();
	return (*this);
}

// functions
void	Dog::makeSound(void) const
{
	std::cout << "Wouaf!" << std::endl;
}

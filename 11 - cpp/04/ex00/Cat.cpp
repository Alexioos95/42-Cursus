/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:40:40 by apayen            #+#    #+#             */
/*   Updated: 2023/11/03 12:53:01 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// constructors and destructor
Cat::Cat(void) : Animal()
{
	std::cout << "Default constructor of Cat called" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(Cat const &src)
{
	std::cout << "Copy constructor of Cat called" << std::endl;
	*this = src;
}

Cat::~Cat(void)
{
	std::cout << "Destructor of Cat called" << std::endl;
}

// overload
Cat	&Cat::operator=(Cat const &rhs)
{
	std::cout << "Copy assignement operator of Cat called" << std::endl;
	this->_type = rhs.getType();
	return (*this);
}

// functions
void	Cat::makeSound(void) const
{
	std::cout << "Miaou!" << std::endl;
}

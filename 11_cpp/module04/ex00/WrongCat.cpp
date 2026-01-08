/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:40:40 by apayen            #+#    #+#             */
/*   Updated: 2023/11/03 12:19:57 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// constructors and destructor
WrongCat::WrongCat(void) : WrongAnimal()
{
	std::cout << "Default constructor of WrongCat called" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const &src)
{
	std::cout << "Copy constructor of WrongCat called" << std::endl;
	*this = src;
}

WrongCat::~WrongCat(void)
{
	std::cout << "Destructor of WrongCat called" << std::endl;
}

// overload
WrongCat	&WrongCat::operator=(WrongCat const &rhs)
{
	std::cout << "Copy assignement operator of WrongCat called" << std::endl;
	this->_type = rhs.getType();
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Miaou!" << std::endl;
}

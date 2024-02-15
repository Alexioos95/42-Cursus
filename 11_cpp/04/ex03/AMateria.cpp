/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:37:24 by apayen            #+#    #+#             */
/*   Updated: 2023/11/07 11:06:38 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// consturctor and destructor
AMateria::AMateria(void) : _type("")
{
	std::cout << "Default constructor of AMateria called" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << "String constructor of AMateria called" << std::endl;
}

AMateria::AMateria(AMateria const &rhs)
{
	std::cout << "Copy constructor of AMateria called" << std::endl;
	*this = rhs;
}

AMateria::~AMateria(void)
{
	std::cout << "Destructor of AMateria called" << std::endl;
}

// overload
AMateria	&AMateria::operator=(AMateria const &rhs)
{
	std::cout << "Copy assignement operator of AMateria called" << std::endl;
	this->_type = rhs.getType();
	return (*this);
}

// setters and getters
void	AMateria::setType(std::string type)
{
	this->_type = type;
}

std::string const	&AMateria::getType(void) const
{
	return (this->_type);
}

// functions
void 		AMateria::use(ICharacter& target)
{
	(void)target;
}

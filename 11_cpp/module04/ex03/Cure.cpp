/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:55:57 by apayen            #+#    #+#             */
/*   Updated: 2023/11/09 11:41:57 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// constructor and destructor
Cure::Cure(void) : AMateria("cure")
{
	std::cout << "Default constructor of Cure called" << std::endl;
}

Cure::Cure(Cure const &rhs)
{
	std::cout << "Copy constructor of Cure called" << std::endl;
	*this = rhs;
}

Cure::~Cure(void)
{
	std::cout << "Destructor of Cure called" << std::endl;
}

// overload
Cure	&Cure::operator=(Cure const &rhs)
{
	std::cout << "Copy assignement operator of Cure called" << std::endl;
	(void)rhs;
	return (*this);
}

// functions
AMateria*	Cure::clone(void) const
{
	AMateria	*ret;

	ret = new Cure;
	return (ret);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:55:57 by apayen            #+#    #+#             */
/*   Updated: 2023/11/07 11:32:00 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// constructor and destructor
Ice::Ice(void) : AMateria("ice")
{
	std::cout << "Default constructor of Ice called" << std::endl;
}

Ice::Ice(Ice const &rhs)
{
	std::cout << "Copy constructor of Ice called" << std::endl;
	*this = rhs;
}

Ice::~Ice(void)
{
	std::cout << "Destructor of Ice called" << std::endl;
}

// overload
Ice	&Ice::operator=(Ice const &rhs)
{
	std::cout << "Copy assignement operator of Ice called" << std::endl;
	(void)rhs;
	return (*this);
}

// functions
AMateria*	Ice::clone(void) const
{
	AMateria	*ret;

	ret = new Ice;
	return (ret);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an Ice bolt at " << target.getName() << " *" << std::endl;
}

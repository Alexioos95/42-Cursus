/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:36:47 by marvin            #+#    #+#             */
/*   Updated: 2023/11/03 11:56:27 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// constructors and destructor
FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "Default constructor of FragTrap called" << std::endl;
	this->setName("");
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "String constructor of FragTrap called" << std::endl;
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
}

FragTrap::FragTrap(FragTrap &src) : ClapTrap(src)
{
	std::cout << "Copy constructor of FragTrap called" << std::endl;
	*this = src;
}

FragTrap::~FragTrap(void)
{
	std::cout << "Destructor of FragTrap called" << std::endl;
}

// overload
FragTrap	&FragTrap::operator=(FragTrap &rhs)
{
	std::cout << "Copy assignement operator of FragTrap called" << std::endl;
	this->setName(rhs.getName());
	this->_hp = rhs._hp;
	this->_ep = rhs._ep;
	this->_ad = rhs._ad;
	return (*this);
}

// functions
void	FragTrap::highFivesGuys(void)
{
	std::cout << this->getName() << " asks everyone to do a high fives with him!" << std::endl;
}

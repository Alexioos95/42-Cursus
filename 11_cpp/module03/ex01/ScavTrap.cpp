/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:36:47 by marvin            #+#    #+#             */
/*   Updated: 2023/11/03 11:55:52 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// constructors and destructor
ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "Default constructor of ScavTrap called" << std::endl;
	this->setName("");
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "String constructor of ScavTrap called" << std::endl;
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
}

ScavTrap::ScavTrap(ScavTrap &src) : ClapTrap(src)
{
	std::cout << "Copy constructor of ScavTrap called" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Destructor of ScavTrap called" << std::endl;
}

// overload
ScavTrap	&ScavTrap::operator=(ScavTrap &rhs)
{
	std::cout << "Copy assignement operator of ScavTrap called" << std::endl;
	this->setName(rhs.getName());
	this->_hp = rhs._hp;
	this->_ep = rhs._ep;
	this->_ad = rhs._ad;
	return (*this);
}

// functions
void	ScavTrap::attack(const std::string& target)
{
	if (this->getHP() > 0)
	{
		if (this->getEP() > 0)
		{
			this->setEP(this->getEP() - 1);
			std::cout << "ScavTrap " << this->getName() << " attacks " << target;
			std::cout << ", causing " << this->getAD() << " points of damage!" << std::endl;
		}
		else
		{
			std::cout << "ScavTrap " << this->getName() << " wants to attack " << target << "...";
			std::cout << " but it does not have any Energy point!" << std::endl;
		}
	}
}

void	ScavTrap::guardGate(void)
{
	std::cout << "Warning: ScavTrap " << this->getName() << " is now in Gatekeeping mode!" << std::endl;
}

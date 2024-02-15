/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:46:12 by marvin            #+#    #+#             */
/*   Updated: 2023/10/28 15:46:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// constructors and destructor
ClapTrap::ClapTrap(void) :_hp(10), _ep(10), _ad(0), _name("")
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _hp(10), _ep(10), _ad(0), _name(name)
{
	std::cout << "String constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}

// overload
ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs)
{
	std::cout << "Copy assignement operator called" << std::endl;
	this->_name = rhs._name;
	this->_hp = rhs._hp;
	this->_ep = rhs._ep;
	this->_ad = rhs._ad;
	return (*this);
}

// setters and getters
void	ClapTrap::setName(std::string name)
{
	this->_name = name;
}

void	ClapTrap::setHP(int hp)
{
	this->_hp = hp;
}

void	ClapTrap::setEP(int ep)
{
	this->_ep = ep;
}

void	ClapTrap::setAD(int ad)
{
	this->_ad = ad;
}

std::string	ClapTrap::getName(void) const
{
	return (this->_name);
}

int	ClapTrap::getHP(void) const
{
	return (this->_hp);
}

int	ClapTrap::getEP(void) const
{
	return (this->_ep);
}

int	ClapTrap::getAD(void) const
{
	return (this->_ad);
}

// functions
void	ClapTrap::attack(const std::string& target)
{
	if (this->getHP() > 0)
	{
		if (this->getEP() > 0)
		{
			this->setEP(this->getEP() - 1);
			std::cout << "ClapTrap " << this->getName() << " attacks " << target;
			std::cout << ", causing " << this->getAD() << " points of damage!" << std::endl;
		}
		else
		{
			std::cout << "ClapTrap " << this->getName() << " wants to attack " << target << "...";
			std::cout << " but it does not have any Energy point!" << std::endl;
		}
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getHP() <= 0)
		std::cout << "ClapTrap " << this->getName() << " got attacked... but he's already dead!" << std::endl;
	else
	{
		this->setHP(this->getHP() - (int)amount);
		std::cout << "ClapTrap " << this->getName() << " got attacked, and lost " << amount << " health points!" << std::endl;
		if (this->getHP() <= 0)
			std::cout << "ClapTrap " << this->getName() << " died" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getHP() > 0)
	{
		if (this->getEP() > 0)
		{
			this->setHP(this->getHP() + (int)amount);
			this->setEP(this->getEP() - 1);
			std::cout << "ClapTrap " << this->getName() << " repaired itself, and received ";
			std::cout << amount << " health points!" << std::endl;
		}
		else
		{
			std::cout << "ClapTrap " << this->getName() << " wants to repair itself...";
			std::cout << " but it does not have any Energy point!" << std::endl;
		}
	}
}

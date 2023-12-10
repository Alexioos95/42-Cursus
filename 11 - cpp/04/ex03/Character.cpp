/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:55:57 by apayen            #+#    #+#             */
/*   Updated: 2023/11/08 12:49:43 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

// constructor and destructor
Character::Character(void) : ICharacter(), _name("")
{
	std::cout << "Default constructor of Character called" << std::endl;
	this->_tab[0] = NULL;
	this->_tab[1] = NULL;
	this->_tab[2] = NULL;
	this->_tab[3] = NULL;
}

Character::Character(std::string name) : ICharacter(), _name(name)
{
	std::cout << "String constructor of Character called" << std::endl;
	this->_tab[0] = NULL;
	this->_tab[1] = NULL;
	this->_tab[2] = NULL;
	this->_tab[3] = NULL;
}

Character::Character(Character const &rhs)
{
	std::cout << "Copy constructor of Character called" << std::endl;
	*this = rhs;
}

Character::~Character(void)
{
	int	i;

	std::cout << "Destructor of Character called" << std::endl;
	i = 0;
	while (i < 4)
	{
		if (this->_tab[i] != NULL)
			delete this->_tab[i];
		i++;
	}
}

// overload
Character	&Character::operator=(Character const &rhs)
{
	int	i;

	std::cout << "Copy assignement operator of Character called" << std::endl;
	this->_name = rhs._name;
	i = 0;
	while (i < 4)
	{
		if (this->_tab[i] != NULL)
		{
			delete this->_tab[i];
			this->_tab[i] = NULL;
		}
		if (rhs._tab[i] != NULL)
			this->_tab[i] = rhs._tab[i]->clone();
		i++;
	}
	return (*this);
}

// setters and getters
void	Character::setName(std::string name)
{
	this->_name = name;
}

std::string const & Character::getName() const
{
	return (this->_name);
}

// functions
void	Character::equip(AMateria* m)
{
	int	i;

	i = 0;
	if (m == NULL)
	{
		std::cout << "You can not equip a 'NULL' Materia..." << std::endl;
		return ;
	}
	while (i < 4 && this->_tab[i] != NULL)
		i++;
	if (i == 4)
	{
		std::cout << "Inventory is full! The Materia has not been equiped..." << std::endl;
		return ;
	}
	_tab[i] = m;
	std::cout << "A Materia has been equiped!" << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || this->_tab[idx] == NULL)
	{
		std::cout << "The index indicated does not correspond to any Materia..." << std::endl;
		return ;
	}
	this->_tab[idx] = NULL;
	std::cout << "A Materia has been unequiped" << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	std::string name;

	if (idx < 0 || idx > 3 || this->_tab[idx] == NULL)
	{
		std::cout << "The index indicated does not correspond to any Materia..." << std::endl;
		return ;
	}
	this->_tab[idx]->use(target);
}

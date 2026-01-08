/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:57:54 by apayen            #+#    #+#             */
/*   Updated: 2023/11/09 11:41:35 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// constructors and destructor
MateriaSource::MateriaSource(void) : IMateriaSource()
{
	std::cout << "Default constructor of MateriaSource called" << std::endl;
	this->_tab[0] = NULL;
	this->_tab[1] = NULL;
	this->_tab[2] = NULL;
	this->_tab[3] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &rhs)
{
	std::cout << "Copy constructor of MateriaSource called" << std::endl;
	*this = rhs;
}

MateriaSource::~MateriaSource(void)
{
	int	i;

	std::cout << "Destructor of MateriaSource called" << std::endl;
	i = 0;
	while (i < 4)
	{
		if (this->_tab[i] != NULL)
			delete this->_tab[i];
		i++;
	}
}

// overload
MateriaSource	&MateriaSource::operator=(MateriaSource const &rhs)
{
	int	i;

	std::cout << "Copy assignement operator of MateriaSource called" << std::endl;
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

// functions
void	MateriaSource::learnMateria(AMateria* m)
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
		std::cout << "MateriaSource's capacity is already full! The Materia has not been learned..." << std::endl;
		return ;
	}
	this->_tab[i] = m->clone();
	std::cout << "Successfully learned a new Materia!" << std::endl;
	if (i == 3)
		std::cout << "MateriaSource's capacity is now full. You can no longer learn new Materia." << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int	i;
	AMateria	*ret;

	i = 0;
	while (i < 4 && this->_tab[i] != NULL && type.compare(this->_tab[i]->getType()) != 0)
		i++;
	if (i == 4 || this->_tab[i] == NULL)
	{
		std::cout << "Failed creating Materia. No such type was learned..." << std::endl;
		return (0);
	}
	ret = this->_tab[i]->clone();
	return (ret);
}

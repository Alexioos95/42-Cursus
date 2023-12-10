/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:40:40 by apayen            #+#    #+#             */
/*   Updated: 2023/11/03 14:11:02 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// constructors and destructor
Cat::Cat(void) : Animal()
{
	std::cout << "Default constructor of Cat called" << std::endl;
	this->_type = "Cat";
	this->_ideas = new Brain();
}

Cat::Cat(Cat const &src)
{
	std::cout << "Copy constructor of Cat called" << std::endl;
	*this = src;
}

Cat::~Cat(void)
{
	std::cout << "Destructor of Cat called" << std::endl;
	delete this->_ideas;
}

// overload
Cat	&Cat::operator=(Cat const &rhs)
{
	std::cout << "Copy assignement operator of Cat called" << std::endl;
	int	i;

	i = 0;
	while (i < 100)
	{
		this->_ideas->setIdea(i, rhs._ideas->getIdea(i));
		i++;
	}
	this->_type = rhs.getType();
	return (*this);
}

// setters and getters
void	Cat::setIdea(int i, std::string idea)
{
	if (i >= 0 && i <= 99)
		this->_ideas->setIdea(i, idea);
}

std::string	Cat::getIdea(int i)
{
	if (i >= 0 && i <= 99)
		return (this->_ideas->getIdea(i));
	else
		return ("");
}

Brain	Cat::getBrain(void)
{
	return (*this->_ideas);
}

// functions
void	Cat::makeSound(void) const
{
	std::cout << "Miaou!" << std::endl;
}

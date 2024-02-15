/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:40:40 by apayen            #+#    #+#             */
/*   Updated: 2023/11/03 14:10:54 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// constructors and destructor
Dog::Dog(void) : Animal()
{
	std::cout << "Default constructor of Dog called" << std::endl;
	this->_type = "Dog";
	this->_ideas = new Brain();
}

Dog::Dog(Dog const &src)
{
	std::cout << "Copy constructor of Dog called" << std::endl;
	*this = src;
}

Dog::~Dog(void)
{
	std::cout << "Destructor of Dog called" << std::endl;
	delete this->_ideas;
}

// overload
Dog	&Dog::operator=(Dog const &rhs)
{
	std::cout << "Copy assignement operator of Dog called" << std::endl;
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
void	Dog::setIdea(int i, std::string idea)
{
	if (i >= 0 && i <= 99)
		this->_ideas->setIdea(i, idea);
}

std::string	Dog::getIdea(int i)
{
	if (i >= 0 && i <= 99)
		return (this->_ideas->getIdea(i));
	else
		return ("");
}

Brain	Dog::getBrain(void)
{
	return (*this->_ideas);
}

// functions
void	Dog::makeSound(void) const
{
	std::cout << "Wouaf!" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:40:40 by apayen            #+#    #+#             */
/*   Updated: 2023/11/03 12:16:08 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// constructors and destructor
Brain::Brain(void)
{
	std::cout << "Default constructor of Brain called" << std::endl;
}

Brain::Brain(Brain const &src)
{
	std::cout << "Copy constructor of Brain called" << std::endl;
	*this = src;
}

Brain::~Brain(void)
{
	std::cout << "Destructor of Brain called" << std::endl;
}

// overload
Brain	&Brain::operator=(Brain const &rhs)
{
	std::cout << "Copy assignement operator of Brain called" << std::endl;

	int	i;
	i = 0;
	while (i < 100)
	{
		this->_ideas[i] = rhs._ideas[i];
		i++;
	}
	return (*this);
}

// setters and getters
void	Brain::setIdea(int i, std::string idea)
{
	if (i >= 0 && i <= 99)
		this->_ideas[i] = idea;
}

std::string	Brain::getIdea(int i)
{
	if (i >= 0 && i <= 99)
		return (this->_ideas[i]);
	else
		return ("");
}

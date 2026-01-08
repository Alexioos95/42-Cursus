/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:12:18 by apayen            #+#    #+#             */
/*   Updated: 2023/11/16 14:40:48 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// constructors and destructor
Intern::Intern(void)
{
	std::cout << "Default constructor of Intern called" << std::endl;
}

Intern::Intern(Intern const &rhs)
{
	std::cout << "Copy constructor of Intern called" << std::endl;
	*this = rhs;
}

Intern::~Intern(void)
{
	std::cout << "Destructor of Intern called" << std::endl;
}

// overload
Intern	&Intern::operator=(Intern const &rhs)
{
	std::cout << "Copy assignement operator of Intern called" << std::endl;
	(void)rhs;
	return (*this);
}

// functions
AForm	*Intern::makeForm(std::string name, std::string target)
{
	try
	{
		AForm		*shrub = new ShrubberyCreationForm(target);
		AForm		*robot = new RobotomyRequestForm(target);
		AForm		*pres = new PresidentialPardonForm(target);

		AForm		*tabform[] = {shrub, robot, pres};
		std::string	tabstr[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
		int			i;
		int			j;

		i = 0;
		j = 0;
		while (i < 3 && name.compare(tabstr[i]) != 0)
			i++;
		while (j < 3)
		{
			if (i != j)
				delete tabform[j];
			j++;
		}
		if (i == 3)
		{
			std::cout << "S-Sorry, I don't know this form..." << std::endl;
			return (NULL);
		}
		return (tabform[i]);
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: couldn't allocate memory with new: " << e.what() << std::endl;
		return (NULL);
	}
}

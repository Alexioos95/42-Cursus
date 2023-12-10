/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 08:57:00 by apayen            #+#    #+#             */
/*   Updated: 2023/11/16 11:00:21 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// constructors and destructor
RobotomyRequestForm::RobotomyRequestForm(void) : AForm("ShrubberyCreation", 72, 45)
{
	std::cout << "Default constructor of RobotomyRequestForm called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("ShrubberyCreation", 72, 45)
{
	std::cout << "String constructor of RobotomyRequestForm called" << std::endl;
	this->setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &rhs)
{
	std::cout << "Copy constructor of RobotomyRequestForm called" << std::endl;
	*this = rhs;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "Destructor of RobotomyRequestForm called" << std::endl;
}

// overload
RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	std::cout << "Copy assignement operator of RobotomyRequestForm called" << std::endl;
	this->setTarget(rhs.getTarget());
	return (*this);
}

// functions
void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	int	i;

	if (this->canExecute(executor) == true)
	{
		i = rand() % 100 + 1;
		if (i % 2 == 0)
			std::cout << this->getTarget() << " has been succesfully robotomized!" << std::endl;
		else
			std::cout << "The robotomization of " << this->getTarget() << " failed..." << std::endl;

	}
}

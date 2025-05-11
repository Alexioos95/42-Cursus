/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 08:57:00 by apayen            #+#    #+#             */
/*   Updated: 2023/11/16 11:08:52 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// constructors and destructor
PresidentialPardonForm::PresidentialPardonForm(void) : AForm("ShrubberyCreation", 25, 5)
{
	std::cout << "Default constructor of PresidentialPardonForm called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("ShrubberyCreation", 25, 5)
{
	std::cout << "String constructor of PresidentialPardonForm called" << std::endl;
	this->setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &rhs)
{
	std::cout << "Copy constructor of PresidentialPardonForm called" << std::endl;
	*this = rhs;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "Destructor of PresidentialPardonForm called" << std::endl;
}

// overload
PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	std::cout << "Copy assignement operator of PresidentialPardonForm called" << std::endl;
	this->setTarget(rhs.getTarget());
	return (*this);
}

// functions
void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->canExecute(executor) == true)
	{
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:39:11 by apayen            #+#    #+#             */
/*   Updated: 2023/11/16 14:42:38 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// constructors and destructor
AForm::AForm(void) : _name(""), _signed(false), _signgrade(150), _execgrade(75), _target("")
{
	std::cout << "Default constructor of AForm called" << std::endl;
}

AForm::AForm(std::string const name, int const signgrade, int const execgrade) : \
	_name(name), _signed(false), _signgrade(signgrade), _execgrade(execgrade), _target("")
{
	std::cout << "Informations constructor of AForm called" << std::endl;
	if (signgrade < 1 || execgrade < 1)
		throw (AForm::GradeTooHighException());
	else if (signgrade > 150 || execgrade > 150)
		throw (AForm::GradeTooLowException());
}

AForm::AForm(AForm const &rhs) : _name(rhs.getName()), _signed(rhs.getSigned()), \
	_signgrade(rhs.getSignGrade()), _execgrade(rhs.getExecGrade()), _target(rhs.getTarget())
{
	std::cout << "Copy constructor of AForm called" << std::endl;
}

AForm::~AForm(void)
{
	std::cout << "Destructor of AForm called" << std::endl;
}

// overload
AForm	&AForm::operator=(AForm const &rhs)
{
	std::cout << "Copy assignement operator of AForm called" << std::endl;
	this->_signed = rhs.getSigned();
	return (*this);
}

// setters and getters
std::string	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getSigned(void) const
{
	return (this->_signed);
}

int		AForm::getSignGrade(void) const
{
	return (this->_signgrade);
}

int		AForm::getExecGrade(void) const
{
	return (this->_execgrade);
}

void	AForm::setTarget(std::string target)
{
	this->_target = target;
}

std::string	AForm::getTarget(void) const
{
	return (this->_target);
}

// functions
void	AForm::beSigned(Bureaucrat &b)
{
	if (this->getSigned() == false)
	{
		if (b.getGrade() <= this->getSignGrade())
			this->_signed = true;
		else
			throw (AForm::GradeTooLowException());
	}
}

// void	AForm::execute(Bureaucrat const & executor) const
// {
// 	(void)executor;
// }

bool	AForm::canExecute(Bureaucrat const & executor) const
{
	if (this->_signed == false)
	{
		throw (AForm::NotSignedException());
		return (false);
	}
	if (this->_execgrade < executor.getGrade())
	{
		throw (GradeTooLowException());
		return (false);
	}
	return (true);
}

// exceptions
const char	*AForm::GradeTooHighException::what(void) const throw()
{
	return ("Error: The grade is too high!");
}

const char	*AForm::GradeTooLowException::what(void) const throw()
{
	return ("Error: The grade is too low!");
}

const char	*AForm::NotSignedException::what(void) const throw()
{
	return ("Error: The form is not signed!");
}

// general
std::ostream	&operator<<(std::ostream &o, AForm &rhs)
{
	o << "Informations of AForm " << rhs.getName() << ":" << std::endl;
	o << "- Is signed: " << rhs.getSigned() << std::endl;
	o << "- Grade required to sign: " << rhs.getSignGrade() << std::endl;
	o << "- Grade required to execute: " << rhs.getExecGrade() << std::endl;
	o << "- Target: " << rhs.getTarget();
	return (o);
}

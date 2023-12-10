/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:39:11 by apayen            #+#    #+#             */
/*   Updated: 2023/11/16 14:42:58 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// constructors and destructor
Form::Form(void) : _name(""), _signed(false), _signgrade(150), _execgrade(75)
{
	std::cout << "Default constructor of Form called" << std::endl;
}

Form::Form(std::string const name, int const signgrade, int const execgrade) : \
	_name(name), _signed(false), _signgrade(signgrade), _execgrade(execgrade)
{
	std::cout << "Informations constructor of Form called" << std::endl;
	if (signgrade < 1 || execgrade < 1)
		throw Form::GradeTooHighException();
	else if (signgrade > 150 || execgrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &rhs) : _name(rhs.getName()), _signed(rhs.getSigned()), \
	_signgrade(rhs.getSignGrade()), _execgrade(rhs.getExecGrade())
{
	std::cout << "Copy constructor of Form called" << std::endl;
}

Form::~Form(void)
{
	std::cout << "Destructor of Form called" << std::endl;
}

// overload
Form	&Form::operator=(Form const &rhs)
{
	std::cout << "Copy assignement operator of Form called" << std::endl;
	this->_signed = rhs.getSigned();
	return (*this);
}

// setters and getters
std::string	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getSigned(void) const
{
	return (this->_signed);
}

int		Form::getSignGrade(void) const
{
	return (this->_signgrade);
}

int		Form::getExecGrade(void) const
{
	return (this->_execgrade);
}

// functions
void	Form::beSigned(Bureaucrat &b)
{
	if (this->getSigned() == false)
	{
		if (b.getGrade() <= this->getSignGrade())
			this->_signed = true;
		else
			throw Form::GradeTooLowException();
	}
}

// exceptions
const char	*Form::GradeTooHighException::what(void) const throw()
{
	return ("Error: The grade is too high!");
}

const char	*Form::GradeTooLowException::what(void) const throw()
{
	return ("Error: The grade is too low!");
}

// general
std::ostream	&operator<<(std::ostream &o, Form &rhs)
{
	o << "Informations of Form " << rhs.getName() << ":" << std::endl;
	o << "- Is signed: " << rhs.getSigned() << std::endl;
	o << "- Grade required to sign: " << rhs.getSignGrade() << std::endl;
	o << "- Grade required to execute: " << rhs.getExecGrade();
	return (o);
}

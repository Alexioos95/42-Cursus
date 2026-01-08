/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:12:18 by apayen            #+#    #+#             */
/*   Updated: 2023/11/16 14:43:11 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// constructors and destructor
Bureaucrat::Bureaucrat(void) : _name("NoName"), _grade(150)
{
	std::cout << "Default constructor of Bureaucrat called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade)
{
	std::cout << "String and int constructor of Bureaucrat called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &rhs)
{
	std::cout << "Copy constructor of Bureaucrat called" << std::endl;
	*this = rhs;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor of Bureaucrat called" << std::endl;
}

// overload
Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	std::cout << "Copy assignement operator of Bureaucrat called" << std::endl;
	this->_grade = rhs._grade;
	return (*this);
}

// setters and getters
std::string const	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

// functions
void	Bureaucrat::incGrade(void)
{
	this->_grade--;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::decGrade(void)
{
	this->_grade++;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

// exceptions
const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Error: The grade is too high!");
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Error: The grade is too low!");
}

// general
std::ostream	&operator<<(std::ostream &o, Bureaucrat &rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (o);
}

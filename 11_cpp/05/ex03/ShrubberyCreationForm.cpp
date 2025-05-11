/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 08:57:00 by apayen            #+#    #+#             */
/*   Updated: 2023/11/16 10:39:55 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// constructors and destructor
ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreation", 145, 137)
{
	std::cout << "Default constructor of ShrubberyCreationForm called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreation", 145, 137)
{
	std::cout << "String constructor of ShrubberyCreationForm called" << std::endl;
	this->setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &rhs)
{
	std::cout << "Copy constructor of ShrubberyCreationForm called" << std::endl;
	*this = rhs;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "Destructor of ShrubberyCreationForm called" << std::endl;
}

// overload
ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	std::cout << "Copy assignement operator of ShrubberyCreationForm called" << std::endl;
	this->setTarget(rhs.getTarget());
	return (*this);
}

// functions
void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::string			tmp;
	char const			*res;
	std::fstream 		out;

	if (this->canExecute(executor) == true)
	{
		tmp = this->getTarget() + "_shrubbery";
		res = tmp.c_str();
		try
		{
			out.open(res, std::fstream::out);
		}
		catch (std::exception &e)
		{
			std::cout << "Error: " << tmp << ": " << e.what() << std::endl;
			return ;
		}
		out << "                      v .   ._, |_  .," << "                      v .   ._, |_  .," << "                      v .   ._, |_  .," << std::endl;
		out << "   `-._\\/  .  \\ /    |/_            " << "   `-._\\/  .  \\ /    |/_            " << "   `-._\\/  .  \\ /    |/_            " << std::endl;
		out << "       \\  _\\, y | \\//              " << "       \\  _\\, y | \\//              " << "       \\  _\\, y | \\//              " << std::endl;
		out << " _\\_.___\\, \\/ -.\\||               " << " _\\_.___\\, \\/ -.\\||               " << " _\\_.___\\, \\/ -.\\||               " << std::endl;
		out << "   `7-,--.`._||  / / ,                " << "   `7-,--.`._||  / / ,                " << "   `7-,--.`._||  / / ,                " << std::endl;
		out << "   /'     `-. `./ / |/_.'             " << "   /'     `-. `./ / |/_.'             " << "   /'     `-. `./ / |/_.'             " << std::endl;
		out << "             |    |//                 " << "             |    |//                 " << "             |    |//                 " << std::endl;
		out << "             |_    /                  " << "             |_    /                  " << "             |_    /                  " << std::endl;
		out << "             |-   |                   " << "             |-   |                   " << "             |-   |                   " << std::endl;
		out << "             |   =|                   " << "             |   =|                   " << "             |   =|                   " << std::endl;
		out << "             |    |                   " << "             |    |                   " << "             |    |                   " << std::endl;
		out << "------------/ ,  . \\--------._       " << "------------/ ,  . \\--------._       " << "------------/ ,  . \\--------._       " << std::endl;
		out.close();
	}
}

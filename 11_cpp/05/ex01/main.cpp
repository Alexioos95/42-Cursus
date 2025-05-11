/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:11:06 by apayen            #+#    #+#             */
/*   Updated: 2023/11/15 16:06:43 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << "** Form's Constructor Exceptions Test **" << std::endl;
	std::cout << "* Test One *" << std::endl; // No problem
	try
	{
		Form f1("F1", 1, 150);
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "* Test Two *" << std::endl; // Too High
	try
	{
		Form f2("F2", 0, 150);
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "* Test Three *" << std::endl; // Too Low
	try
	{
		Form	f3("F3", 1, 151);
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "** Overload << Test **" << std::endl;
	Form	f4("F04", 15, 75);
	std::cout << f4 << std::endl;

	std::cout << "** beSigned() Test **" << std::endl;
	std::cout << "* Test One *" << std::endl; // No Problem
	Bureaucrat	b1("B01", 148);
	Form	f5("F05", 149, 1);
	std::cout << f5.getSigned() << std::endl;
	try
	{
		f5.beSigned(b1);
		std::cout << f5.getSigned() << std::endl;
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "* Test Two *" << std::endl; // Too low
	Bureaucrat	b2("B02", 150);
	Form	f6("F06", 149, 1);
	std::cout << f6.getSigned() << std::endl;
	try
	{
		f6.beSigned(b2);
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "** signForm() Test **" << std::endl;
	std::cout << "* Test One *" << std::endl; // Too Low
	Bureaucrat	b3("B03", 150);
	Form		f7("F07", 149, 1);
	std::cout << f7.getSigned() << std::endl;
	b3.signForm(f7);
	std::cout << "* Test Two *" << std::endl; // No Problem
	std::cout << f7.getSigned() << std::endl;
	b3.incGrade();
	b3.signForm(f7);
	std::cout << f7.getSigned() << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:11:06 by apayen            #+#    #+#             */
/*   Updated: 2023/11/15 13:15:55 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "** Test One**" << std::endl; // No problem
	try
	{
		Bureaucrat one("One", 1);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "** Test Two**" << std::endl; // Too High
	try
	{
		Bureaucrat two("Two", 0);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "** Test Three**" << std::endl; // No Problem
	try
	{
		Bureaucrat three("Three", 150);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "** Test Four**" << std::endl; // Too Low
	try
	{
		Bureaucrat four("Four", 151);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "** Test Five**" << std::endl; // Too High
	try
	{
		Bureaucrat five("Five", 1);
		five.incGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "** Test Six**" << std::endl; // Too Low
	try
	{
		Bureaucrat six("Six", 150);
		six.decGrade();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "** Test Overload**" << std::endl;
	Bureaucrat seven("Seven", 20);
	std::cout << seven << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:11:06 by apayen            #+#    #+#             */
/*   Updated: 2023/11/16 11:27:02 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	// std::cout << "** Abstract Class Test **" << std::endl;
	// AForm	a1; // Doesn't compile

	std::cout << "** ShrubberyCreation Test **" << std::endl;
	Bureaucrat				b1("B01", 138);
	ShrubberyCreationForm	s1("test_one");
	b1.executeForm(s1);
	b1.signForm(s1);
	b1.executeForm(s1);
	b1.incGrade();
	b1.executeForm(s1);
	std::cout << s1 << std::endl;
	std::cout << std::endl;

	std::cout << "** RobotomyRequest Test **" << std::endl;
	Bureaucrat				b2("B02", 46);
	RobotomyRequestForm		f2("you");
	b2.executeForm(f2);
	b2.signForm(f2);
	b2.executeForm(f2);
	b2.incGrade();
	b2.executeForm(f2);
	b2.executeForm(f2);
	b2.executeForm(f2);
	b2.executeForm(f2);
	std::cout << f2 << std::endl;
	std::cout << std::endl;

	std::cout << "** PresidentialPardon Test **" << std::endl;
	Bureaucrat				b3("B03", 6);
	PresidentialPardonForm	p3("Alexis");
	b3.executeForm(p3);
	b3.signForm(p3);
	b3.executeForm(p3);
	b3.incGrade();
	b3.executeForm(p3);
	std::cout << p3 << std::endl;
	std::cout << std::endl;
}

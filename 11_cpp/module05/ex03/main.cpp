/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:11:06 by apayen            #+#    #+#             */
/*   Updated: 2023/11/16 14:58:34 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	std::cout << "** Subject Test **" << std::endl;
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	delete rrf;
	std::cout << std::endl;

	std::cout << "** Intern Test **" << std::endl;
	Intern	i;
	AForm	*one;
	AForm	*two;
	AForm	*three;
	AForm	*four;

	one = i.makeForm("shrubbery creation", "dunno_one");
	std::cout << *one << std::endl;
	two = i.makeForm("robotomy request", "dunno_two");
	std::cout << *two << std::endl;
	three = i.makeForm("presidential pardon", "dunno_three");
	std::cout << *three << std::endl;
	four = i.makeForm("abracadabra", "dunno_four"); // Can't find

	delete one;
	delete two;
	delete three;
	delete four;
}

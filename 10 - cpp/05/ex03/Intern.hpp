/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:11:19 by apayen            #+#    #+#             */
/*   Updated: 2023/11/16 14:34:40 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		// constructors and destructor
		Intern(void);
		Intern(Intern const &rhs);
		~Intern(void);
		// overload
		Intern	&operator=(Intern const &rhs);
		// functions
		AForm	*makeForm(std::string name, std::string target);
};

typedef void (AForm::*f)(void);
#endif

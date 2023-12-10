/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:11:19 by apayen            #+#    #+#             */
/*   Updated: 2023/11/16 11:25:26 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class Form;
class Bureaucrat
{
	public:
		// constructors and destructor
		Bureaucrat(void);
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const &rhs);
		~Bureaucrat(void);
		// overload
		Bureaucrat	&operator=(Bureaucrat const &rhs);
		// setters and getters
		std::string const	getName(void) const;
		int					getGrade(void) const;
		// functions
		void				incGrade(void);
		void				decGrade(void);
		void				signForm(Form &f);
		// exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};

	private:
		std::string const	_name;
		int					_grade;
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat &rhs);

# include "Form.hpp"
#endif

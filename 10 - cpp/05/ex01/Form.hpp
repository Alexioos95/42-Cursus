/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:35:31 by apayen            #+#    #+#             */
/*   Updated: 2023/11/15 15:54:45 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Form
{
	public:
		// constructors and destructor
		Form(void);
		Form(std::string const name, int const signgrade, int const execgrade);
		Form(Form const &rhs);
		~Form(void);
		// overload
		Form		&operator=(Form const &rhs);
		// setters and getters
		std::string	getName(void) const;
		bool		getSigned(void) const;
		int			getSignGrade(void) const;
		int			getExecGrade(void) const;
		// function
		void		beSigned(Bureaucrat &b);
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
		bool				_signed;
		int const			_signgrade;
		int const			_execgrade;
};

std::ostream	&operator<<(std::ostream &o, Form &rhs);

#endif

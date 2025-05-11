/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:35:31 by apayen            #+#    #+#             */
/*   Updated: 2023/11/16 11:12:01 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class AForm
{
	public:
		// constructors and destructor
		AForm(void);
		AForm(std::string const name, int const signgrade, int const execgrade);
		AForm(AForm const &rhs);
		virtual ~AForm(void);
		// overload
		AForm		&operator=(AForm const &rhs);
		// setters and getters
		std::string		getName(void) const;
		bool			getSigned(void) const;
		int				getSignGrade(void) const;
		int				getExecGrade(void) const;
		void			setTarget(std::string target);
		std::string		getTarget(void) const;
		// function
		void			beSigned(Bureaucrat &b);
		virtual void	execute(Bureaucrat const &executor) const = 0;
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
		class NotSignedException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};

	protected:
		// functions
		bool			canExecute(Bureaucrat const &executor) const;

	private:
		std::string const	_name;
		bool				_signed;
		int const			_signgrade;
		int const			_execgrade;
		std::string			_target;
};

std::ostream	&operator<<(std::ostream &o, AForm &rhs);

#endif

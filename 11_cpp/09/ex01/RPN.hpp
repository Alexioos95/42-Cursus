/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 22:22:39 by root              #+#    #+#             */
/*   Updated: 2023/12/02 14:01:21 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <exception>
# include <iostream>
# include <cstdlib>
# include <climits>
# include <stack>

class RPN
{
	public:
	// ** Constructors and Destructor ** //
		RPN(void);
		RPN(RPN const &rhs);
		~RPN(void);
	// ** Overload ** //
		RPN	&operator=(RPN const &rhs);
	// ** Exceptions ** //
		class EmptyArgException : public std::exception
			{ public: const char	*what(void) const throw(); };
		class UnexpectedCharException : public std::exception
			{ public: const char	*what(void) const throw(); };
		class InvalidFormatException : public std::exception
			{ public: const char	*what(void) const throw(); };
	// ** Functions ** //
		int	run(std::string arg);

	private:
	// ** Functions ** //
		void	parsing(std::string arg);
	// ** Attributes **/
		std::stack<long long int>	stack;
};

#endif

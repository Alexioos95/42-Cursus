/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:26:02 by apayen            #+#    #+#             */
/*   Updated: 2023/11/21 13:52:01 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class Span
{
	public:
		// constructor and destructor
		Span(unsigned int N);
		Span(Span const &rhs);
		~Span(void);
		// overload
		Span			&operator=(Span const &rhs);
		// exceptions
		class MaxSizeException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
		class NotEnoughException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
		// function
		void			addNumber(unsigned int N);
		void			addRange(std::vector<unsigned int> newv, std::vector<unsigned int>::iterator begin, std::vector<unsigned int>::iterator end);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);

	private:
		// constructor
		Span(void);
		// attribute
		std::vector<unsigned int>	_v;
};

#endif

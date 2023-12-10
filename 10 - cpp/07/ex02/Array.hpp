/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:26:54 by apayen            #+#    #+#             */
/*   Updated: 2023/11/21 09:55:45 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>
# include <stdexcept>

template<typename T>
class Array
{
	public:
		// constructors and destructor
		Array(void);
		Array(unsigned int n);
		Array(Array const &rhs);
		~Array(void);
		// overload
		Array<T>	&operator=(Array const &rhs);
		T			&operator[](unsigned int i);
		// function
		size_t	size(void) const;

	private:
		T		*_array;
		size_t	_size;
};

#endif

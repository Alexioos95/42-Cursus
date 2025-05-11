/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:00:28 by apayen            #+#    #+#             */
/*   Updated: 2023/11/23 09:39:20 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdio>
# include <ctype.h>
# include <cstdlib>
# include <cmath>

class ScalarConverter
{
	public:
		// destructor
		~ScalarConverter(void);
		// function
		static void	convert(std::string lit);

	private:
		// constructors
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &rhs);
		// overload
		ScalarConverter	&operator=(ScalarConverter const &rhs);
		// function
};

bool	parsing(std::string lit);

#endif

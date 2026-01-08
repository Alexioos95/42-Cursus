/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:46:37 by marvin            #+#    #+#             */
/*   Updated: 2023/11/20 13:32:52 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		// constructors and destructor
		Fixed(void);
		Fixed(Fixed const &src);
		Fixed(int const nb);
		Fixed(float const nb);
		~Fixed(void);
		// overload
		Fixed	&operator=(Fixed const &rhs);
		// setters and getters
		void	setRawBits(int const raw);
		int		getRawBits(void) const;
		// functions
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					_rawbits;
		static const int	_bits = 8;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs);

#endif

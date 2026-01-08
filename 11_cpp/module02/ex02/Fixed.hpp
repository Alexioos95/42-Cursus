/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:46:37 by marvin            #+#    #+#             */
/*   Updated: 2023/10/27 10:46:37 by marvin           ###   ########.fr       */
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
		bool				operator>(Fixed const &rhs) const;
		bool				operator<(Fixed const &rhs) const;
		bool				operator>=(Fixed const &rhs) const;
		bool				operator<=(Fixed const &rhs) const;
		bool				operator==(Fixed const &rhs) const;
		bool				operator!=(Fixed const &rhs) const;
		Fixed				&operator=(Fixed const &rhs);
		Fixed				operator+(Fixed const &rhs);
		Fixed				operator-(Fixed const &rhs);
		Fixed				operator*(Fixed const &rhs);
		Fixed				operator/(Fixed const &rhs);
		Fixed				&operator++();
		Fixed				operator++(int);
		Fixed				&operator--();
		Fixed				operator--(int);
		// setters and getters
		void				setRawBits(int const raw);
		int					getRawBits(void) const;
		// functions
		float				toFloat(void) const;
		int					toInt(void) const;
		static Fixed		&min(Fixed &one, Fixed &two);
		static const Fixed 	&min(Fixed const &one, Fixed const &two);
		static Fixed 		&max(Fixed &one, Fixed &two);
		static const Fixed 	&max(Fixed const &one, Fixed const &two);

	private:
		int					_rawbits;
		static const int	_bits = 8;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs);

#endif

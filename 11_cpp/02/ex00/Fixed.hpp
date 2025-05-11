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

class Fixed
{
	public:
		// constructors and destructor
		Fixed(void);
		Fixed(Fixed const &src);
		~Fixed(void);
		// overload
		Fixed	&operator=(Fixed const &rhs);
		// setters and getters
		void	setRawBits(int const raw);
		int		getRawBits(void) const;

	private:
		int					_rawbits;
		static const int	_bits = 8;
};

#endif

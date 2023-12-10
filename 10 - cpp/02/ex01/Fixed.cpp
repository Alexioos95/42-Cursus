/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:48:20 by marvin            #+#    #+#             */
/*   Updated: 2023/10/27 10:48:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _rawbits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(int const nb) : _rawbits(nb)
{
	std::cout << "Int constructor called" << std::endl;
	this->_rawbits = (nb << this->_bits);
}

Fixed::Fixed(float const nb) : _rawbits(nb)
{
	std::cout << "Float constructor called" << std::endl;
	this->_rawbits = roundf(nb * (1 << this->_bits));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignement operator called" << std::endl;
	this->_rawbits = rhs.getRawBits();
	return (*this);
}

void	Fixed::setRawBits(int const raw)
{
	this->_rawbits = raw;
}

int	Fixed::getRawBits(void) const
{
	return(this->_rawbits);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_rawbits / (float)(1 << this->_bits));
}

int	Fixed::toInt(void) const
{
	return (this->_rawbits >> this->_bits);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return (o);
}

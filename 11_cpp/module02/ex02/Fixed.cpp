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

// constructors and destructor
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
	if (nb != nb || nb == INFINITY || nb == -INFINITY)
	{
		std::cout << "Error: Impossible to cast " << nb << " to int" << std::endl;
		this->_rawbits = 0;
		return ;
	}
	this->_rawbits = roundf(nb * (1 << this->_bits));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

// functions
void	Fixed::setRawBits(int const raw)
{
	this->_rawbits = raw;
}

int	Fixed::getRawBits(void) const
{
	return (this->_rawbits);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_rawbits / (float)(1 << this->_bits));
}

int	Fixed::toInt(void) const
{
	return (this->_rawbits >> this->_bits);
}

// overload
std::ostream	&operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return (o);
}

bool	Fixed::operator>(Fixed const &rhs) const
{
	if (this->_rawbits > rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<(Fixed const &rhs) const
{
	if (this->_rawbits < rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(Fixed const &rhs) const
{
	if (this->_rawbits >= rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(Fixed const &rhs) const
{
	if (this->_rawbits <= rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(Fixed const &rhs) const
{
	if (this->_rawbits == rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(Fixed const &rhs) const
{
	if (this->_rawbits != rhs.getRawBits())
		return (true);
	return (false);
}

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignement operator called" << std::endl;
	this->_rawbits = rhs.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(Fixed const &rhs)
{
	this->_rawbits = this->_rawbits + rhs.getRawBits();
	return (*this);
}

Fixed	Fixed::operator-(Fixed const &rhs)
{
	this->_rawbits = this->_rawbits - rhs.getRawBits();
	return (*this);
}

Fixed	Fixed::operator*(Fixed const &rhs)
{
	return (this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(Fixed const &rhs)
{
	return (this->toFloat() / rhs.toFloat());
}

Fixed	&Fixed::operator++()
{
	this->_rawbits++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	++*this;
	return (tmp);
}

Fixed	&Fixed::operator--()
{
	this->_rawbits--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	--*this;
	return (tmp);
}

Fixed	&Fixed::min(Fixed &one, Fixed &two)
{
	if (one.getRawBits() <= two.getRawBits())
		return (one);
	return (two);
}

const	Fixed	&Fixed::min(Fixed const &one, Fixed const &two)
{
	if (one.getRawBits() <= two.getRawBits())
		return (one);
	return (two);
}

Fixed	&Fixed::max(Fixed &one, Fixed &two)
{
	if (one.getRawBits() >= two.getRawBits())
		return (one);
	return (two);
}

const	Fixed	&Fixed::max(Fixed const &one, Fixed const &two)
{
	if (one.getRawBits() >= two.getRawBits())
		return (one);
	return (two);
}

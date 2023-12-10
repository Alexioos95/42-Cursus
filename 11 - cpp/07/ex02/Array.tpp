/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:39:35 by apayen            #+#    #+#             */
/*   Updated: 2023/11/24 13:55:46 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

// constructors and destructor
template<typename T>
Array<T>::Array(void) : _array(new T[0]), _size(0)
{
	std::cout << "Default constructor of Array called" << std::endl;
	this->_array[0] = 0;
}

template<typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{
	unsigned int	i;

	i = 0;
	std::cout << "Unsigned int constructor of Array called" << std::endl;
	while (i < n)
	{
		this->_array[i] = 0;
		i++;
	}
}

template<typename T>
Array<T>::Array(Array const &rhs)
{
	std::cout << "Copy constructor of Array called" << std::endl;
	*this = rhs;
}

template<typename T>
Array<T>::~Array(void)
{
	std::cout << "Destructor of Array called" << std::endl;
	delete [] this->_array;
}

// overload
template<typename T>
Array<T>	&Array<T>::operator=(Array const &rhs)
{
	unsigned int	i;

	i = 0;
	std::cout << "Copy assignement operator of Array called" << std::endl;
	if (this != &rhs)
	{
		delete [] this->_array;
		this->_size = rhs._size;
		this->_array = new T[this->_size];
		while (i < this->_size)
		{
			this->_array[i] = rhs._array[i];
			i++;
		}
	}
	return (*this);
}

template<typename T>
T	&Array<T>::operator[](unsigned int i)
{
	if (i >= this->_size)
		throw (std::out_of_range("Parameter is out of range"));
	return (this->_array[i]);
}

template<typename T>
size_t	Array<T>::size(void) const
{
	return (this->_size);
}

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:22:57 by apayen            #+#    #+#             */
/*   Updated: 2023/11/20 09:33:06 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// constructors and destructor
Serializer::Serializer(void)
{
	std::cout << "Default constructor of Serializer called" << std::endl;
}

Serializer::Serializer(Serializer const &rhs)
{
	std::cout << "Copy constructor of Serializer called" << std::endl;
	static_cast<void>(rhs);
}

Serializer::~Serializer(void)
{
	std::cout << "Destructor of Serializer called" << std::endl;
}

// overload
Serializer	&Serializer::operator=(Serializer const &rhs)
{
	std::cout << "Copy assignement of Serializer called" << std::endl;
	static_cast<void>(rhs);
	return (*this);
}

// functions
uintptr_t	Serializer::serialize(Data* ptr)
{
	uintptr_t	raw;

	raw = reinterpret_cast<uintptr_t>(ptr);
	return (raw);
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	Data	*ptr;

	ptr = reinterpret_cast<Data *>(raw);
	return (ptr);
}

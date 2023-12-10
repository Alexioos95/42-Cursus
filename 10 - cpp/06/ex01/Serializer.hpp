/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:11:56 by apayen            #+#    #+#             */
/*   Updated: 2023/11/29 10:26:45 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

struct Data
{
	int	i;
};

class Serializer
{
	public:
		// destructor
		~Serializer(void);
		// functions
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

	private:
		// constructors
		Serializer(void);
		Serializer(Serializer const &rhs);
		Serializer	&operator=(Serializer const &rhs);
};

#endif

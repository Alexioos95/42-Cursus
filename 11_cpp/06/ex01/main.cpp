/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:11:25 by apayen            #+#    #+#             */
/*   Updated: 2023/11/20 09:35:32 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data		d;
	uintptr_t	ui;
	Data		*nd;

	d.i = 42;
	std::cout << "d.i is originally equal to " << d.i << std::endl;

	std::cout << "Assigning a uintptr_t to result of serializing..." << std::endl;
	ui = Serializer::serialize(&d);

	std::cout << "Assigning a Data * to result of deserializing..." << std::endl;
	nd = Serializer::deserialize(ui);

	std::cout << "New data of i = " << nd->i << std::endl;
}

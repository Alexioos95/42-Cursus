/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:08:56 by apayen            #+#    #+#             */
/*   Updated: 2023/11/21 12:15:22 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

const char	*NoOccurence::what(void) const throw()
{
	return ("Couldn't find the occurence");
}

int	main(void)
{
	std::vector<int>			v;
	std::vector<int>::iterator	it;
	int							i;

	i = 1;
	while (i < 10000)
	{
		v.push_back(i);
		i = i * 10;
	}
	v.push_back(10);
	std::cout << "Created vector int with {1, 10, 100, 1000, 10000, 10}" << std::endl;
	try
	{
		std::cout << "Search 10" << std::endl;
		it = easyfind(v, 10);
		std::cout << "Got iterator to: " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "Search -1" << std::endl;
		it = easyfind(v, -1);
		std::cout << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

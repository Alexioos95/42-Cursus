/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:27:31 by apayen            #+#    #+#             */
/*   Updated: 2023/11/21 10:15:36 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.tpp"

int	main(void)
{
	std::cout << "** Char Test **" << std::endl;
	unsigned int	i1;
	int				c1;
	Array<char>		arr1(10);

	i1 = 0;
	c1 = 97;
	while (i1 < arr1.size())
	{
		arr1[i1] = c1;
		i1++;
		c1++;
	}
	i1 = 0;
	while (i1 < arr1.size())
	{
		std::cout << arr1[i1];
		if (i1 < arr1.size() - 1)
			std::cout << ", ";
		i1++;
	}
	std::cout << std::endl << std::endl;

	std::cout << "** Int Test **" << std::endl;
	unsigned int	i2;
	int				c2;
	Array<int>		arr2(20);

	i2 = 0;
	c2 = 97;
	while (i2 < arr2.size())
	{
		arr2[i2] = c2;
		i2++;
		c2++;
	}
	i2 = 0;
	while (i2 < arr2.size())
	{
		std::cout << arr2[i2];
		if (i2 < arr2.size() - 1)
			std::cout << ", ";
		i2++;
	}
	std::cout << std::endl << std::endl;

	std::cout << "** Exception Test **" << std::endl;
	unsigned int	i3;

	i3 = 50;
	try
	{
		i3 = arr2[i3];
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "** Copy Test **" << std::endl;
	std::cout << "Create arr3 with size of 1" << std::endl;
	Array<int>		arr3(1);
	arr3 = arr2;
	std::cout << "Copied arr2 into arr3" << std::endl;
	i3 = 0;
	while (i3 < arr2.size())
	{
		arr2[i3] = arr2[i3] - 96;
		i3++;
	}
	std::cout << "Modified arr2" << std::endl;
	std::cout << "New array:" << std::endl;
	i3 = 0;
	while (i3 < arr2.size())
	{
		std::cout << arr2[i3];
		if (i3 < arr2.size() - 1)
			std::cout << ", ";
		i3++;
	}
	std::cout << std::endl;
	i3 = 0;
	while (i3 < arr3.size())
	{
		std::cout << arr3[i3];
		if (i3 < arr3.size() - 1)
			std::cout << ", ";
		i3++;
	}
	std::cout << std::endl;
}

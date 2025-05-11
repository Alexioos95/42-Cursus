/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:36:35 by apayen            #+#    #+#             */
/*   Updated: 2023/11/20 16:34:04 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	int		tab[] = {117, 118, 119, 120, 121, 122};
	char	str[] = "abcdef";
	int		i;

	i = 0;
	std::cout << "Original tab: ";
	while (i < 6)
	{
		std::cout << tab[i];
		if (i < 5)
			std::cout << ", ";
		i++;
	}
	std::cout << std::endl << "Original str: " << str << std::endl;
	iter<int>(tab, 6, toupper);
	iter<char>(str, 6, toupper);
	i = 0;
	std::cout << "New tab: ";
	while (i < 6)
	{
		std::cout << tab[i];
		if (i < 5)
			std::cout << ", ";
		i++;
	}
	std::cout << std::endl << "New str: " << str << std::endl;
	iter<int>(tab, 6, tolower);
	iter<char>(str, 6, tolower);
	i = 0;
	std::cout << "Yet New tab: ";
	while (i < 6)
	{
		std::cout << tab[i];
		if (i < 5)
			std::cout << ", ";
		i++;
	}
	std::cout << std::endl << "Yet New str: " << str << std::endl;
}

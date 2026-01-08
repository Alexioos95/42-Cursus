/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 08:32:12 by marvin            #+#    #+#             */
/*   Updated: 2023/10/26 12:37:20 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int argc, char **argv)
{
	Zombie				*horde;
	std::stringstream	str;
	long long int		n;
	long long int		i;

	if (argc != 3)
	{
		std::cout << "Usage: ./test <nb_zombie> <name>" << std::endl;
		return (1);
	}
	str << argv[1];
	str >> n;
	if (n < 0 || n > 6000000)
	{
		std::cout << "Invalid argument" << std::endl;
		return (1);
	}
	horde = zombieHorde((int)n, argv[2]);
	if (horde == NULL)
		return (1);
	std::cout << n << " zombies created" << std::endl;
	i = 0;
	while (i < n)
	{
		horde[i].announce();
		i++;
	}
	std::cout << i << " zombies announced themselves" << std::endl;
	delete [] horde;
	std::cout << i << " zombies disappeared" << std::endl;
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 08:29:02 by marvin            #+#    #+#             */
/*   Updated: 2023/11/03 09:19:52 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie *zomb;
	int		i;

	zomb = new Zombie[N];
	i = 0;
	while (i < N)
	{
		zomb[i].setName(name);
		i++;
	}
	return (zomb);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:26:50 by marvin            #+#    #+#             */
/*   Updated: 2023/10/28 16:26:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap a("A");
	ClapTrap b("B");

	a.attack("B");
	b.takeDamage(a.getAD());
	a.setAD(9);
	a.attack("B");
	b.takeDamage(a.getAD());
	b.beRepaired(3);
	b.setEP(0);
	b.beRepaired(1);
	a.attack("B");
	b.takeDamage(a.getAD());
	a.attack("B");
	b.takeDamage(a.getAD());
	b.beRepaired(1);
}

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

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap a("A");
	ScavTrap b("B");

	std::cout << b.getEP() << std::endl;
	a.attack("B");
	b.takeDamage(a.getAD());
	a.setAD(79);
	a.attack("B");
	b.takeDamage(a.getAD());
	b.beRepaired(50);
	b.setEP(0);
	b.beRepaired(1);
	a.attack("B");
	b.takeDamage(a.getAD());
	a.attack("B");
	b.takeDamage(a.getAD());
	b.beRepaired(1);
	a.guardGate();
}

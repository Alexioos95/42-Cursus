/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:36:47 by marvin            #+#    #+#             */
/*   Updated: 2023/11/03 11:56:11 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		// constructors and destructor
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap &rhs);
		~ScavTrap(void);
		// overload
		ScavTrap	&operator=(ScavTrap &rhs);
		// functions
		void		attack(const std::string& target);
		void		guardGate();
};

# endif

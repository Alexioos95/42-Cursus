/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:36:47 by marvin            #+#    #+#             */
/*   Updated: 2023/11/03 11:56:05 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		// constructors and destructor
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap &rhs);
		~FragTrap(void);
		// overload
		FragTrap	&operator=(FragTrap &rhs);
		// functions
		void		highFivesGuys(void);
};

# endif

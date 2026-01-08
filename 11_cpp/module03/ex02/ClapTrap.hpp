/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:44:02 by marvin            #+#    #+#             */
/*   Updated: 2023/11/08 12:47:05 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	public:
		// constructors and destructor
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &src);
		~ClapTrap(void);
		// overload
		ClapTrap	&operator=(ClapTrap const &rhs);
		// setters and getters
		void		setName(std::string name);
		void		setHP(int hp);
		void		setEP(int ep);
		void		setAD(int ad);
		std::string	getName(void) const;
		int			getHP(void) const;
		int			getEP(void) const;
		int			getAD(void) const;
		// functions
		void		attack(const std::string& target);
		void		takeDamage(unsigned int	amount);
		void		beRepaired(unsigned int	amount);

	protected:
		int			_hp;
		int			_ep;
		int			_ad;
		std::string	_name;
};

#endif

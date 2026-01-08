/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:30:21 by marvin            #+#    #+#             */
/*   Updated: 2023/10/26 14:40:36 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
	public:
		Weapon(void);
		Weapon(std::string type);
		~Weapon(void);
		void				setType(std::string type);
		const std::string	&getType(void);

	private:
		std::string	_type;
};

#endif

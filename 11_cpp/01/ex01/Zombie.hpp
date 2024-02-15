/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 08:06:35 by marvin            #+#    #+#             */
/*   Updated: 2023/10/26 14:38:26 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <sstream>
# include <string>

class Zombie
{
	public:
		Zombie(void);
		~Zombie(void);
		void	announce(void) const;
		void	setName(std::string name);

	private:
		std::string	_name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif

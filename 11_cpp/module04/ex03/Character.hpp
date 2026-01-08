/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:13:20 by apayen            #+#    #+#             */
/*   Updated: 2023/11/07 11:09:15 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
		// constructors and destructor
		Character(void);
		Character(std::string name);
		Character(Character const &rhs);
		~Character(void);
		// overload
		Character					&operator=(Character const &rhs);
		// setters and getters
		void						setName(std::string name);
		virtual std::string const &	getName() const;
		// functions
		virtual void				equip(AMateria* m);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter& target);

	private:
		std::string	_name;
		AMateria	*_tab[4];
};

#endif

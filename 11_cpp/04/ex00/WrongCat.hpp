/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:44:42 by apayen            #+#    #+#             */
/*   Updated: 2023/11/15 12:34:38 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongCAT_HPP
# define WrongCAT_HPP

# include "WrongAnimal.hpp"
# include <iostream>

class WrongCat : public WrongAnimal
{
	public:
		// constructors and destructor
		WrongCat(void);
		WrongCat(std::string type);
		WrongCat(WrongCat const &src);
		~WrongCat(void);
		// overload
		WrongCat	&operator=(WrongCat const &rhs);
		// function
		void		makeSound(void) const;
};

#endif

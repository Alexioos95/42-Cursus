/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:44:42 by apayen            #+#    #+#             */
/*   Updated: 2023/11/15 12:34:25 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <iostream>

class Dog : public Animal
{
	public:
		// constructors and destructor
		Dog(void);
		Dog(std::string type);
		Dog(Dog const &src);
		~Dog(void);
		// overload
		Dog				&operator=(Dog const &rhs);
		// function
		virtual void	makeSound(void) const;
};

#endif

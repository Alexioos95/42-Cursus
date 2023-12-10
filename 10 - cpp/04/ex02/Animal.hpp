/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:36:10 by apayen            #+#    #+#             */
/*   Updated: 2023/11/03 14:20:37 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	public:
		// constructors and destructor
		Animal(void);
		Animal(std::string type);
		Animal(Animal const &src);
		virtual ~Animal(void);
		// overload
		Animal	&operator=(Animal const &rhs);
		// setters and getters
		std::string		getType(void) const;
		// functions
		virtual void	makeSound(void) const = 0;

	protected:
		std::string _type;
};

#endif

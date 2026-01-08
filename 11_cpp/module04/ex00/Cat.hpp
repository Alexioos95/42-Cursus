/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:44:42 by apayen            #+#    #+#             */
/*   Updated: 2023/11/15 12:34:28 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <iostream>

class Cat : public Animal
{
	public:
		// constructors and destructor
		Cat(void);
		Cat(std::string type);
		Cat(Cat const &src);
		~Cat(void);
		// overload
		Cat				&operator=(Cat const &rhs);
		// function
		virtual void	makeSound(void) const;
};

#endif

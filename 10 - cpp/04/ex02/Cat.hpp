/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:44:42 by apayen            #+#    #+#             */
/*   Updated: 2023/11/03 14:09:49 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
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
		// setters and getters
		void			setIdea(int i, std::string idea);
		std::string		getIdea(int i);
		Brain			getBrain();
		// functions
		virtual void	makeSound(void) const;

	private:
		Brain	*_ideas;
};

#endif

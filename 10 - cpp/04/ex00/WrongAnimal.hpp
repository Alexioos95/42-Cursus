/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:36:10 by apayen            #+#    #+#             */
/*   Updated: 2023/11/03 12:18:31 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	public:
		// constructors and destructor
		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal const &src);
		~WrongAnimal(void);
		// overload
		WrongAnimal	&operator=(WrongAnimal const &rhs);
		// setters and getters
		std::string		getType(void) const;
		// functions
		void			makeSound(void) const;

	protected:
		std::string _type;
};

#endif

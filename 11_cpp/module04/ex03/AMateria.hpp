/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:33:36 by apayen            #+#    #+#             */
/*   Updated: 2023/11/20 16:38:54 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
	private:
		std::string _type2;

	protected:
		std::string	_type;

	public:
		// constructors and destructor
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(AMateria const &rhs);
		virtual ~AMateria(void);
		// overload
		AMateria			&operator=(AMateria const &rhs);
		// setters and getters
		void				setType(std::string type);
		std::string const &	getType() const; //Returns the materia type
		// functions
		virtual AMateria*	clone() const = 0;
		virtual void 		use(ICharacter& target);
};

#endif

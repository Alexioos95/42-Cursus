/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:53:21 by apayen            #+#    #+#             */
/*   Updated: 2023/11/07 10:45:53 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		// constructors and destructor
		Cure(void);
		Cure(Cure const &rhs);
		~Cure(void);
		// overload
		Cure				&operator=(Cure const &rhs);
		// functions
		virtual AMateria*	clone() const;
		virtual void 		use(ICharacter& target);
};

#endif

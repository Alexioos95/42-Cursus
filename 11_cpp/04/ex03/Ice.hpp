/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:53:21 by apayen            #+#    #+#             */
/*   Updated: 2023/11/07 10:35:53 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		// constructors and destructor
		Ice(void);
		Ice(Ice const &rhs);
		~Ice(void);
		// overload
		Ice	&operator=(Ice const &rhs);
		// functions
		virtual AMateria*	clone() const;
		virtual void 		use(ICharacter& target);
};

#endif

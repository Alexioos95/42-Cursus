/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:45:53 by apayen            #+#    #+#             */
/*   Updated: 2023/11/20 10:13:23 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <cstdlib>
# include <exception>

class Base
{
	public:
		virtual ~Base(void);
};

Base	*generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif

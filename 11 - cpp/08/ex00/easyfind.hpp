/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:09:12 by apayen            #+#    #+#             */
/*   Updated: 2023/11/21 12:12:21 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <exception>
# include <iostream>
# include <vector>
# include <algorithm>
# include <iterator>

class NoOccurence : public std::exception
{
	public:
		virtual const char	*what(void) const throw();
};

template<typename T>
typename T::iterator	easyfind(T &tab, int nb)
{
	typename T::iterator	it;

	it = std::find(tab.begin(), tab.end(), nb);
	if (it == tab.end() && *tab.end() != nb)
		throw (NoOccurence());
	return (it);
}

#endif

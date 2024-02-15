/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:19:40 by apayen            #+#    #+#             */
/*   Updated: 2023/11/20 11:26:35 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template<typename T>
void	swap(T &one, T &two)
{
	T	tmp;
	tmp = one;
	one = two;
	two = tmp;
}

template<typename T>
T	min(T one, T two)
{
	if (one < two)
		return (one);
	return (two);
}

template<typename T>
T	max(T one, T two)
{
	if (one > two)
		return (one);
	return (two);
}

#endif

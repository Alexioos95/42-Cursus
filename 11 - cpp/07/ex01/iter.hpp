/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:36:42 by apayen            #+#    #+#             */
/*   Updated: 2023/11/20 16:10:25 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T, typename U, typename V>
void	iter(T *addr, unsigned int length, U f(V))
{
	unsigned int	i;

	i = 0;
	while (i < length)
	{
		addr[i] = f(addr[i]);
		i++;
	}
}

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:30:50 by apayen            #+#    #+#             */
/*   Updated: 2022/11/24 16:43:17 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_ptr(unsigned long int nb, char c)
{
	int	len;

	len = 0;
	if (nb >= 16)
		len += ft_ptr(nb / 16, c);
	if (nb % 16 <= 9)
		len += ft_putchar((nb % 16) + '0');
	else
	{
		if (c == 'X')
			len += ft_putchar((nb % 16) + 55);
		else
			len += ft_putchar((nb % 16) + 87);
	}
	return (len);
}

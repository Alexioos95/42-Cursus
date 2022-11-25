/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:08:58 by apayen            #+#    #+#             */
/*   Updated: 2022/11/24 16:43:20 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr(int nb)
{
	int				len;
	long long int	nb2;

	len = 0;
	nb2 = nb;
	if (nb2 < 0)
	{
		len += ft_putchar('-');
		nb2 *= -1;
	}
	if (nb2 >= 10)
		len += ft_putnbr(nb2 / 10);
	len += ft_putchar((nb2 % 10) + '0');
	return (len);
}

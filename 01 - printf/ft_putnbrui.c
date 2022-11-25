/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrui.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:33:49 by apayen            #+#    #+#             */
/*   Updated: 2022/11/24 16:54:08 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbrui(unsigned int n)
{
	int						len;
	unsigned long long int	nb;

	nb = n;
	len = 0;
	if (nb >= 10)
		len += ft_putnbrui(nb / 10);
	len += ft_putchar((nb % 10) + '0');
	return (len);
}

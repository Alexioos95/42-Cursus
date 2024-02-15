/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:28:45 by apayen            #+#    #+#             */
/*   Updated: 2023/01/25 14:50:43 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

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

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, format);
	i = 0;
	len = 0;
	if (!format)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == 'd')
		{
			len += ft_putnbr(va_arg(args, int));
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
		if (len == -1)
			return (len);
	}
	va_end(args);
	return (len);
}

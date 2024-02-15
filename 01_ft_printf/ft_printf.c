/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:28:45 by apayen            #+#    #+#             */
/*   Updated: 2022/11/25 09:26:49 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
		if (format[i] == '%' && ft_isformat(format[i + 1]) == 1)
		{
			len += ft_format(args, format[i + 1]);
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

/*
#include <stdio.h>
int	main(void)
{
	int i;

	i = 0;
	ft_printf("Mine : %p \n", &i);
	printf("Real : %p \n", &i);
	return (0);
}
*/

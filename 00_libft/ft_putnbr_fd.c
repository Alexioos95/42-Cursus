/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:52:35 by apayen            #+#    #+#             */
/*   Updated: 2022/11/15 11:22:13 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long int	n2;

	n2 = n;
	if (n2 < 0)
	{
		ft_putchar_fd('-', fd);
		n2 *= -1;
	}
	if (n2 >= 10)
	{
		ft_putnbr_fd(n2 / 10, fd);
	}
	ft_putchar_fd((n2 % 10 + '0'), fd);
}

/*
int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_putnbr_fd(atoi(argv[1]), atoi(argv[2]));
	}
	return (0);
}
*/

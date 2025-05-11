/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:27:19 by apayen            #+#    #+#             */
/*   Updated: 2023/01/13 09:57:25 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	notdouble(int *tab, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < i)
		{
			if (tab[j] == tab[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	isvalid(char b, char c, char d, int i)
{
	if (c == '+' || c == '-')
	{
		if (i != 0)
		{
			if ((b >= 9 && b <= 13) || b == 32)
				return (1);
			return (0);
		}
		if (d >= '0' && d <= '9')
			return (1);
		return (0);
	}
	else if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	notnum(int argc, char **argv)
{
	int	i;
	int	j;
	int	b;

	j = 1;
	b = 0;
	if (argc == 1)
		return (1);
	while (j < argc)
	{
		i = 0;
		while (argv[j][i] != '\0')
		{
			if (argv[j][i] >= '0' && argv[j][i] <= '9')
				b = 1;
			else if (isvalid(argv[j][i - 1], argv[j][i], argv[j][i + 1],
						i) == 0)
				return (write(2, "Error\n", 6), 1);
			i++;
		}
		j++;
	}
	if (b == 0)
		return (write(2, "Error\n", 6), 1);
	return (0);
}

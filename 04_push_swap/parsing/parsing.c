/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:29:12 by apayen            #+#    #+#             */
/*   Updated: 2023/01/16 13:08:42 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi(char *str, int i, int *b)
{
	long long int	result;
	long long int	sign;

	result = 0;
	sign = 1;
	while (str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
		if ((result * sign > INT_MAX) || (sign == -1 && result
				* sign < INT_MIN))
			*b = 1;
	}
	return ((int)result * (int)sign);
}

int	issp(char c)
{
	if ((c == 32) || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

void	filltab(int argc, char **argv, int *tab, int *b)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 1;
	k = 0;
	while (j < argc)
	{
		i = 0;
		while (argv[j][i] != '\0')
		{
			while (argv[j][i] == 32 || (argv[j][i] >= 9 && argv[j][i] <= 13))
				i++;
			if (argv[j][i] == '\0')
				return ;
			tab[k] = ft_atoi(argv[j], i, b);
			k++;
			if (*b == 1)
				return (free(tab));
			while (argv[j][i] != '\0' && issp(argv[j][i]) == 0)
				i++;
		}
		j++;
	}
}

int	getlen(int argc, char **argv)
{
	int	i;
	int	j;
	int	len;

	j = 1;
	len = 0;
	while (j < argc)
	{
		i = 0;
		while (argv[j][i] != '\0')
		{
			while ((argv[j][i] == 32) || (argv[j][i] >= 9 && argv[j][i] <= 13))
				i++;
			if (argv[j][i] == '\0')
				return (len);
			len++;
			if (argv[j][i] == '-' || argv[j][i] == '+')
				i++;
			while (argv[j][i] >= '0' && argv[j][i] <= '9')
				i++;
		}
		j++;
	}
	return (len);
}

int	*parsing(int argc, char **argv, int len)
{
	int	*tab;
	int	error;
	int	b;

	b = 0;
	tab = malloc(sizeof(int) * len);
	if (tab == NULL)
		return (NULL);
	filltab(argc, argv, tab, &b);
	if (b == 1)
		return (NULL);
	error = notdouble(tab, len);
	if (error == 1)
		return (free(tab), NULL);
	return (tab);
}

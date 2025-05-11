/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplifytab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:38:08 by apayen            #+#    #+#             */
/*   Updated: 2023/01/12 09:43:38 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	renametab(int *tab, int *new, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		j = 0;
		while (new[j] != tab[i])
			j++;
		tab[i] = j;
		i++;
	}
}

void	swap(int *tab, int i)
{
	int	tmp;

	tmp = tab[i];
	tab[i] = tab[i + 1];
	tab[i + 1] = tmp;
}

int	*copytab(int *tab, int len)
{
	int	i;
	int	*new;

	i = 0;
	new = malloc(sizeof(int) * len);
	if (new == NULL)
		return (NULL);
	while (i < len)
	{
		new[i] = tab[i];
		i++;
	}
	return (new);
}

int	*simplifytab(int *tab, int len)
{
	int	i;
	int	*new;

	i = 0;
	new = copytab(tab, len);
	if (new == NULL)
		return (NULL);
	while (i < len - 1)
	{
		if (new[i] > new[i + 1])
		{
			swap(new, i);
			i = 0;
		}
		else
			i++;
	}
	renametab(tab, new, len);
	free(new);
	return (tab);
}

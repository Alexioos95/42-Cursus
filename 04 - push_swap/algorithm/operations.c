/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 09:56:34 by apayen            #+#    #+#             */
/*   Updated: 2023/01/16 09:31:36 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pusha(int *stacka, int *stackb, int *lena, int *lenb)
{
	int	i;

	i = *lena;
	if (*lenb == 0)
		return ;
	if (*lena != 0)
	{
		while (i > 0)
		{
			stacka[i] = stacka[i - 1];
			i--;
		}
	}
	stacka[0] = stackb[0];
	(*lena)++;
	i = 0;
	while (i < *lenb - 1)
	{
		stackb[i] = stackb[i + 1];
		i++;
	}
	(*lenb)--;
	write(1, "pa\n", 3);
}

void	pushb(int *stacka, int *stackb, int *lena, int *lenb)
{
	int	i;

	i = *lenb;
	if (*lena == 0)
		return ;
	if (*lenb != 0)
	{
		while (i > 0)
		{
			stackb[i] = stackb[i - 1];
			i--;
		}
	}
	stackb[0] = stacka[0];
	(*lenb)++;
	i = 0;
	while (i < *lena - 1)
	{
		stacka[i] = stacka[i + 1];
		i++;
	}
	(*lena)--;
	write(1, "pb\n", 3);
}

void	rotatea(int *stacka, int *lena)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stacka[0];
	while (i < *lena - 1)
	{
		stacka[i] = stacka[i + 1];
		i++;
	}
	stacka[i] = tmp;
	write(1, "ra\n", 3);
}

void	reverserotatea(int *stacka, int *lena)
{
	int	i;
	int	tmp;

	i = *lena - 1;
	tmp = stacka[i];
	while (i > 0)
	{
		stacka[i] = stacka[i - 1];
		i--;
	}
	stacka[0] = tmp;
	write(1, "rra\n", 4);
}

void	swapa(int *stacka)
{
	int	tmp;

	tmp = stacka[0];
	stacka[0] = stacka[1];
	stacka[1] = tmp;
	write(1, "sa\n", 3);
}

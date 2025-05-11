/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortsmallstack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:11:35 by apayen            #+#    #+#             */
/*   Updated: 2023/01/16 09:24:09 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	getminmax(int *tab, int len, int b)
{
	int	i;
	int	result;

	i = 1;
	result = tab[0];
	while (i < len)
	{
		if (b == 1)
		{
			if (result < tab[i])
				result = tab[i];
		}
		else
		{
			if (result > tab[i])
				result = tab[i];
		}
		i++;
	}
	return (result);
}

void	sort3num(int *stacka, int *lena)
{
	int	min;
	int	max;

	min = getminmax(stacka, *lena, 0);
	max = getminmax(stacka, *lena, 1);
	if (issorted(stacka, *lena) == 1)
		return ;
	if (stacka[0] == min)
	{
		swapa(stacka);
		rotatea(stacka, lena);
	}
	else if (stacka[0] == max && stacka[2] == min)
	{
		swapa(stacka);
		reverserotatea(stacka, lena);
	}
	else if (stacka[0] == max && stacka[1] == min)
		rotatea(stacka, lena);
	else if (stacka[1] == max && stacka[2] == min)
		reverserotatea(stacka, lena);
	else if (stacka[2] == max && stacka[1] == min)
		swapa(stacka);
}

void	sort4num(int *stacka, int *stackb, int *lena, int *lenb)
{
	sort3num(stacka, lena);
	if (stackb[0] < stacka[0])
		pusha(stacka, stackb, lena, lenb);
	else if (stackb[0] > stacka[2])
	{
		pusha(stacka, stackb, lena, lenb);
		rotatea(stacka, lena);
	}
	else if (stackb[0] < stacka[1])
	{
		pusha(stacka, stackb, lena, lenb);
		swapa(stacka);
	}
	else if (stackb[0] > stacka[1])
	{
		reverserotatea(stacka, lena);
		pusha(stacka, stackb, lena, lenb);
		rotatea(stacka, lena);
		rotatea(stacka, lena);
	}
}

void	sort5num(int *stacka, int *stackb, int *lena, int *lenb)
{
	sort4num(stacka, stackb, lena, lenb);
	if (stackb[0] > stacka[0] && stackb[0] < stacka[1])
	{
		pusha(stacka, stackb, lena, lenb);
		swapa(stacka);
	}
	else if (stackb[0] > stacka[1] && stackb[0] < stacka[2])
	{
		rotatea(stacka, lena);
		pusha(stacka, stackb, lena, lenb);
		swapa(stacka);
		reverserotatea(stacka, lena);
	}
	else if (stackb[0] > stacka[2] && stackb[0] < stacka[3])
	{
		reverserotatea(stacka, lena);
		pusha(stacka, stackb, lena, lenb);
		rotatea(stacka, lena);
		rotatea(stacka, lena);
	}
	else if (stackb[0] < stacka[0] || stackb[0] > stacka[3])
		pusha(stacka, stackb, lena, lenb);
	if (stacka[0] > stacka[3])
		rotatea(stacka, lena);
}

void	sortsmallstack(struct s_stack stacks)
{
	stacks.lenb = 0;
	if (stacks.lena == 2)
		swapa(stacks.stacka);
	else if (stacks.lena == 3)
		sort3num(stacks.stacka, &stacks.lena);
	else if (stacks.lena == 4)
	{
		pushb(stacks.stacka, stacks.stackb, &stacks.lena, &stacks.lenb);
		sort4num(stacks.stacka, stacks.stackb, &stacks.lena, &stacks.lenb);
	}
	else if (stacks.lena == 5)
	{
		pushb(stacks.stacka, stacks.stackb, &stacks.lena, &stacks.lenb);
		pushb(stacks.stacka, stacks.stackb, &stacks.lena, &stacks.lenb);
		sort5num(stacks.stacka, stacks.stackb, &stacks.lena, &stacks.lenb);
	}
}

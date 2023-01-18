/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:32:51 by apayen            #+#    #+#             */
/*   Updated: 2023/01/16 09:39:24 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	getmaxdivisor(int *stacka, int lena)
{
	int	max;
	int	maxdivisor;

	max = getminmax(stacka, lena, 1);
	maxdivisor = 1;
	while (max > 9)
	{
		max /= 10;
		maxdivisor *= 10;
	}
	return (maxdivisor);
}

void	radixsort(struct s_stack stacks)
{
	int	i;
	int	divisor;
	int	tmp;

	divisor = 0;
	stacks.lenb = 0;
	tmp = stacks.lena;
	stacks.stacka = simplifytab(stacks.stacka, stacks.lena);
	if (stacks.stacka == NULL)
		return ;
	while (issorted(stacks.stacka, stacks.lena) == 0)
	{
		i = 0;
		while (i < tmp)
		{
			if (stacks.stacka[0] >> divisor & 1)
				rotatea(stacks.stacka, &stacks.lena);
			else
				pushb(stacks.stacka, stacks.stackb, &stacks.lena, &stacks.lenb);
			i++;
		}
		while (stacks.lenb > 0)
			pusha(stacks.stacka, stacks.stackb, &stacks.lena, &stacks.lenb);
		divisor++;
	}
}

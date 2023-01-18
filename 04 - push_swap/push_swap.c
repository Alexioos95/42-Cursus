/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:27:42 by apayen            #+#    #+#             */
/*   Updated: 2023/01/16 09:46:46 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	issorted(int *stack, int len)
{
	int	i;

	i = 1;
	while (i < len)
	{
		if (stack[i] < stack[i - 1])
			return (0);
		i++;
	}
	return (1);
}

int	*errorandparse(int argc, char **argv, int len)
{
	int	*tab;

	tab = parsing(argc, argv, len);
	if (tab == NULL)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	return (tab);
}

int	main(int argc, char **argv)
{
	struct s_stack	stacks;

	if (argc == 1)
		return (0);
	stacks.error = notnum(argc, argv);
	if (stacks.error == 1)
		return (-1);
	stacks.lena = getlen(argc, argv);
	stacks.stacka = errorandparse(argc, argv, stacks.lena);
	if (stacks.stacka == NULL)
		return (-1);
	if (issorted(stacks.stacka, stacks.lena) == 1)
		return (free(stacks.stacka), 0);
	stacks.stackb = malloc(sizeof(int) * stacks.lena);
	if (stacks.stackb == NULL)
		return (free(stacks.stacka), -1);
	if (stacks.lena <= 5)
		sortsmallstack(stacks);
	else if (stacks.lena >= 6)
		radixsort(stacks);
	if (stacks.stacka == NULL)
		return (free(stacks.stackb), -1);
	return (free(stacks.stacka), free(stacks.stackb), 0);
}

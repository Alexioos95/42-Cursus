/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:42:04 by apayen            #+#    #+#             */
/*   Updated: 2022/11/10 14:25:19 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/*
#include <ctype.h>
#include <stdio.h>
int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc == 2)
	{
		i = ft_isprint(atoi(argv[1]));
		j = isprint(atoi(argv[1]));
		printf("Mine : %d\nReal : %d\n", i, j);
	}
	return (0);
}
*/

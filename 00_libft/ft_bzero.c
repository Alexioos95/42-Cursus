/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:51:29 by apayen            #+#    #+#             */
/*   Updated: 2022/11/09 10:23:22 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*s2;

	i = 0;
	s2 = (unsigned char *)s;
	while (i < n)
	{
		s2[i] = 0;
		i++;
	}
}

/*
#include <strings.h>
#include <stdio.h>
int	main(void)
{
	char	tab[5] = {'1', '2', '3', '4', '5'};
	char	tab2[5] = {'1', '2', '3', '4', '5'};
	int	i;

	i = 0;
	ft_bzero(tab, 5);
	bzero(tab2, 5);
	printf("Mine : ");
	while (i <= 4)
	{
		printf("%i", tab[i]);
		i++;
	}
	i = 0;
	printf("\nReal : ");
	while (i <= 4)
	{
		printf("%i", tab2[i]);
		i++;
	}
	printf("\n");
}
*/

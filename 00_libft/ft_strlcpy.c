/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:12:22 by apayen            #+#    #+#             */
/*   Updated: 2022/11/15 14:05:01 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		return (ft_strlen(src));
	}
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

/*
#include <bsd/string.h>
#include <stdio.h>
int	main(int argc, char **argv)
{
	int	j;

	if (argc == 4)
	{
		j = strlcpy(argv[1], argv[2], atoi(argv[3]));
		printf("Real : %d\n", j);
		printf("Dest : %s\n", argv[1]);
	}
	return (0);
}
*/

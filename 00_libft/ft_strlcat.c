/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:12:22 by apayen            #+#    #+#             */
/*   Updated: 2022/11/16 13:08:58 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	j;
	size_t	len_d;
	size_t	len_s;

	j = 0;
	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	if (size <= len_d)
		return (size + len_s);
	while (src[j] != '\0' && j < (size - len_d - 1))
	{
		dst[len_d + j] = src[j];
		j++;
	}
	dst[len_d + j] = '\0';
	return (len_d + len_s);
}

/*
#include <bsd/string.h>
#include <stdio.h>
int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc == 4)
	{
		i = ft_strlcat(argv[1], argv[2], atoi(argv[3]));
		j = strlcat(argv[1], argv[2], atoi(argv[3]));
		printf("Mine : %d\nReal : %d\n", i, j);
	}
	return (0);
}
*/

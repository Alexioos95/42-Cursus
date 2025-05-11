/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:36:42 by apayen            #+#    #+#             */
/*   Updated: 2022/11/16 11:33:23 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	*s2;

	s2 = (unsigned char *)s;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s2[i] == (unsigned char)c)
		{
			return ((char *)&s2[i]);
		}
		i--;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>
int	main(int argc, char **argv)
{
	char	*i;
	char	*j;

	if (argc == 3)
	{
		i = ft_strrchr(argv[1], argv[2][0]);
		j = strrchr(argv[1], argv[2][0]);
		printf("Mine : %s\nReal : %s\n", i, j);
	}
	return (0);
}
*/

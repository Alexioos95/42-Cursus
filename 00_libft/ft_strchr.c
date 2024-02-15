/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:36:42 by apayen            #+#    #+#             */
/*   Updated: 2022/11/16 11:07:12 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*s2;

	s2 = (unsigned char *)s;
	if (c == '\0')
	{
		i = ft_strlen(s);
		return ((char *)&s2[i]);
	}
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s2[i]);
		}
		i++;
	}
	return (NULL);
}

/*
#include <stddef.h>
#include <stdio.h>
#include <string.h>
int	main(int argc, char **argv)
{
	char	*i;
	char	*j;

	if (argc == 3)
	{
		i = ft_strchr(argv[1], *argv[2][0]);
		j = strchr(argv[1], *argv[2][0]);
		printf("Mine : %s\nReal : %s\n", i, j);
	}
	return (0);
}
*/

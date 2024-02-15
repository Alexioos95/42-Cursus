/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:42:35 by apayen            #+#    #+#             */
/*   Updated: 2022/11/15 16:40:37 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s3;
	unsigned char	*s4;

	s3 = (unsigned char *)s1;
	s4 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (s3[i] != '\0' && s4[i] != '\0' && s3[i] == s4[i] && i < n - 1)
	{
		i++;
	}
	return (s3[i] - s4[i]);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	int	i;
	int	j;

		i = ft_strncmp("tesa", "test", 4);
		j = strncmp("tesa", "test", 4);
		printf("Mine : %d\nReal : %d\n", i, j);
	return (0);
}
*/
/*
#include <stdio.h>
#include <string.h>
int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc == 4)
	{
		i = ft_strncmp(argv[1], argv[2], atoi(argv[3]));
		j = strncmp(argv[1], argv[2], atoi(argv[3]));
		printf("Mine : %d\nReal : %d\n", i, j);
	}
	return (0);
}
*/

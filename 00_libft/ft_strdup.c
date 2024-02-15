/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:44:42 by apayen            #+#    #+#             */
/*   Updated: 2022/11/15 09:44:30 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	size_t	len;
	char	*s1;

	i = 0;
	len = ft_strlen(s);
	s1 = malloc(sizeof(char) * (len + 1));
	if (s1 == NULL)
	{
		return (NULL);
	}
	while (s[i] != '\0')
	{
		s1[i] = s[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

/*
#include <stdio.h>
#include <string.h>
int	main(int argc, char **argv)
{
	char	*i;
	char	*j;

	if (argc == 2)
	{
		i = ft_strdup(argv[1]);
		j = strdup(argv[1]);
		printf("Mine : %s\nReal : %s\n", i, j);
	}
	return (0);
}
*/

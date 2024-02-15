/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:35:21 by apayen            #+#    #+#             */
/*   Updated: 2022/11/16 09:49:37 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*strmalloc;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	strmalloc = malloc(sizeof(char) * len + 1);
	if (strmalloc == NULL)
	{
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		strmalloc[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		strmalloc[i + j] = s2[j];
		j++;
	}
	strmalloc[i + j] = '\0';
	return (strmalloc);
}

/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	char	*i;

	if (argc == 3)
	{
		i = ft_strjoin(argv[1], argv[2]);
		printf("%s", i);
	}
	return (0);
}
*/

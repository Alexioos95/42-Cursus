/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:20:06 by apayen            #+#    #+#             */
/*   Updated: 2022/11/21 13:12:57 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
		{
			return (1);
		}
		else
		{
			i++;
		}
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		len;
	int		lenm;
	char	*strmalloc;

	i = 0;
	j = 0;
	len = ft_strlen(s1) - 1;
	while (is_set(s1[len], set) == 1)
		len--;
	while (is_set(s1[i], set) == 1)
		i++;
	lenm = ft_strlen(&s1[i]) - ft_strlen(&s1[len]);
	strmalloc = ft_substr(s1, i, (lenm + 1));
	while (i <= len && strmalloc != NULL)
	{
		strmalloc[j] = s1[i];
		j++;
		i++;
	}
	if (strmalloc != NULL)
		strmalloc[j] = '\0';
	return (strmalloc);
}

/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	char	*i;

	if (argc == 3)
	{
		i = ft_strtrim(argv[1], argv[2]);
		printf("%s\n", i);
	}
	return (0);
}
*/

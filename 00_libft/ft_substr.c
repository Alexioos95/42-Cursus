/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:24:45 by apayen            #+#    #+#             */
/*   Updated: 2022/11/16 12:22:26 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*strmalloc;

	i = 0;
	if (start >= ft_strlen(s))
	{
		strmalloc = malloc(sizeof(char) * 1);
		strmalloc[0] = '\0';
		return (strmalloc);
	}
	if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	strmalloc = malloc(sizeof(char) * len + 1);
	if (strmalloc == NULL)
		return (NULL);
	while (s[i] != '\0' && i < len)
	{
		strmalloc[i] = s[start];
		i++;
		start++;
	}
	strmalloc[i] = '\0';
	return (strmalloc);
}

/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	char	*i;

	if (argc == 4)
	{
		i = ft_substr(argv[1], atoi(argv[2]), atoi(argv[3]));
		printf("%s\n", i);
	}
	return (0);
}
*/

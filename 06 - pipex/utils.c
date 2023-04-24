/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:35:21 by apayen            #+#    #+#             */
/*   Updated: 2023/04/11 10:27:47 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strnstr(char *big, char *little)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[j] == '\0')
	{
		return ((char *)big);
	}
	while (big[i] != '\0')
	{
		j = 0;
		while (big[i + j] == little[j] && little[j] != '\0')
		{
			j++;
			if (little[j] == '\0' && i == 0)
			{
				return ((char *)&big[i + 5]);
			}
		}
		i++;
	}
	return (NULL);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

void	addslash(char *s1, char *strmalloc, int i)
{
	strmalloc[i] = '/';
	free(s1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*strmalloc;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	strmalloc = malloc(sizeof(char) * (unsigned int)len + 2);
	if (strmalloc == NULL)
		return ((void)perror("pipex: malloc"), NULL);
	while (s1[i] != '\0')
	{
		strmalloc[i] = s1[i];
		i++;
	}
	addslash(s1, strmalloc, i);
	i++;
	while (s2[j] != '\0')
	{
		strmalloc[i + j] = s2[j];
		j++;
	}
	strmalloc[i + j] = '\0';
	return (strmalloc);
}

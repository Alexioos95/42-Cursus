/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:10:13 by eewu              #+#    #+#             */
/*   Updated: 2023/09/20 17:51:34 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str && i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	tab = malloc(size * nmemb);
	ft_bzero(tab, size * nmemb);
	return (tab);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2 || ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if ((int)ft_strlen(s1) != i)
		return (0);
	return (1);
}

char	*ft_tabcmp(char *str, char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (NULL);
	while (tab[i])
	{
		if (ft_strcmp(str, tab[i]))
			return (tab[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strnstr_cmp(char *big, char *little, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!little[j])
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (i + j < len && (big[i + j] == little[j]))
		{
			j++;
			if (!little[j])
				return ((char *)&big[i]);
		}
		i++;
	}
	return (0);
}

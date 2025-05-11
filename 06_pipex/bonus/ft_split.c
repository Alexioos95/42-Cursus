/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:00:12 by apayen            #+#    #+#             */
/*   Updated: 2023/04/11 10:33:27 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_countstr(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] != c)
			i++;
		count++;
		while (s[i] != '\0' && s[i] == c)
			i++;
	}
	return (count);
}

char	*ft_strdupsplit(char *s, char c, int j)
{
	int		i;
	int		len;
	char	*s1;

	i = 0;
	len = j;
	while (s[len] != '\0' && s[len] != c)
		len++;
	len = len - j;
	s1 = malloc(sizeof(char) * ((unsigned int)len + 1));
	if (s1 == NULL)
		return (NULL);
	while (i < len)
	{
		s1[i] = s[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}

void	ft_free(char **strmalloc, int i)
{
	while (i >= 0)
	{
		free(strmalloc[i]);
		i--;
	}
	free(strmalloc);
}

char	*ft_loop(char *s, char c, int i)
{
	char	*str;
	int		j;
	int		loop;

	j = 0;
	loop = 0;
	while (s[j] != '\0' && s[j] == c)
		j++;
	while (loop < i)
	{
		while (s[j] != '\0' && s[j] != c)
			j++;
		while (s[j] != '\0' && s[j] == c)
			j++;
		loop++;
	}
	str = ft_strdupsplit(s, c, j);
	if (str == NULL)
		return (NULL);
	return (str);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		len;
	char	**strmalloc;

	i = 0;
	if (s == NULL)
		return (NULL);
	len = ft_countstr(s, c);
	strmalloc = malloc(sizeof(char *) * ((unsigned int)len + 1));
	if (strmalloc == NULL)
		return (NULL);
	while (i < len)
	{
		strmalloc[i] = ft_loop(s, c, i);
		if (strmalloc[i] == NULL)
			return ((void)ft_free(strmalloc, i - 1), NULL);
		i++;
	}
	strmalloc[i] = NULL;
	return (strmalloc);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:19:13 by apayen            #+#    #+#             */
/*   Updated: 2022/11/23 09:23:43 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countstr(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
		{
			count++;
		}
		i++;
	}
	return (count);
}

static void	ft_filltab(int *tab, const char *s, char c)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (s[i] != '\0')
	{
		if (i == 0 && s[i] != c)
			tab[j] = i;
		else if (s[i] != c && s[i - 1] != s[i])
			tab[j] = i;
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			len++;
			tab[j + 1] = len;
		}
		len = 0;
		if (i != 0 && s[i] == c && s[i - 1] != c && s[i] != '\0')
			j += 2;
		if (s[i] != '\0')
			i++;
	}
}

void	ft_free(char **strmalloc, int len, int *tab)
{
	int	i;
	int	b;

	i = 0;
	b = 0;
	while (i < len)
	{
		if (strmalloc[i] == NULL)
		{
			b = 1;
		}
		i++;
	}
	if (b == 1)
	{
		i = 0;
		while (i <= len)
		{
			free(strmalloc[i]);
			i++;
		}
	}
	free(tab);
}

static char	*ft_substrsplit(const char *s, int start, int len)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
	{
		return (NULL);
	}
	while (i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		len;
	int		*tab;
	char	**strmalloc;

	i = 0;
	j = 0;
	len = ft_countstr(s, c);
	strmalloc = malloc(sizeof(char *) * (len + 1));
	if (strmalloc == NULL)
		return (NULL);
	tab = malloc(sizeof(int) * (len * 2));
	if (tab == NULL)
		return (NULL);
	ft_filltab(tab, s, c);
	while (i < len)
	{
		strmalloc[i] = ft_substrsplit(s, tab[j], tab[j + 1]);
		i++;
		j = j + 2;
	}
	strmalloc[i] = NULL;
	ft_free(strmalloc, len, tab);
	return (strmalloc);
}

/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	int		i;
	char	**strs;

	if (argc == 3)
	{
		i = 0;
		strs = ft_split(argv[1], argv[2][0]);
		while (strs[i])
		{
			printf("strs[%d] = %s\n", i, strs[i]);
			free(strs[i]);
			i++;
		}
		free(strs);
	}
	return (0);
}
*/

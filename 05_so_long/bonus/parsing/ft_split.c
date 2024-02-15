/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:00:12 by apayen            #+#    #+#             */
/*   Updated: 2023/02/13 16:12:06 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_countstr(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

void	ft_filltab(int *tab, const char *s, char c)
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

void	freesplit(struct s_split *split, int b)
{
	int	i;

	i = 0;
	if (b == 1)
	{
		while (i < split->len)
		{
			free(split->strmalloc[i]);
			i++;
		}
		free(split->strmalloc);
	}
	free(split->tab);
}

char	*ft_substrsplit(char *s, int start, int len)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char *s, char c)
{
	struct s_split	split;

	split.i = 0;
	split.j = 0;
	if (s == NULL)
		return (NULL);
	split.len = ft_countstr(s, c);
	split.strmalloc = malloc(sizeof(char *) * (split.len + 1));
	if (split.strmalloc == NULL)
		return (NULL);
	split.tab = malloc(sizeof(int) * (split.len * 2));
	if (split.tab == NULL)
		return (free(split.strmalloc), NULL);
	ft_filltab(split.tab, s, c);
	while (split.i < split.len)
	{
		split.strmalloc[split.i] = ft_substrsplit(s, split.tab[split.j], \
				split.tab[split.j + 1]);
		if (split.strmalloc[split.i] == NULL)
			return (freesplit(&split, 1), NULL);
		split.i++;
		split.j = split.j + 2;
	}
	split.strmalloc[split.len] = 0;
	return (freesplit(&split, 0), split.strmalloc);
}

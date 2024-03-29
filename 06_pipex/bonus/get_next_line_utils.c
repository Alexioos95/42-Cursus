/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:40:48 by apayen            #+#    #+#             */
/*   Updated: 2023/04/11 10:57:31 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_checknl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoingnl(char *s1, char *s2, int b, char *buffer)
{
	int		i;
	int		j;
	char	*strmalloc;

	i = 0;
	j = 0;
	strmalloc = malloc(sizeof(char) \
		* ((unsigned int)ft_strlen(s1) + (unsigned int)ft_strlen(s2)) + 1);
	if (strmalloc == NULL)
		return (NULL);
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
	free(s1);
	if (b == 1)
		free(s2);
	return ((void)ft_cleanbuffer(buffer), strmalloc);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*strmalloc;

	i = 0;
	strmalloc = malloc(sizeof(char) * (unsigned int)len + 1);
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

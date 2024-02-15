/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:44:02 by apayen            #+#    #+#             */
/*   Updated: 2023/03/02 10:40:18 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*strmalloc;

	i = 0;
	j = 0;
	strmalloc = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
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
	return (strmalloc);
}

char	*getmap(int fd)
{
	static char	buffer[3801];
	char		*line;
	int			r;

	if (fd < 0)
		return (NULL);
	line = malloc(sizeof(char) * 1);
	if (line == NULL)
		return (NULL);
	line[0] = '\0';
	r = read(fd, buffer, 3800);
	if (r <= 0)
		return (free(line), NULL);
	else
	{
		if (r < 3800)
			return (ft_strjoin(line, buffer));
		ft_strjoin(line, buffer);
	}
	r = read(fd, buffer, 1);
	if (r > 0)
		return (NULL);
	return (ft_strjoin(line, buffer));
}

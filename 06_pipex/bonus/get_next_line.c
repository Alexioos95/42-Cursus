/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:40:46 by apayen            #+#    #+#             */
/*   Updated: 2023/04/11 10:44:35 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_checkread(int fd, char *buffer, char *line, int *b)
{
	int		r;
	int		nl;
	char	*sub;

	r = (int)read(fd, buffer, BUFFER_SIZE);
	nl = ft_checknl(buffer);
	if (r <= 0 && line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	else
	{
		if (r < BUFFER_SIZE && nl == -1)
			*b = 1;
		if (nl != -1)
		{
			sub = ft_substr(buffer, 0, (nl + 1));
			if (sub == NULL)
				return (NULL);
			return (ft_strjoingnl(line, sub, 1, buffer));
		}
		else
			return (ft_strjoingnl(line, buffer, 0, buffer));
	}
}

void	ft_cleanbuffer(char *buffer)
{
	int	nl;
	int	j;

	nl = 0;
	j = 0;
	while (buffer[nl] != '\0' && buffer[nl] != '\n')
		nl++;
	while (nl + j < BUFFER_SIZE)
	{
		buffer[j] = buffer[nl + j + 1];
		j++;
	}
	while (j < BUFFER_SIZE)
	{
		buffer[j] = 0;
		j++;
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			b;
	int			nl;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	line = malloc(sizeof(char) * 1);
	if (line == NULL)
		return (NULL);
	line[0] = '\0';
	nl = ft_checknl(buffer);
	if (nl != -1)
		line = ft_strjoingnl(line, ft_substr(buffer, 0, (nl + 1)), 1, buffer);
	else if (buffer[0] != '\0')
		line = ft_strjoingnl(line, buffer, 0, buffer);
	b = 0;
	while (b == 0 && line != NULL && ft_checknl(line) == -1)
		line = ft_checkread(fd, buffer, line, &b);
	return (line);
}

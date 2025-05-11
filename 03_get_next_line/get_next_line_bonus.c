/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:40:46 by apayen            #+#    #+#             */
/*   Updated: 2022/12/12 14:00:24 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_checkread(int fd, char *buffer, char *line, int *b)
{
	int		r;
	int		nl;
	char	*sub;

	r = read(fd, buffer, BUFFER_SIZE);
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
			return (ft_strjoin(line, sub, 1, buffer));
		}
		else
			return (ft_strjoin(line, buffer, 0, buffer));
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
	static char	buffer[1024][BUFFER_SIZE + 1];
	char		*line;
	int			b;
	int			nl;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	line = malloc(sizeof(char) * 1);
	if (line == NULL)
		return (NULL);
	line[0] = '\0';
	nl = ft_checknl(buffer[fd]);
	if (nl != -1)
		line = ft_strjoin(line, ft_substr(buffer[fd], 0, (nl + 1)), 1,
				buffer[fd]);
	else if (buffer[fd][0] != '\0')
		line = ft_strjoin(line, buffer[fd], 0, buffer[fd]);
	b = 0;
	while (b == 0 && line != NULL && ft_checknl(line) == -1)
		line = ft_checkread(fd, buffer[fd], line, &b);
	return (line);
}

/*
#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int		fd;
	int		fd2;
	int		fd3;
	char	*line;
	int		i;

	fd = open("../file.txt", O_RDONLY);
	fd2 = open("../file2.txt", O_RDONLY);
	fd3 = open("../file3.txt", O_RDONLY);
	if (fd == -1 || fd2 == -1 || fd3 == -1)
	{
		printf("Problem with fd.\n");
		return (0);
	}
	i = 0;
	while (i < 3)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		line = get_next_line(fd2);
		printf("%s", line);
		free(line);
		line = get_next_line(fd3);
		printf("%s", line);
		free(line);
		i++;
	}
	return (0);
}
*/

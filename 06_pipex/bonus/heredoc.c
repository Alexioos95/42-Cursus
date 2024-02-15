/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:40:40 by apayen            #+#    #+#             */
/*   Updated: 2023/04/12 09:23:35 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	checklimiter(char *line, char *limiter)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && limiter[i] != '\0' && line[i] == limiter[i])
		i++;
	if (line[i] == '\n' && limiter[i] == '\0')
		return (1);
	return (0);
}

int	loop(char *line, char **argv, int *fd)
{
	int		i;

	write(0, "> ", 2);
	line = get_next_line(0);
	if (line == NULL || checklimiter(line, argv[2]) == 1)
	{
		free(line);
		return (1);
	}
	i = 0;
	while (line[i] != '\0')
	{
		write(fd[1], &line[i], 1);
		i++;
	}
	free(line);
	return (0);
}

void	heredoc(struct s_pipe *pipex, int argc, char **argv)
{
	char	*line;
	int		fd[2];

	line = NULL;
	if (argc < 6)
		exit(1);
	if (pipe(fd) == -1)
	{
		perror("pipex: pipe");
		exit(1);
	}
	pipex->infile = fd[0];
	while (1)
	{
		if (loop(line, argv, fd) == 1)
			break ;
	}
	close(fd[1]);
}

int	checkheredoc(char *argv)
{
	int		i;
	char	*str;

	i = 0;
	str = "here_doc";
	while (argv[i] != '\0' && str[i] != '\0' && argv[i] == str[i])
		i++;
	if (argv[i] == '\0' && str[i] == '\0')
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:28:28 by apayen            #+#    #+#             */
/*   Updated: 2023/04/18 11:40:59 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	mallocpids(struct s_pipe *pipex)
{
	int	i;

	i = 0;
	pipex->pid = malloc(sizeof(int) \
		* (unsigned int)(pipex->argc - 3 - pipex->heredoc));
	if (pipex->pid == NULL)
		return ((void)perror("pipex: malloc"), (void)close(pipex->infile), \
			(void)close(pipex->outfile), 1);
	while (i < pipex->argc - 3 - pipex->heredoc)
	{
		pipex->pid[0] = -1;
		i++;
	}
	return (0);
}

int	init2(struct s_pipe *pipex, int argc, char **argv)
{
	if (pipex->heredoc == 0)
	{
		pipex->infile = open(argv[1], O_RDONLY);
		if (pipex->infile == -1)
			if (badfile(pipex, argc, argv, 0) == -1)
				return (1);
	}
	pipex->outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (pipex->outfile == -1)
		if (badfile(pipex, argc, argv, 1) == 1)
			return ((void)perror("pipex: open"), 1);
	pipex->arg = NULL;
	pipex->fullpath = NULL;
	pipex->path = NULL;
	pipex->pid = NULL;
	if (mallocpids(pipex) == 1)
		return (1);
	if (pipe(pipex->fd[0]) == -1)
		return ((void)free(pipex->pid), (void)close(pipex->infile), \
			(void)close(pipex->outfile), 1);
	if (pipe(pipex->fd[1]) == -1)
		return ((void)free(pipex->pid), (void)close(pipex->fd[0][0]), \
			(void)close(pipex->fd[0][1]), (void)close(pipex->infile), \
			(void)close(pipex->outfile), 1);
	return (0);
}

int	init(struct s_pipe *pipex, int argc, char **argv, char **envp)
{
	pipex->heredoc = checkheredoc(argv[1]);
	if (pipex->heredoc == 1)
		heredoc(pipex, argc, argv);
	pipex->i = 2;
	if (pipex->heredoc == 1)
		pipex->i++;
	pipex->paddingstruct = 0;
	pipex->j = -1;
	pipex->argc = argc;
	pipex->env = envp;
	pipex->badinfile = 0;
	pipex->badoutfile = 0;
	pipex->status = 0;
	if (init2(pipex, argc, argv) == 1)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:23:23 by apayen            #+#    #+#             */
/*   Updated: 2023/04/18 12:39:41 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	closeall(struct s_pipe *pipex)
{
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	close(pipex->infile);
	close(pipex->outfile);
	waitpid(pipex->pid[0], NULL, 0);
	waitpid(pipex->pid[1], &pipex->status, 0);
	if (WIFEXITED(pipex->status))
		exit(WEXITSTATUS(pipex->status));
}

int	badfile(struct s_pipe *pipex, int argc, char **argv, int i)
{
	if (i == 0)
	{
		pipex->badinfile = 1;
		write(2, "pipex: ", 7);
		write(2, argv[1], (size_t)ft_strlen(argv[1]));
		write(2, ": ", 2);
		perror(NULL);
		pipex->infile = open("/dev/null", O_RDONLY);
		if (pipex->infile == -1)
			return (1);
	}
	else
	{
		pipex->badoutfile = 1;
		close(pipex->infile);
		write(2, "pipex: ", 7);
		write(2, argv[argc - 1], (size_t)ft_strlen(argv[argc - 1]));
		write(2, ": ", 2);
		perror(NULL);
		pipex->outfile = open("/dev/null", O_RDONLY);
		if (pipex->outfile == -1)
			return ((void)close(pipex->infile), 1);
	}
	return (0);
}

int	init(struct s_pipe *pipex, int argc, char **argv, char **envp)
{
	pipex->i = 2;
	pipex->j = -1;
	pipex->argc = argc;
	pipex->env = envp;
	pipex->badinfile = 0;
	pipex->badoutfile = 0;
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile == -1)
		if (badfile(pipex, argc, argv, 0) == -1)
			return (1);
	pipex->outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (pipex->outfile == -1)
		if (badfile(pipex, argc, argv, 1) == -1)
			return ((void)perror("pipex: open"), 1);
	if (pipe(pipex->fd) == -1)
		return ((void)close(pipex->infile), (void)close(pipex->outfile), \
			(void)perror("pipex: pipe"), 1);
	pipex->fullpath = NULL;
	pipex->path = NULL;
	pipex->arg = NULL;
	pipex->status = 0;
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	struct s_pipe	pipex;

	if (argc != 5)
	{
		write(2, "pipex usage: /pipex infile cmd1 cmd2 outfile\n", 45);
		return (1);
	}
	if (init(&pipex, argc, argv, envp) == 1)
		return (1);
	while (pipex.i < argc - 1)
	{
		pipex.pid[pipex.i - 2] = fork();
		if (pipex.pid[pipex.i - 2] == -1)
			return ((void)closeall(&pipex), \
				(void)perror("pipex: fork"), 1);
		if (pipex.pid[pipex.i - 2] == 0)
		{
			if (childprocess(argv, pipex, pipex.i) == 1)
				return (1);
		}
		else
			pipex.i++;
	}
	closeall(&pipex);
	return (pipex.status);
}

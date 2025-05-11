/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:23:23 by apayen            #+#    #+#             */
/*   Updated: 2023/04/24 10:50:53 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	freefds(struct s_pipe *pipex)
{
	if (pipex->infile >= 0)
		close(pipex->infile);
	if (pipex->outfile >= 0)
		close(pipex->outfile);
	if (pipex->fd[0][0] >= 0)
		close(pipex->fd[0][0]);
	if (pipex->fd[0][1] >= 0)
		close(pipex->fd[0][1]);
	if (pipex->fd[1][0] >= 0)
		close(pipex->fd[1][0]);
	if (pipex->fd[1][1] >= 0)
		close(pipex->fd[1][1]);
}

void	closeall(struct s_pipe *pipex)
{
	int	i;

	i = 0;
	freefds(pipex);
	while (i < pipex->i - 2 - pipex->heredoc)
	{
		waitpid(pipex->pid[i], &pipex->status, 0);
		i++;
	}
	free(pipex->pid);
	if (WIFEXITED(pipex->status))
		exit(WEXITSTATUS(pipex->status));
}

static int	looppipe(struct s_pipe *pipex)
{
	pipex->i++;
	if (pipex->i > 3 && pipex->i < pipex->argc - 2)
	{
		close(pipex->fd[(pipex->i - 2 - pipex->heredoc) % 2][0]);
		close(pipex->fd[(pipex->i - 2 - pipex->heredoc) % 2][1]);
		if (pipe(pipex->fd[(pipex->i - 2 - pipex->heredoc) % 2]) == 1)
			return ((void)closeall(pipex), 1);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	struct s_pipe	pipex;

	if (argc < 5)
		return (1);
	if (init(&pipex, argc, argv, envp) == 1)
		return (1);
	while (pipex.i < argc - 1)
	{
		pipex.pid[pipex.i - 2 - pipex.heredoc] = fork();
		if (pipex.pid[pipex.i - 2 - pipex.heredoc] == -1)
			return ((void)perror("pipex: fork"), \
				(void)closeall(&pipex), 1);
		if (pipex.pid[pipex.i - 2 - pipex.heredoc] == 0)
		{
			if (childprocess(argv, pipex, pipex.i) == 1)
				return ((void)close(0), (void)close(1), (void)close(2), 1);
		}
		else
		{
			if (looppipe(&pipex) == 1)
				return (1);
		}
	}
	closeall(&pipex);
	return (pipex.status);
}

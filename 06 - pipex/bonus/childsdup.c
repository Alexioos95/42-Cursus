/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childsdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:06:11 by apayen            #+#    #+#             */
/*   Updated: 2023/04/18 11:18:28 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	childs(struct s_pipe *pipex, int i)
{
	if (dup2(pipex->fd[(i + 1) % 2][0], STDIN_FILENO) == -1)
		return ((void)freefds(pipex), \
			(void)perror("pipex: dup2"), (void)free(pipex->pid), 1);
	if (dup2(pipex->fd[i % 2][1], STDOUT_FILENO) == -1)
		return ((void)freefds(pipex), \
			(void)perror("pipex: dup2"), (void)free(pipex->pid), 1);
	freefds(pipex);
	return (0);
}

int	lastchild(struct s_pipe *pipex, int i)
{
	if (dup2(pipex->fd[(i + 1) % 2][0], STDIN_FILENO) == -1)
		return ((void)freefds(pipex), \
			(void)perror("pipex: dup2"), (void)free(pipex->pid), 1);
	if (dup2(pipex->outfile, STDOUT_FILENO) == -1)
		return ((void)freefds(pipex), \
			(void)perror("pipex: dup2"), (void)free(pipex->pid), 1);
	freefds(pipex);
	return (0);
}

int	firstchild(struct s_pipe *pipex)
{
	if (dup2(pipex->infile, STDIN_FILENO) == -1)
		return ((void)freefds(pipex), \
			(void)perror("pipex: dup2"), (void)free(pipex->pid), 1);
	if (dup2(pipex->fd[0][1], STDOUT_FILENO) == -1)
		return ((void)freefds(pipex), \
			(void)perror("pipex: dup2"), (void)free(pipex->pid), 1);
	freefds(pipex);
	return (0);
}

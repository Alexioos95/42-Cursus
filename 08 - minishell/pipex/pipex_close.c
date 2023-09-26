/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:53:15 by eewu              #+#    #+#             */
/*   Updated: 2023/09/20 16:27:08 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_free_process(t_pipex *m)
{
	int	s;

	s = m->ms->status;
	ft_closefds(m);
	ft_closeoutin(m);
	if (WIFEXITED(s) && m->pids && m->pids[0] != -1)
		m->ms->status = (WEXITSTATUS(s));
	else if (WIFSIGNALED(s) && m->pids && m->pids[0] != -1)
		m->ms->status = 128 + WTERMSIG(s);
	ft_freefds(m);
	if (m->ms->status == 131)
		printf("Quit (core dumped)\n");
}

void	ft_close_file(t_cmd_lst *cmd)
{
	int		*fd;
	int		i;

	if (cmd)
		fd = cmd->fd;
	else
		return ;
	i = 0;
	while (fd && fd[i])
	{
		if (fd[i] >= 0)
			close(fd[i++]);
	}
}

void	ft_closeoutin(t_pipex *m)
{
	if (m->in[0] >= 0)
		close(m->in[0]);
	if (m->in[1] >= 0)
		close(m->in[1]);
	if (m->out >= 0)
		close(m->out);
	if (m->bhole >= 0)
		close(m->bhole);
}

void	ft_closefds(t_pipex *m)
{
	int	i;

	i = 0;
	while (i < m->pipe)
	{
		if (m->fds && m->fds[i][1] >= 0)
			close(m->fds[i][1]);
		if (m->fds && m->fds[i][0] >= 0)
			close(m->fds[i][0]);
		i++;
	}
}

void	ft_freefds(t_pipex *m)
{
	int	i;

	i = 0;
	while (i < m->pipe && m->fds)
		free(m->fds[i++]);
	if (m->pipe)
		free(m->fds);
	if (m->pids)
		free(m->pids);
	m->pids = NULL;
	m->fds = NULL;
}

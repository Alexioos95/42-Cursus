/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:01:50 by eewu              #+#    #+#             */
/*   Updated: 2023/09/21 16:03:34 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_pipe(t_pipex *m)
{
	int	i;

	i = 0;
	while (i < m->nb_cmd)
	{
		m->pids[i] = -1;
		if (i < 2)
		{
			if (pipe(m->fds[i]) == -1)
			{
				free(m->fds[0]);
				free(m->fds[1]);
				free(m->fds);
				m->fds = NULL;
				m->ms->error = 1;
				return ;
			}
			m->pipe++;
		}
		i++;
	}
}

int	ft_fdspipe(t_pipex *m)
{
	int	i;

	i = 0;
	m->i = m->nb_cmd % 2;
	if (m->i == 0)
		i = 1;
	return (i);
}

void	ft_fork(t_pipex *m)
{
	if (m->nb_cmd >= 1)
	{
		m->pids[m->count] = fork();
		if (m->pids[m->count] == -1)
		{
			m->ms->error = 1;
			ft_lstclearpipex(&m->cmd);
			free(m->ms->tabenv);
			ft_free_process(m);
			throwerror(m->ms, "fork");
		}
	}
}

void	ft_childprocess(t_pipex *m)
{
	int	i;
	int	dup_redir;

	i = 0;
	if (m->i == 0)
		i = 1;
	setsigaction(m->ms, 0);
	if (m->count > 0 && m->in_rok != -2)
		ft_dupcheck(m->fds[i][0], STDIN_FILENO, m);
	if (m->ms->error == 0 && m->nb_cmd > 1 && m->out_red != 1)
		ft_dupcheck(m->fds[m->i][1], STDOUT_FILENO, m);
	if (m->ms->error != 0)
		return ;
	dup_redir = ft_dup_redir(m, m->cmd);
	if (m->ms->error == 0)
		ft_cmdex(m->cmd->tab, m->ev, m, dup_redir);
}

void	ft_cmdex(char **cmd, char **ev, t_pipex *m, int dup_redir)
{
	char	*error_type;

	ft_closefds(m);
	ft_closeoutin(m);
	ft_freefds(m);
	error_type = "command not found";
	if (m->cmd->i == -1)
		error_type = "Is a directory";
	if ((m->out_rok == 0 && (m->in_rok == 0 || m->in_rok == -2)) && cmd \
		&& m->cmd->i == 0 && dup_redir >= 0 && m->cmd->tab[0][0] != '\0'
		&& !(ft_isabuiltin(m->cmd->tab, m->ms, 1)) && m->ms->error == 0)
		execve(m->cmd->name, cmd, ev);
	if (m->cmd->i == 13)
		error_type = strerror(m->cmd->i);
	if ((m->ms->error == 0) && (m->cmd->tab[0][0] != '\0' || m->cmd->i != 0) \
		&& !(ft_isabuiltin(m->cmd->tab, m->ms, 0)))
		ft_error(cmd[0], error_type, 0, m);
	while (m->cmd)
	{
		if (m->cmd->i == 0 && m->cmd->tab[0][0] == '\0')
			free(m->cmd->tab[0]);
		m->cmd = m->cmd->next;
	}
	ft_exitchild(m, m->ms->status);
}

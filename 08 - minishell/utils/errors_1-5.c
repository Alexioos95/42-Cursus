/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_1-5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:25:41 by eewu              #+#    #+#             */
/*   Updated: 2023/09/20 16:25:50 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_errors_redir(t_pipex *m, t_redir *redir, int in_out, t_cmd_lst *cmd)
{
	char	*file;
	int		ambi;

	file = redir->token.file;
	ambi = redir->token.ambi;
	ft_close_file(cmd);
	if (in_out == 0 && ambi == 0)
	{
		m->in_rok = errno;
		ft_error(file, strerror(m->in_rok), (int)m->pids[m->count], m);
	}
	else if (in_out == 0 && ambi == 1)
		ft_error(file, "ambiguous redirection", (int)m->pids[m->count], m);
	else if (in_out == 1 && ambi == 0)
	{
		m->out_rok = errno;
		ft_error(file, strerror(m->out_rok), (int)m->pids[m->count], m);
	}
	else if (in_out == 1 && ambi == 1)
		ft_error(file, "ambiguous redirection", (int)m->pids[m->count], m);
}

void	ft_exitchild(t_pipex *m, int status_code)
{
	t_shell		*ms;

	ms = m->ms;
	ft_closefds(m);
	ft_freefds(m);
	ft_closeoutin(m);
	ft_lstclearpipex(&m->headplus);
	free(ms->tabenv);
	free (m);
	frees(ms, status_code);
}

void	ft_error(char *file, char *error, int pid, t_pipex *m)
{
	ft_dupcheck(2, 1, m);
	printf("minishell: %s: %s\n", file, error);
	if ((m->in_rok > 0 || m->out_rok > 0) && pid == 0)
	{
		while (m->cmd)
		{
			if (m->cmd->i == 0 && m->cmd->tab[0][0] == '\0')
				free(m->cmd->tab[0]);
			m->cmd = m->cmd->next;
		}
		ft_exitchild(m, 1);
	}
	else if ((m->cmd->i == 13) && pid == 0)
		ft_exitchild(m, 126);
	else if ((m->cmd->i > 0) && pid == 0)
		ft_exitchild(m, 127);
}

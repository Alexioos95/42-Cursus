/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_open.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:03:42 by eewu              #+#    #+#             */
/*   Updated: 2023/09/21 16:28:05 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_openin(t_pipex *m, t_redir *redir, t_cmd_lst *cmd)
{
	char	*token;
	char	*file;
	bool	bol;

	token = redir->token.token;
	file = redir->token.file;
	bol = (bool)redir->token.ambi;
	if (!token)
		m->in[0] = open("/dev/stdin", O_RDONLY);
	else if (token && !bol && (ft_strcmp(token, "<") || ft_strcmp(token, "<<")))
	{
		m->in[0] = open(file, O_RDONLY);
		if (m->in[0] >= 0)
			m->in_rok = -2;
	}
	if (bol)
		m->in[0] = -1;
	if (m->in[0] >= 0 && m->in_rok != -2)
		m->in_rok = 0;
	else if (m->in[0] == -1)
		ft_errors_redir(m, redir, 0, cmd);
	return (m->in[0]);
}

int	ft_openout(t_pipex *m, t_redir *redir, t_cmd_lst *cmd)
{
	char	*token;
	char	*file;
	int		bol;

	token = redir->token.token;
	file = redir->token.file;
	bol = (bool)redir->token.ambi;
	if (!token)
		m->out = open("/dev/stdout", O_WRONLY);
	else if (!bol && (ft_strcmp(token, ">") || ft_strcmp(token, ">>")))
	{
		if (ft_strcmp(token, ">"))
			m->out = open(file, O_WRONLY | O_TRUNC);
		else if (ft_strcmp(token, ">>"))
			m->out = open(file, O_WRONLY | O_APPEND);
		if (m->out == -1)
			m->out = open(file, O_WRONLY | O_CREAT, 0644);
		if (m->out >= 0)
			m->out_red = 1;
		else
			ft_errors_redir(m, redir, 1, cmd);
	}
	else if (bol)
		ft_errors_redir(m, redir, 1, cmd);
	return (m->out);
}

void	ft_dupcheck(int fd, int stdfd, t_pipex *m)
{
	if (dup2(fd, stdfd) == -1)
	{
		ft_free_process(m);
		ft_lstclearpipex(&m->headplus);
		m->ms->error = 1;
		free(m->ms->tabenv);
		throwerror(m->ms, "dup2");
	}
}

int	ft_open_redir(t_cmd_lst *cmd, t_pipex *m)
{
	char		*token;
	t_redir		*redir_tmp;
	int			i;

	i = 0;
	redir_tmp = cmd->redirlst;
	if (!cmd->fd)
		cmd->fd = malloc(sizeof(int) * ft_lstsize(redir_tmp));
	if (!cmd->fd)
		return (-1);
	while (i < ft_lstsize(redir_tmp))
		cmd->fd[i++] = 0;
	i = 0;
	while (redir_tmp)
	{
		token = redir_tmp->token.token;
		if (token && (ft_strcmp(token, "<") || ft_strcmp(token, "<<")))
			cmd->fd[i++] = ft_openin(m, redir_tmp, cmd);
		else if (token && (ft_strcmp(token, ">>") || ft_strcmp(token, ">")))
			cmd->fd[i++] = ft_openout(m, redir_tmp, cmd);
		redir_tmp = redir_tmp->next;
	}
	return (1);
}

int	ft_dup_redir(t_pipex *m, t_cmd_lst *cmd)
{
	t_cmd_lst	*tmp;
	int			i;

	tmp = cmd;
	if (!cmd)
		return (-1);
	m->bhole = open("/dev/null", O_WRONLY);
	if (m->bhole == -1)
	{
		m->ms->error = 1;
		return (-1);
	}
	i = ft_open_redir(tmp, m);
	if (m->in_rok > 0 || m->cmd->i != 0)
		ft_dupcheck(m->bhole, STDIN_FILENO, m);
	if (m->in[0] >= 0)
		ft_dupcheck(m->in[0], STDIN_FILENO, m);
	if (m->out >= 0)
		ft_dupcheck(m->out, STDOUT_FILENO, m);
	return (i);
}

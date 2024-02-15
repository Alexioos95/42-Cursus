/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parsing3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:43:32 by eewu              #+#    #+#             */
/*   Updated: 2023/09/22 09:38:54 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_exitprotection(t_shell *ms, char **tab, int in, int out)
{
	int	i;

	i = 0;
	if (ft_strncmp(tab[0], "exit", 4) == 0)
	{
		if (tab[1] != NULL && (tab[1][0] == '-' || tab[1][0] == '+'))
			i++;
		while (tab[1] != NULL && tab[1][i] != '\0' && tab[1][i] >= '0' \
			&& tab[1][i] <= '9')
			i++;
		if (tab[1] == NULL || (tab[1] != NULL && tab[2] == NULL) \
			|| (tab[1] != NULL && tab[1][i] != '\0'))
		{
			close(in);
			close(out);
			close(ms->pex->bhole);
		}
		if (tab[1] != NULL && tab[2] != NULL && tab[1][i] == '\0')
			return (0);
		return (1);
	}
	return (0);
}

void	ft_cmd_list(t_pipex *m, t_shell *ms)
{
	char	**tab;
	char	*name;
	t_lexer	*lexer;

	lexer = ms->lexer;
	name = NULL;
	while (lexer && ms->error == 0)
	{
		tab = ft_find_nodecmd(&lexer, ms);
		if (tab)
			ft_checkaccees(m, &lexer, tab);
		else if (!tab && ms->error == 0)
		{
			ft_fake_command(m, ms, tab, name);
			if (ms->error == 1)
				return ((void)free(tab));
		}
		if (lexer)
			lexer = lexer->next;
	}
	m->cmd_i = 0;
}

void	find_cmd(t_pipex *m, t_shell *ms)
{
	t_lst	*node_env;

	node_env = ft_getenv(ms, "PATH");
	if (node_env && node_env->print == 1)
	{
		m->s_ev = ft_split(&node_env->line[5], ':');
		if (m->s_ev == NULL)
			return ((void)free(ms->tabenv));
	}
	else
	{
		m->s_ev = ft_calloc(sizeof(char *), 2);
		if (!m->s_ev)
			return ((void)free(ms->tabenv));
		m->s_ev[0] = ft_calloc(sizeof(char), 1);
		if (!m->s_ev[0])
		{
			freesplit(m->s_ev);
			m->s_ev = NULL;
			return ((void)free(ms->tabenv));
		}
	}
	ft_cmd_list(m, ms);
	ft_redir_list(m, ms);
	freesplit(m->s_ev);
}

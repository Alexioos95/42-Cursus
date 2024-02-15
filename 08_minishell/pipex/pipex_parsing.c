/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:14:53 by eewu              #+#    #+#             */
/*   Updated: 2023/09/21 16:27:14 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	**ft_find_nodecmd(t_lexer **lexer, t_shell *ms)
{
	char	**tab;

	tab = NULL;
	while ((*lexer) && !((*lexer)->token.pipe) && ms->error == 0)
	{
		if ((*lexer)->tab)
		{
			tab = ft_realloc_tab(tab, (*lexer)->tab);
			if (!tab)
				ms->error = 1;
		}
		(*lexer) = (*lexer)->next;
	}
	return (tab);
}

int	ft_access_while(t_pipex *m, char **tab, int p)
{
	char	*name;
	int		j;

	j = 0;
	while ((m->s_ev[j] && p != 0 && (int)ft_strlen(tab[0]) >= 1) \
		&& m->eror != -1)
	{
		name = ft_pipex_join(m->s_ev[j++], tab[0]);
		if (access(name, X_OK) != 0)
			free(name);
		else
		{
			p = 0;
			ft_pipex_lstadd_back(&m->cmd, ft_pipex_lstnew(tab, name, p), m);
		}
	}
	return (p);
}

void	ft_access(t_pipex *m, char **tab, int p)
{
	char	*name;

	if (m->ms->error == 1)
		return ;
	if (p == 0 || (ft_isabuiltin(tab, m->ms, 0)))
	{
		name = ft_strdup(tab[0]);
		ft_pipex_lstadd_back(&m->cmd, ft_pipex_lstnew(tab, name, 0), m);
	}
	else
	{
		p = ft_access_while(m, tab, p);
		if (p != 0)
		{
			name = ft_strdup(tab[0]);
			ft_pipex_lstadd_back(&m->cmd, ft_pipex_lstnew(tab, name, p), m);
		}
	}
}

void	ft_checkaccees(t_pipex *m, t_lexer **lexer, char **tab)
{
	struct stat	dir;

	ft_memset(&dir, 0, sizeof(struct stat));
	if (tab[0] && (tab[0][0] == '.' || tab[0][0] == '/'))
	{
		if (lstat(tab[0], &dir) == -1 && errno == ENOMEM)
		{
			m->ms->error = 1;
			return ((void)ft_free_process(m));
		}
		if (!access(tab[0], X_OK))
			m->eror = 0;
		else
			m->eror = errno;
		if (S_ISDIR(dir.st_mode) || S_ISLNK(dir.st_mode))
			m->eror = -1;
	}
	else
		m->eror = 2;
	ft_access(m, tab, m->eror);
	while ((*lexer) && !((*lexer)->token.pipe))
		(*lexer) = (*lexer)->next;
}

void	ft_fake_command(t_pipex *m, t_shell *ms, char **tab, char *name)
{
	tab = ft_calloc (sizeof (char *), 2);
	if (!tab)
		return ;
	tab[0] = ft_calloc(sizeof(char), 1);
	if (!tab[0])
	{
		ms->error = 1;
		return ;
	}
	name = ft_strdup(tab[0]);
	if (name == NULL)
	{
		ms->error = 1;
		return ;
	}
	ft_pipex_lstadd_back(&m->cmd, ft_pipex_lstnew(tab, name, 0), m);
}

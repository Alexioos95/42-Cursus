/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:21:32 by apayen            #+#    #+#             */
/*   Updated: 2023/09/14 16:20:28 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_nb_cmd(t_lexer *lexer)
{
	int	i;

	i = 1;
	while (lexer)
	{
		if (lexer->token.pipe)
			i++;
		lexer = lexer->next;
	}
	return (i);
}

void	ft_lstadd_back(struct s_shell *ms, t_lst **lst, t_lst *new)
{
	struct s_lst	*last;

	if (new == NULL)
		throwerror(ms, "malloc");
	if ((*lst) == NULL)
	{
		(*lst) = new;
		return ;
	}
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

struct s_lst	*ft_lstnew(struct s_shell *ms, char *str)
{
	struct s_lst	*new;

	new = malloc(sizeof(struct s_lst));
	if (new == NULL)
		return (NULL);
	new->print = 1;
	new->line = str;
	new->next = NULL;
	new->ms = ms;
	return (new);
}

t_tokens	ft_newtoken(char *token, char *file)
{
	t_tokens	new;

	new.pipe = NULL;
	new.token = NULL;
	new.ambi = 0;
	if (ft_strcmp(token, "|"))
		new.pipe = token;
	else
		new.token = token;
	new.file = file;
	return (new);
}

// Initialise toutes les variables, et construit la liste chainee du env.
void	init(struct s_shell *ms, char **envp)
{
	ms->line = NULL;
	ms->pwdpath = NULL;
	ms->oldpwdpath = NULL;
	ms->env = NULL;
	ms->tmp = NULL;
	ms->status = 0;
	ms->error = 0;
	ms->hd = NULL;
	ms->pex = NULL;
	ms->lexer = NULL;
	ms->head = NULL;
	ft_memset(&ms->sigact[0], 0, sizeof(ms->sigact[0]));
	ms->sigact[0].sa_handler = SIG_DFL;
	ft_memset(&ms->sigact[1], 0, sizeof(ms->sigact[1]));
	ms->sigact[1].sa_handler = &ft_sigint;
	ft_memset(&ms->sigact[2], 0, sizeof(ms->sigact[2]));
	ms->sigact[2].sa_handler = &ft_sigint2;
	ft_memset(&ms->sigact[3], 0, sizeof(ms->sigact[3]));
	ms->sigact[3].sa_handler = &ft_sigint_heredoc;
	ft_memset(&ms->sigact[4], 0, sizeof(ms->sigact[4]));
	ms->sigact[4].sa_handler = SIG_IGN;
	ft_setenv(ms, envp);
}

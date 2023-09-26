/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:36:20 by apayen            #+#    #+#             */
/*   Updated: 2023/09/13 16:04:58 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_lstclear(struct s_lst *lst)
{
	struct s_lst	*tmp;

	if (lst == NULL)
		return ;
	while (lst != NULL)
	{
		tmp = lst->next;
		free(lst->line);
		free(lst);
		lst = tmp;
	}
}

void	ft_lexerclear(t_lexer *lexer)
{
	t_lexer		*tmp;

	if (lexer == NULL)
		return ;
	while (lexer)
	{
		tmp = lexer->next;
		if (lexer->str)
			free(lexer->str);
		if (lexer->tab)
			freesplit(lexer->tab);
		if (lexer->token.file)
		{
			if (ft_strcmp(lexer->token.token, "<<"))
				unlink(lexer->token.file);
			free(lexer->token.file);
		}
		if (lexer->token.token)
			free(lexer->token.token);
		if (lexer->token.pipe)
			free(lexer->token.pipe);
		free(lexer);
		lexer = tmp;
	}
}

// Free un tableau de split.
void	freesplit(char **strmalloc)
{
	int	i;

	i = 0;
	if (strmalloc == NULL)
		return ;
	while (strmalloc[i] != NULL)
	{
		free(strmalloc[i]);
		i++;
	}
	free(strmalloc);
}

// Free toutes les variables.
_Noreturn void	frees(struct s_shell *ms, int code)
{
	if (ms->head)
		ft_lexerclear(ms->head);
	if (ms->line != NULL)
		free(ms->line);
	if (ms->env != NULL)
		ft_lstclear(ms->env);
	if (ms->tmp != NULL)
		free(ms->tmp);
	if (ms->pwdpath != NULL)
		free(ms->pwdpath);
	if (ms->oldpwdpath != NULL)
		free(ms->oldpwdpath);
	if (ms->hd != NULL && ms->hd->backup >= 0)
		close(ms->hd->backup);
	rl_clear_history();
	exit(code);
}

_Noreturn void	throwerror(struct s_shell *ms, char *str)
{
	printf("minishell: %s: %s\n", str, strerror(errno));
	if (ms->pex != NULL)
		free(ms->pex);
	frees(ms, 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:40:00 by apayen            #+#    #+#             */
/*   Updated: 2023/09/18 15:27:45 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

// Hub de l'executeur. Il trie le parsing, et l'execute.
int	execution(struct s_shell *ms, struct s_lexer *lexer)
{
	ft_add_tokenword(lexer, ms);
	ft_add_word_to_tab(lexer, ms);
	if (ms->error == 1)
		return (1);
	ft_heredoc(lexer, ms);
	if (ms->status == -1)
	{
		ms->status = 130;
		return (1);
	}
	setsigaction(ms, 2);
	ft_expand(lexer, ms);
	if (ft_start(ms) == 1)
	{
		ms->error = 1;
		return (1);
	}
	return (0);
}

// Hub du parser, qui envoie le resultat dans l'executeur.
int	parser(struct s_shell *ms)
{
	t_lexer	*lexer;

	if (ms->line == NULL)
		return (0);
	if (checkorphans(ms->line) == 1)
		return (2);
	ft_browse(ms);
	if (ms->lexer && ms->error == 0)
	{
		lexer = ms->lexer;
		if (execution(ms, lexer) == 0)
		{
			ft_lstclearpipex(&ms->pex->headplus);
			free(ms->pex);
			ms->pex = NULL;
		}
	}
	ft_lexerclear(ms->head);
	ms->head = NULL;
	return (ms->status);
}

// Regarde pourquoi la line est a NULL, et agit en consequence.
void	nullonreadline(struct s_shell *ms)
{
	if (errno == ENOMEM)
		throwerror(ms, "readline");
	else
	{
		if (isatty(0) == 1)
			printf("exit\n");
		frees(ms, ms->status);
	}
}

// Boucle du shell.
// Lire une ligne > parser > executer.
_Noreturn void	loop(struct s_shell *ms)
{
	while (1)
	{
		setsigaction(ms, 1);
		if (ms->line != NULL)
			free(ms->line);
		if (isatty(0) == 1)
			ms->line = readline("apayen&eewu@minishell$ ");
		else
			ms->line = readline("");
		if (ms->line == NULL)
			nullonreadline(ms);
		if (ms->line[0] != '\0')
			add_history(ms->line);
		if (g_glob > 1)
			ms->status = 130;
		g_glob = 0;
		ms->status = parser(ms);
	}
}

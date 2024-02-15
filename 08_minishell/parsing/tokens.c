/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:21:57 by eewu              #+#    #+#             */
/*   Updated: 2023/09/19 09:43:45 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_goodtoken(t_shell *ms, char *line, t_tokens *token, char **word)
{
	int		i;
	int		state;
	char	c;
	char	*curr_token;

	i = 0;
	state = 0;
	c = line[i];
	while ((ft_istoken(line[i]) && state == 0) && line[i] && (c == line[i]))
		state = ft_state(line[++i], state);
	curr_token = ft_subnstr(line, 0, (size_t)i);
	if (!curr_token)
		ms->error = 1;
	*token = ft_newtoken(curr_token, NULL);
	*word = NULL;
	return (i);
}

int	ft_goodword(char *line, t_tokens *token, char **word, int state)
{
	int		i;

	i = 0;
	while ((!ft_istoken(line[i]) || state > 0) && line[i])
		state = ft_state(line[++i], state);
	*token = ft_newtoken(NULL, NULL);
	*word = ft_subnstr(line, 0, (size_t)i);
	return (i);
}

void	ft_add_tokenword(t_lexer *lexer, t_shell *ms)
{
	t_lexer	*tmp;

	while (lexer)
	{
		if (lexer->token.token && \
		(lexer->next && lexer->next->str && lexer->next->i != 0))
		{
			tmp = lexer->next->next;
			lexer->token.file = lexer->next->str;
			lexer->token.ambi = 0;
			lexer->next->str = NULL;
			free (lexer->next);
			lexer->next = tmp;
			lexer = tmp;
			ms->lexer->len--;
		}
		else
			lexer = lexer->next;
	}
}

void	ft_add_word_to_tab(t_lexer *lexer, t_shell *ms)
{
	int		nb_tab;
	t_lexer	*node_cmd;

	while (lexer && ms->error == 0)
	{
		node_cmd = lexer;
		nb_tab = 0;
		while (lexer && lexer->str)
		{
			nb_tab++;
			lexer = lexer->next;
		}
		if (nb_tab)
			ft_tabptr(ms, node_cmd, node_cmd, nb_tab);
		while (lexer && !lexer->str && ms->error == 0)
			lexer = lexer->next;
	}
}

void	ft_tabptr(t_shell *ms, t_lexer *node_cmd, t_lexer *tmp, int nb_tab)
{
	int			i;

	i = 0;
	(tmp) = node_cmd;
	(node_cmd)->tab = ft_calloc(sizeof (char *), (size_t)(nb_tab + 1));
	if (!(node_cmd)->tab)
	{
		ms->error = 1;
		return ;
	}
	(node_cmd)->tab[i++] = (tmp)->str;
	(tmp)->str = NULL;
	(tmp) = (tmp)->next;
	while (i < nb_tab && (tmp) && (tmp)->str)
		ft_lexer_delone((&tmp), i++);
	ms->lexer->len -= nb_tab - 1;
}

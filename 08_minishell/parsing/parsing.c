/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:53:38 by apayen            #+#    #+#             */
/*   Updated: 2023/09/14 16:21:32 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_state(char c, int state)
{
	if (c == '\"' && state <= 1)
		state = 2;
	else if (c == '\"' && state == 2)
		state = 0;
	else if (c == '\'' && state <= 1)
		state = 3;
	else if (c == '\'' && state == 3)
		state = 0;
	return (state);
}

int	ft_istoken(char c)
{
	int		i;
	char	*tokens;

	tokens = "<>|&";
	i = 0;
	while (tokens[i])
	{
		if (tokens[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_isthereatoken(char *line, t_lexer **lexer, t_shell *ms)
{
	int			i;
	int			s;
	t_tokens	token;
	char		*word;

	i = 0;
	word = NULL;
	s = ft_state(line[i], 0);
	if (ft_istoken(line[i]) && s == 0)
		i = ft_goodtoken(ms, line, &token, &word);
	else if (!ft_istoken(line[i]) || ft_state(line[i], s) > 0)
	{
		i = ft_goodword(line, &token, &word, s);
		if (!word)
			ms->error = 1;
	}
	if (0 != i && (word || token.token || token.pipe))
		ft_lexer_addback(lexer, ft_lexer_new(word, token), ms);
	return (i);
}

void	ft_browse(t_shell *ms)
{
	int			i;
	int			n;
	t_lexer		*lexer;
	char		**split;

	i = 0;
	lexer = NULL;
	split = ft_split(ms->line, ' ');
	if (!split)
	{
		ms->error = 1;
		return ;
	}
	while (split[i])
	{
		n = 0;
		while (n != ft_strlen(split[i]) && ms->error == 0)
			n += ft_isthereatoken(&split[i][n], &lexer, ms);
		if (ms->error == 1)
			break ;
		i++;
	}
	freesplit (split);
	ms->lexer = lexer;
}

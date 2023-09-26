/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dquote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:42:43 by marvin            #+#    #+#             */
/*   Updated: 2023/09/04 14:35:42 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_expand_ambiguous(struct s_expand *exp, char *str)
{
	int	i;

	i = 0;
	if (str != NULL && str[0] == '$')
	{
		while (isexp(exp, str, i, i + 1) == 0)
			i++;
		if (str[i + 1] == '\0')
			return (1);
	}
	return (0);
}

// Remplace la str donnee commencant par $, et la remplace par son
// equivalent dans le env, pour une str originale entre double quotes.
void	ft_expand_dquotereplace(struct s_expand *exp)
{
	int	len;

	if (ft_strncmp(exp->tmp, "$?", 2) == 0)
	{
		free(exp->tmp);
		exp->tmp = ft_itoa(exp->ms->status);
		if (exp->tmp == NULL)
			ft_expand_error(exp);
		return ;
	}
	len = ft_strlen(&exp->tmp[1]);
	if (len == 0)
		return ;
	exp->node = ft_getenv(exp->ms, &exp->tmp[1]);
	if (exp->node == NULL || exp->node->print != 1)
		exp->tmp[0] = '\0';
	else
	{
		free(exp->tmp);
		exp->tmp = ft_strdup(&exp->node->line[len + 1]);
		if (exp->tmp == NULL)
			ft_expand_error(exp);
	}
}

// Routine pour la str donnee.
void	ft_expand_dquote(struct s_expand *exp, char *str)
{
	exp->i = 0;
	exp->c = '\0';
	while (str[exp->i] != '\0')
	{
		exp->j = exp->i;
		while (str[exp->i] != '\0' && str[exp->i] != '$')
			exp->i++;
		if (str[exp->i] == '\0' || exp->i != exp->j)
			exp->buff = ft_expand_join(exp, exp->buff, \
				ft_substr(str, exp->j, exp->i - exp->j));
		else
		{
			while (isexp(exp, str, exp->i, exp->j + 1) == 0)
				exp->j++;
			exp->tmp = ft_substr(str, exp->i, exp->j - exp->i + 1);
			if (exp->tmp == NULL)
				ft_expand_error(exp);
			ft_expand_dquotereplace(exp);
			exp->buff = ft_expand_join(exp, exp->buff, exp->tmp);
			exp->i = exp->j + 1;
		}
	}
	free(exp->split[0]);
}

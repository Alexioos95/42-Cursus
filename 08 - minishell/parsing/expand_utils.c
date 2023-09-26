/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:41:57 by marvin            #+#    #+#             */
/*   Updated: 2023/09/19 14:26:09 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

// Free toutes les variables de l'expand,
// et appelle la fonction d'erreur critique generale.
void	ft_expand_error(struct s_expand *exp)
{
	if (exp->split[0] != NULL)
		free(exp->split[0]);
	if (exp->split[1] != NULL)
		free(exp->split[1]);
	if (exp->split[2] != NULL)
		free(exp->split[2]);
	if (exp->buff != NULL)
		free(exp->buff);
	if (exp->tmp != NULL)
		free(exp->tmp);
	if (exp->hd != NULL && exp->hd->name != NULL)
	{
		unlink(exp->hd->name);
		free(exp->hd->line);
	}
	throwerror(exp->ms, "malloc");
}

// Join 2 str les free.
char	*ft_expand_join(struct s_expand *exp, char *s1, char *s2)
{
	char	*half;

	if (s2 == NULL)
		ft_expand_error(exp);
	half = ft_strjoin(s1, s2);
	if (half == NULL)
		ft_expand_error(exp);
	free(s1);
	free(s2);
	return (half);
}

// Return 1 si le char est alpha-numerique.
int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') \
		|| (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

// Regarde si l'index i de la str est arrive a l'expand suivant.
int	isexp(struct s_expand *exp, char *str, int i, int j)
{
	if (str[i] == '$' \
		&& (str[i + 1] == '?' || (str[i + 1] >= '0' && str[i + 1] <= '9')))
	{
		exp->j++;
		return (1);
	}
	if (str[j] != '_' && ft_isalnum(str[j]) == 0)
		return (1);
	return (0);
}

// Initialise les variables necessaires.
void	ft_expand_initstruct(struct s_expand *exp, t_shell *ms, t_lexer *lex)
{
	if (ft_expand_ambiguous(exp, lex->token.file) == 1)
	{
		lex->token.ambi = 1;
		return ;
	}
	exp->split[0] = NULL;
	exp->split[1] = NULL;
	exp->split[2] = NULL;
	exp->tmp = NULL;
	exp->i = 0;
	exp->j = 0;
	exp->c = '\0';
	exp->node = NULL;
	exp->ms = ms;
	exp->hd = NULL;
	exp->buff = malloc(sizeof(char) * 1);
	if (exp->buff == NULL)
		ft_expand_error(exp);
	exp->buff[0] = '\0';
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:06:46 by apayen            #+#    #+#             */
/*   Updated: 2023/09/11 15:31:04 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

// Initialise les variables pour l'expand du heredoc.
void	ft_expheredoc_init(struct s_expand *exp, char *str)
{
	if (exp->i != exp->j)
		exp->buff = ft_expand_join(exp, exp->buff, ft_substr(str, exp->j, \
			exp->i - exp->j));
	exp->j = exp->i;
	while (isexp(exp, str, exp->i, exp->j + 1) == 0)
		exp->j++;
	exp->split[0] = ft_substr(str, exp->i, exp->j - exp->i + 1);
	if (exp->split[0] == NULL)
		ft_expand_error(exp);
}

// Expand les variables d'environnements des lignes heredoc.
char	*ft_heredoc_expand(struct s_heredoc *hd, char *str)
{
	struct s_expand	exp;

	ft_expand_initstruct(&exp, hd->ms, hd->ms->lexer);
	exp.hd = hd;
	exp.i = 0;
	while (str[exp.i] != '\0')
	{
		exp.j = exp.i;
		while (str[exp.i] != '\0' && str[exp.i] != '$')
			exp.i++;
		if (str[exp.i] == '\0')
		{
			exp.split[1] = ft_substr(str, exp.j, ft_strlen(&str[exp.j]) + 1);
			if (exp.split[1] == NULL)
				ft_expand_error(&exp);
			exp.buff = ft_expand_join(&exp, exp.buff, exp.split[1]);
			free(str);
			return (exp.buff);
		}
		ft_expheredoc_init(&exp, str);
		ft_expand_dollar(&exp, exp.split[0]);
		exp.i = exp.j + 1;
	}
	free(str);
	return (exp.buff);
}

// Créer un fichier avec un nom aléatoire.
void	ft_heredoc_filename(struct s_shell *ms, char *str)
{
	int		i;
	int		fd;

	fd = open("/dev/random", O_RDONLY);
	if (fd == -1)
	{
		free(str);
		throwerror(ms, "open");
	}
	read(fd, str, 14);
	i = 1;
	str[0] = '.';
	while (i < 15)
	{
		str[i] = (str[i] % 25) + 'a';
		i++;
	}
	str[i] = '.';
	str[16] = 't';
	str[17] = 'm';
	str[18] = 'p';
	str[19] = '\0';
	close(fd);
}

// Modifie la str pour enlever les (d)quotes.
int	ft_heredoc_quotes(char *str, int i, int len)
{
	int		j;
	int		ret;
	char	c;

	c = str[i];
	while (str[i] != '\0' && str[i + 1] != c)
	{
		str[i] = str[i + 1];
		i++;
	}
	ret = i;
	j = i + 1;
	while (str[j] != '\0')
	{
		str[i] = str[j + 1];
		i++;
		j++;
	}
	while (j < len)
	{
		str[j] = '\0';
		j++;
	}
	return (ret - 1);
}

// Retire les (d)quotes du délimiteur.
int	ft_heredoc_delim(char *str)
{
	int		i;
	int		len;
	int		state;

	i = 0;
	state = 0;
	len = ft_strlen(str);
	while (str[i] != '\0')
	{
		if (str[i] == '"' || str[i] == '\'')
		{
			state = 1;
			i = ft_heredoc_quotes(str, i, len);
		}
		i++;
	}
	return (state);
}

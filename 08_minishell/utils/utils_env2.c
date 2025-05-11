/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:32:20 by apayen            #+#    #+#             */
/*   Updated: 2023/09/12 17:32:48 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	countvalablenodes(struct s_lst *lst)
{
	int				i;
	struct s_lst	*tmp;

	i = 0;
	tmp = lst;
	while (tmp != NULL)
	{
		if (tmp->print == 1)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

char	**listtotab(struct s_shell *ms)
{
	int				i;
	int				len;
	struct s_lst	*tmp;
	char			**tab;

	i = 0;
	len = countvalablenodes(ms->env);
	tab = malloc(sizeof(char *) * ((unsigned long)len + 1));
	if (tab == NULL)
		throwerror(ms, "malloc");
	tmp = ms->env;
	while (tmp != NULL)
	{
		if (tmp->print == 1)
		{
			tab[i] = tmp->line;
			i++;
		}
		tmp = tmp->next;
	}
	tab[i] = NULL;
	return (tab);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s3;
	unsigned char	*s4;

	s3 = (unsigned char *)s1;
	s4 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (s3[i] != '\0' && s4[i] != '\0' && s3[i] == s4[i] && i < n - 1)
		i++;
	return (s3[i] - s4[i]);
}

char	*ft_subnstr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	n;
	char	*str;

	i = 0;
	if (!s || ((size_t)start == len))
		return (0);
	if ((int)start >= ft_strlen(s))
		n = 0;
	else
		n = (size_t)ft_strlen(&s[start]);
	if (n > len)
		n = len;
	str = malloc(sizeof(char) * (n + 1));
	if (!str)
		return (0);
	while (i < n)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

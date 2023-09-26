/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:05:22 by apayen            #+#    #+#             */
/*   Updated: 2023/09/20 09:57:06 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

// Strjoin legerement modifie pour include le char c entre les 2 str.
char	*ft_strjoinenv(char *s1, char c, char *s2)
{
	int		i;
	int		j;
	char	*strmalloc;

	i = 0;
	j = 0;
	strmalloc = malloc(sizeof(char) * (unsigned long)ft_strlen(s1) \
		+ (unsigned long)ft_strlen(s2) + 2);
	if (strmalloc == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		strmalloc[i] = s1[i];
		i++;
	}
	if (c != '\0')
		strmalloc[i] = c;
	while (s2[j] != '\0')
	{
		strmalloc[i + j + 1] = s2[j];
		j++;
	}
	strmalloc[i + j + 1] = '\0';
	return (strmalloc);
}

char	*ft_itoa(int nb)
{
	int				tmp;
	int				len;
	char			*str;

	len = 1;
	tmp = nb;
	while (tmp > 9)
	{
		tmp = tmp / 10;
		len++;
	}
	str = malloc(sizeof(char) * ((unsigned long)len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = nb % 10 + '0';
		nb = nb / 10;
		len--;
	}
	return (str);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*strmalloc;

	i = 0;
	if (start >= ft_strlen(s) || len == -1)
	{
		strmalloc = malloc(sizeof(char) * 1);
		strmalloc[0] = '\0';
		return (strmalloc);
	}
	if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	strmalloc = malloc(sizeof(char) * (unsigned long)len + 1);
	if (strmalloc == NULL)
		return (NULL);
	while (s[i] != '\0' && i < len)
	{
		strmalloc[i] = s[start];
		i++;
		start++;
	}
	strmalloc[i] = '\0';
	return (strmalloc);
}

// strnstr legerement modifie, qui return l'adresse de la str au int equal.
char	*ft_strnstr(char *big, char *little, int equal)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (big == NULL || little == NULL)
		return (NULL);
	if (little[j] == '\0')
		return ((char *)big);
	while (big[i] != '\0')
	{
		j = 0;
		while (big[i + j] == little[j] && little[j] != '\0')
		{
			j++;
			if (little[j] == '\0' && i == 0 && big[i + j] == '=')
				return ((char *)&big[i + (unsigned long)equal]);
		}
		i++;
	}
	return (NULL);
}

// Parcours la liste chainee, et return le node qui correspond a la str.
struct s_lst	*ft_getenv(struct s_shell *ms, char *str)
{
	struct s_lst	*tmp;

	tmp = ms->env;
	while (tmp != NULL && tmp->line != NULL)
	{
		if (ft_strnstr(tmp->line, str, 0) != NULL)
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}

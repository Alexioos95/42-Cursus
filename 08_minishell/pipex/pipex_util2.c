/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_util2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:07:57 by eewu              #+#    #+#             */
/*   Updated: 2023/09/20 17:19:15 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*ft_pipex_strlcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_pipex_strlcat(char *dest, const char *src, int size)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[size + i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_pipex_join(char *path, char *cmd)
{
	size_t	len_path;
	size_t	len_buf;
	char	*join;

	len_path = 0;
	len_buf = 0;
	if (path)
		len_path = (size_t)ft_strlen(path) + 1;
	if (cmd)
		len_buf = (size_t)ft_strlen(cmd);
	join = ft_calloc(sizeof(char), (len_path + len_buf + 1));
	if (!join)
		return (join);
	if (path)
		ft_pipex_strlcpy(join, path);
	ft_pipex_strlcat(join, "/", (int)(len_path - 1));
	if (cmd)
		ft_pipex_strlcat(join, cmd, (int)len_path);
	return (join);
}

char	**ft_realloc_tab(char **tab, char **curr_tab)
{
	char	**res;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (tab && tab[j])
		j++;
	while (curr_tab && curr_tab[k])
		k++;
	res = ft_calloc (sizeof(char *), (size_t)(j + k + 1));
	if (!res)
		return (NULL);
	j = 0;
	k = 0;
	while (tab && tab[j])
		res[i++] = tab[j++];
	while (curr_tab && curr_tab[k])
		res[i++] = curr_tab[k++];
	free (tab);
	return (res);
}

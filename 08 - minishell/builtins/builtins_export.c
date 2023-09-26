/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:03:43 by apayen            #+#    #+#             */
/*   Updated: 2023/09/01 14:07:00 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

// Creer une nouvelle node, l'ajoute a la liste, et set sa str.
int	ft_export_newnode(struct s_shell *ms, char *str)
{
	struct s_lst	*new;

	new = ft_lstnew(ms, NULL);
	if (new == NULL)
		throwerror(ms, "malloc");
	new->line = ft_strdup(str);
	if (new->line == NULL)
	{
		printf("minishell: malloc: %s\n", strerror(errno));
		free(new);
		frees(ms, 1);
	}
	ft_lstadd_back(ms, &ms->env, new);
	return (0);
}

// Remplace la str de la node correspondant a la variable,
// et change son flag d'unset.
int	ft_export_oldnode(struct s_lst *node, char *str)
{
	free(node->line);
	node->line = ft_substr(str, 0, ft_strlen(str));
	if (node->line == NULL)
	{
		printf("minishell: malloc: %s\n", strerror(errno));
		frees(node->ms, 1);
	}
	node->print = 1;
	return (0);
}

// Cherche une node correspondant a la variable.
// Si elle existe, modifie la str, sinon, la creer.
int	ft_export_refreshenv(struct s_shell *ms, char *str, int equal)
{
	char			*new;
	struct s_lst	*node;

	new = ft_substr(str, 0, equal);
	if (new == NULL)
		throwerror(ms, "malloc");
	node = ft_getenv(ms, new);
	free(new);
	if (node == NULL)
		ft_export_newnode(ms, str);
	else
		ft_export_oldnode(node, str);
	if (ft_strncmp(str, "OLDPWD=", 8) == 0 && ms->oldpwdpath != NULL)
	{
		free(ms->oldpwdpath);
		ms->oldpwdpath = NULL;
	}
	return (0);
}

// Ajoute la str a la liste chainee d'env.
// Si une node correspond au nom de la variable,
// je remplace la str de la node plutot que d'en creer une nouvelle.
int	ft_export(struct s_shell *ms, char **tab)
{
	int				i;
	int				isvalid;

	i = 1;
	while (tab[i] != NULL)
	{
		i++;
		isvalid = ft_export_parsing(tab[i - 1]);
		if (isvalid == 0)
		{
			if (tab[i] == NULL)
				return (1);
			continue ;
		}
		ft_export_refreshenv(ms, tab[i - 1], isvalid);
	}
	return (0);
}

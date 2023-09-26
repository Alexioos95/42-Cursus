/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:32:17 by apayen            #+#    #+#             */
/*   Updated: 2023/09/20 11:53:15 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

// cd au chemin set dans le HOME du env.
int	ft_cd_home(struct s_shell *ms, char *tmp)
{
	struct s_lst	*node;

	node = ft_getenv(ms, "HOME");
	if (node == NULL || node->print == 0 || node->line == NULL)
	{
		free(tmp);
		printf("minishell: cd: HOME not set\n");
		return (1);
	}
	if (node->line[5] == '\0')
		return (0);
	if (chdir(&node->line[5]) == -1)
	{
		free(tmp);
		if (errno == ENOMEM)
			throwerror(ms, "cd");
		printf("minishell: chdir: %s: %s\n", &node->line[5], strerror(errno));
		return (1);
	}
	ft_cd_actualizeenv(ms, tmp);
	ft_cd_actualizepwd(ms);
	return (0);
}

// cd au chemin set dans le OLDPWD du env.
int	ft_cd_oldpwd(struct s_shell *ms, char *tmp, int b)
{
	struct s_lst	*node;

	node = ft_getenv(ms, "OLDPWD");
	if (node == NULL || node->print != 1 || node->line[7] == '\0')
	{
		free(tmp);
		printf("minishell: cd: OLDPWD not set\n");
		return (1);
	}
	if (chdir(&ms->oldpwdpath[7]) == -1)
	{
		free(tmp);
		if (errno == ENOMEM)
			throwerror(ms, "cd");
		printf("minishell: cd: %s: %s\n", &ms->oldpwdpath[7], strerror(errno));
		return (1);
	}
	if (b == 0)
		printf("%s\n", &ms->oldpwdpath[7]);
	ft_cd_actualizeenv(ms, tmp);
	ft_cd_actualizepwd(ms);
	return (0);
}

// cd au chemin donnee en parametre.
int	ft_cd_nothome(struct s_shell *ms, char *str, char *tmp)
{
	if (chdir(str) == -1)
	{
		free(tmp);
		if (errno == ENOMEM)
			throwerror(ms, "cd");
		printf("minishell: cd: %s: %s\n", str, strerror(errno));
		return (1);
	}
	ft_cd_actualizeenv(ms, tmp);
	ft_cd_actualizepwd(ms);
	return (0);
}

// Change le working directory, et actualise le env.
int	ft_cd(struct s_shell *ms, char **tab)
{
	char	*tmp;

	if (tab[1] != NULL && tab[2] != NULL)
		return ((void)printf("minishell: cd: too many arguments\n"), 1);
	tmp = getcwd(NULL, 0);
	if (tmp == NULL)
	{
		tmp = ft_cd_proteccwd(ms, tab, tmp);
		if (tmp == NULL)
			return (1);
	}
	if (tmp[0] == '\0' && ft_strncmp(tab[1], "..", 2) == 0)
		return (ft_cd_removedparent(ms, tab, tmp));
	else
	{
		if (tab[1] == NULL && ft_cd_home(ms, tmp) == 1)
			return (1);
		else if (tab[1] != NULL && ft_strncmp(tab[1], "-", 2) == 0)
			return (ft_cd_oldpwd(ms, tmp, 0));
		else if (tab[1] != NULL && ft_strncmp(tab[1], "-", 2) != 0)
			return (ft_cd_nothome(ms, tab[1], tmp));
	}
	return (0);
}

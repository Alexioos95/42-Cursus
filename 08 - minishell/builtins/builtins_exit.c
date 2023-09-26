/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:39:05 by apayen            #+#    #+#             */
/*   Updated: 2023/09/22 09:33:41 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

// Free ce qu'il reste du pipex avant l'execution de l'exit.
void	ft_exit_free(struct s_shell *ms)
{
	free(ms->pex->pids);
	ft_lstclearpipex(&ms->pex->headplus);
	free(ms->pex);
	free(ms->tabenv);
}

// Verifie que le tableau ne contient que des chiffres.
void	ft_exit_checktab(struct s_shell *ms, char *str, int i)
{
	int	b;

	b = 0;
	ft_atoi(str, &b);
	if (b == 1 || ((str[0] == '-' || str[0] == '+') && str[1] == '\0'))
	{
		printf("minishell: exit: %s: numeric argument required\n", str);
		ft_exit_free(ms);
		frees(ms, 2);
	}
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			printf("minishell: exit: %s: numeric argument required\n", str);
			ft_exit_free(ms);
			frees(ms, 2);
		}
		i++;
	}
}

// Quitter proprement le programme.
int	ft_exit(struct s_shell *ms, char **tab)
{
	int	i;
	int	status;

	i = 0;
	printf("exit\n");
	if (tab[1] == NULL)
	{
		ft_exit_free(ms);
		frees(ms, ms->status);
	}
	if (tab[1][0] == '-' || tab[1][0] == '+')
		i++;
	ft_exit_checktab(ms, tab[1], i);
	if (tab[2] != NULL)
	{
		printf("minishell: exit: too many arguments\n");
		return (1);
	}
	status = (int)ft_atoi(tab[1], &i);
	ft_exit_free(ms);
	frees(ms, status);
	return (0);
}

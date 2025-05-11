/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:58:01 by eewu              #+#    #+#             */
/*   Updated: 2023/09/18 16:57:32 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../header.h"

// void	print_allcmd(t_pipex *m)
// {
// 	int			j;
// 	int			k;
// 	t_cmd_lst	*tmp;
// 	t_redir		*red;

// 	k = 0;
// 	tmp = m->head;
// 	while (tmp)
// 	{
// 		j = 0;
// 		while (tmp->tab && tmp->tab[j])
// 		{
// 			dprintf(2, "tab[%d][%d]:%s Bool[%d]\n", k, j, tmp->tab[j], tmp->i);
// 			j++;
// 		}
// 		red = tmp->redirlst;
// 		while (red)
// 		{
// 			dprintf(2, "Dir: %s\nFile: %s\n", red->token.token, red->token.file);
// 			red = red->next;
// 		}
// 		tmp = tmp->next;
// 		k++;
// 	}
// 	printf("Nb_cmd: %d\n", m->nb_cmd);
// }

// void	print_list(char *tab, int i)
// {
// 	printf("Tab[%d]: %s\n", i, tab);
// }

// void	print_tab(char **tab)
// {
// 	int	i;

// 	i = 0;
// 	while (tab[i])
// 	{
// 		printf("Tab[%d]: %s\n", i, tab[i]);
// 		i++;
// 	}
// }

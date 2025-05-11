/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:48:23 by eewu              #+#    #+#             */
/*   Updated: 2023/09/21 10:49:50 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_cmd_lst	*ft_pipex_lstnew(char **cmd, char *name, int i)
{
	t_cmd_lst	*new;

	new = malloc(sizeof(t_cmd_lst));
	if (!new)
	{
		free(name);
		return (0);
	}
	new->tab = cmd;
	new->name = name;
	new->redirlst = NULL;
	new->i = i;
	new->fd = NULL;
	new->next = NULL;
	return (new);
}

t_cmd_lst	*ft_lstlast(t_cmd_lst *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_pipex_lstadd_back(t_cmd_lst **lst, t_cmd_lst *new, t_pipex *m)
{
	t_cmd_lst	*last;

	if (new == NULL)
	{
		m->ms->error = 1;
		return ;
	}
	if (*lst == NULL)
	{
		*lst = new;
		m->head = *lst;
		m->headplus = *lst;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

void	ft_lstclearpipex(t_cmd_lst **lst)
{
	t_cmd_lst	*exec;
	t_redir		*redir;

	if (!(*lst))
		return ;
	while (*lst)
	{
		exec = (*lst)->next;
		free((*lst)->tab);
		free((*lst)->name);
		if ((*lst)->fd)
			free((*lst)->fd);
		while ((*lst)->redirlst)
		{
			redir = (*lst)->redirlst->next;
			free((*lst)->redirlst);
			(*lst)->redirlst = redir;
		}
		free((*lst));
		(*lst) = exec;
	}
}

int	ft_lstsize(t_redir *lst)
{
	int		i;
	t_redir	*tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

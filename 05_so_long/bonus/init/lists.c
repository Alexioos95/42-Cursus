/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:56:44 by apayen            #+#    #+#             */
/*   Updated: 2023/02/21 15:42:01 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	setenemycolor(struct s_mlx *game, struct s_enemy *lst, int nb)
{
	if (nb % 4 == 3)
	{
		lst->color = 'O';
		lst->icolor = 3;
		lst->cur = game->tabenemy[3][1];
	}
	else if (nb % 4 == 2)
	{
		lst->color = 'P';
		lst->icolor = 2;
		lst->cur = game->tabenemy[2][3];
	}
	else if (nb % 4 == 1)
	{
		lst->color = 'B';
		lst->icolor = 1;
		lst->cur = game->tabenemy[1][1];
	}
	else
	{
		lst->color = 'R';
		lst->icolor = 0;
		lst->cur = game->tabenemy[0][5];
	}
	lst->tmp = 1;
}

struct s_enemy	*initnode(struct s_enemy *new)
{
	new->dir = '0';
	new->color = '0';
	new->icolor = 0;
	new->cur = NULL;
	new->tmp = 0;
	new->ytarget = 0;
	new->xtarget = 0;
	new->delay = 0;
	new->spriteframe = 0;
	new->animframe = 0;
	new->algolock = 0;
	new->panic = 0;
	new->blink = 0;
	new->idle = 0;
	return (new);
}

struct s_enemy	*ft_lstnew(struct s_mlx *game, int nb, int x, int y)
{
	struct s_enemy	*new;

	new = malloc(sizeof(struct s_enemy));
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	new->nb = nb;
	new->startxpos = x;
	new->startypos = y;
	new->xpos = x;
	new->ypos = y;
	new = initnode(new);
	setenemycolor(game, new, nb);
	setenemytarget(game, new);
	return (new);
}

void	ft_lstadd_back(struct s_enemy **lst, struct s_enemy *new)
{
	struct s_enemy	*tmp;

	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	ft_lstclear(struct s_enemy **lst)
{
	struct s_enemy	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	lst = NULL;
}

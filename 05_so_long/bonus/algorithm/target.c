/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:03:46 by apayen            #+#    #+#             */
/*   Updated: 2023/02/23 14:50:21 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	avoidhouse(struct s_mlx *game)
{
	if (game->enemy->ypos < game->height - 3 \
		&& game->enemy->xpos < game->width - 3 && game->enemy->xpos > 3 \
		&& game->map[game->enemy->ypos + 1][game->enemy->xpos] == 'E' \
		&& game->map[game->enemy->ypos + 1][game->enemy->xpos - 1] == '1' \
		&& game->map[game->enemy->ypos + 1][game->enemy->xpos - 2] == '1' \
		&& game->map[game->enemy->ypos + 1][game->enemy->xpos - 3] == '1' \
		&& game->map[game->enemy->ypos + 1][game->enemy->xpos + 1] == '1' \
		&& game->map[game->enemy->ypos + 1][game->enemy->xpos + 2] == '1' \
		&& game->map[game->enemy->ypos + 1][game->enemy->xpos + 3] == '1' \
		&& game->map[game->enemy->ypos + 2][game->enemy->xpos] == '0' \
		&& game->map[game->enemy->ypos + 2][game->enemy->xpos - 3] == '1' \
		&& game->map[game->enemy->ypos + 2][game->enemy->xpos + 3] == '1' \
		&& game->map[game->enemy->ypos + 3][game->enemy->xpos] == '1' \
		&& game->map[game->enemy->ypos + 3][game->enemy->xpos - 1] == '1' \
		&& game->map[game->enemy->ypos + 3][game->enemy->xpos - 2] == '1' \
		&& game->map[game->enemy->ypos + 3][game->enemy->xpos - 3] == '1' \
		&& game->map[game->enemy->ypos + 3][game->enemy->xpos + 1] == '1' \
		&& game->map[game->enemy->ypos + 3][game->enemy->xpos + 2] == '1' \
		&& game->map[game->enemy->ypos + 3][game->enemy->xpos + 3] == '1')
		return (1);
	return (0);
}

void	predictplayer(struct s_mlx *game, struct s_enemy *lst)
{
	if (lst->color == 'P')
	{
		if (game->dir == 'L')
		{
			lst->ytarget = game->pypos;
			lst->xtarget = game->pxpos - 4;
		}
		else if (game->dir == 'R')
		{
			lst->ytarget = game->pypos;
			lst->xtarget = game->pxpos + 4;
		}
		else if (game->dir == 'U')
		{
			lst->ytarget = game->pypos - 4;
			lst->xtarget = game->pxpos;
		}
		else if (game->dir == 'D')
		{
			lst->ytarget = game->pypos + 4;
			lst->xtarget = game->pxpos;
		}
	}
}

void	randomtarget(struct s_mlx *game, struct s_enemy *lst)
{
	int	y;
	int	x;

	y = rand();
	x = rand();
	while (y > game->height - 1)
		y /= 10;
	lst->ytarget = y;
	while (x > game->width - 1)
		x /= 10;
	lst->xtarget = x;
}

void	followenemy(struct s_mlx *game, struct s_enemy *lst)
{
	struct s_enemy	*tmp;
	int				redy;
	int				redx;

	tmp = game->enemy;
	game->enemy = game->lsthead;
	redy = game->enemy->ypos;
	redx = game->enemy->xpos;
	game->enemy = tmp;
	lst->ytarget = (game->pypos * 2 + 1) - redy;
	lst->xtarget = (game->pxpos * 2 - 1) - redx;
}

void	setenemytarget(struct s_mlx *game, struct s_enemy *lst)
{
	if (lst->idle >= 1)
	{
		lst->ytarget = lst->ypos + 1;
		lst->xtarget = lst->xpos;
		lst->idle++;
		if (lst->idle >= 30)
			lst->idle = 0;
	}
	else if (lst->panic >= 1)
		randomtarget(game, lst);
	else if (lst->color == 'R')
	{
		lst->ytarget = game->pypos;
		lst->xtarget = game->pxpos;
	}
	else if (lst->color == 'B')
		followenemy(game, lst);
	else if (lst->color == 'O')
		randomtarget(game, lst);
	else
		predictplayer(game, lst);
}

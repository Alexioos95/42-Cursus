/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 09:31:54 by apayen            #+#    #+#             */
/*   Updated: 2023/02/22 16:42:05 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	movetoup(struct s_mlx *game)
{
	game->fct = NULL;
	if (game->map[game->pypos - 1][game->pxpos] == '1')
		return ;
	else
	{
		if (game->map[game->pypos][game->pxpos] != 'E')
			game->map[game->pypos][game->pxpos] = '0';
		if (game->dir != 'U')
		{
			game->dir = 'U';
			game->animframe = 0;
			game->nblock = 0;
			placetextures(game);
			game->nbmove++;
		}
	}
}

void	movetodown(struct s_mlx *game)
{
	game->fct = NULL;
	if (game->map[game->pypos + 1][game->pxpos] == '1')
		return ;
	else
	{
		if (game->map[game->pypos][game->pxpos] != 'E')
			game->map[game->pypos][game->pxpos] = '0';
		if (game->dir != 'D')
		{
			game->dir = 'D';
			game->animframe = 0;
			game->nblock = 0;
			placetextures(game);
			game->nbmove++;
		}
	}
}

void	movetoleft(struct s_mlx *game)
{
	game->fct = NULL;
	if (game->map[game->pypos][game->pxpos - 1] == '1')
		return ;
	else
	{
		if (game->map[game->pypos][game->pxpos] != 'E')
			game->map[game->pypos][game->pxpos] = '0';
		if (game->dir != 'L')
		{
			game->dir = 'L';
			game->animframe = 0;
			game->nblock = 0;
			placetextures(game);
			game->nbmove++;
		}
	}
}

void	movetoright(struct s_mlx *game)
{
	game->fct = NULL;
	if (game->map[game->pypos][game->pxpos + 1] == '1')
		return ;
	else
	{
		if (game->map[game->pypos][game->pxpos] != 'E')
			game->map[game->pypos][game->pxpos] = '0';
		if (game->dir != 'R')
		{
			game->dir = 'R';
			game->animframe = 0;
			game->nblock = 0;
			placetextures(game);
			game->nbmove++;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 09:31:54 by apayen            #+#    #+#             */
/*   Updated: 2023/02/13 16:08:41 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	gg(struct s_mlx *game)
{
	freeall(game, 5);
	game->nbmove++;
	exit(0);
}

void	movetoright(struct s_mlx *game)
{
	if (game->map[game->pypos][game->pxpos + 1] == '1')
		return ;
	else if (game->map[game->pypos][game->pxpos + 1] == 'E' && game->c > 0)
		return ;
	else if (game->map[game->pypos][game->pxpos + 1] == 'E' && game->c == 0)
		gg(game);
	else
	{
		game->map[game->pypos][game->pxpos] = '0';
		if (game->map[game->pypos][game->pxpos + 1] == 'C')
			game->c--;
		game->map[game->pypos][game->pxpos + 1] = 'P';
		game->pxpos++;
		placetextures(game);
		game->nbmove++;
		ft_printf("Number of moves : %d\n", game->nbmove);
	}
}

void	movetoleft(struct s_mlx *game)
{
	if (game->map[game->pypos][game->pxpos - 1] == '1')
		return ;
	else if (game->map[game->pypos][game->pxpos - 1] == 'E' && game->c > 0)
		return ;
	else if (game->map[game->pypos][game->pxpos - 1] == 'E' && game->c == 0)
		gg(game);
	else
	{
		game->map[game->pypos][game->pxpos] = '0';
		if (game->map[game->pypos][game->pxpos - 1] == 'C')
			game->c--;
		game->map[game->pypos][game->pxpos - 1] = 'P';
		game->pxpos--;
		placetextures(game);
		game->nbmove++;
		ft_printf("Number of moves : %d\n", game->nbmove);
	}
}

void	movetoup(struct s_mlx *game)
{
	if (game->map[game->pypos - 1][game->pxpos] == '1')
		return ;
	else if (game->map[game->pypos - 1][game->pxpos] == 'E' && game->c > 0)
		return ;
	else if (game->map[game->pypos - 1][game->pxpos] == 'E' && game->c == 0)
		gg(game);
	else
	{
		game->map[game->pypos][game->pxpos] = '0';
		if (game->map[game->pypos - 1][game->pxpos] == 'C')
			game->c--;
		game->map[game->pypos - 1][game->pxpos] = 'P';
		game->pypos--;
		placetextures(game);
		game->nbmove++;
		ft_printf("Number of moves : %d\n", game->nbmove);
	}
}

void	movetodown(struct s_mlx *game)
{
	if (game->map[game->pypos + 1][game->pxpos] == '1')
		return ;
	else if (game->map[game->pypos + 1][game->pxpos] == 'E' && game->c > 0)
		return ;
	else if (game->map[game->pypos + 1][game->pxpos] == 'E' && game->c == 0)
		gg(game);
	else
	{
		game->map[game->pypos][game->pxpos] = '0';
		if (game->map[game->pypos + 1][game->pxpos] == 'C')
			game->c--;
		game->map[game->pypos + 1][game->pxpos] = 'P';
		game->pypos++;
		placetextures(game);
		game->nbmove++;
		ft_printf("Number of moves : %d\n", game->nbmove);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:20:23 by apayen            #+#    #+#             */
/*   Updated: 2023/02/17 09:56:59 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	sprite2(struct s_mlx *game)
{
	if (game->dir == 'U')
		game->playercur = game->playerup2;
	else if (game->dir == 'D')
		game->playercur = game->playerdown2;
	else if (game->dir == 'L')
		game->playercur = game->playerleft2;
	else if (game->dir == 'R')
		game->playercur = game->playerright2;
	game->playertmp = game->playerright2;
}

void	sprite1(struct s_mlx *game)
{
	if (game->dir == 'U')
		game->playercur = game->playerup1;
	else if (game->dir == 'D')
		game->playercur = game->playerdown1;
	else if (game->dir == 'L')
		game->playercur = game->playerleft1;
	else if (game->dir == 'R')
		game->playercur = game->playerright1;
	game->playertmp = game->playerright1;
}

void	changespriteplayer(struct s_mlx *game)
{
	game->spriteframe++;
	if (game->playertmp == game->player0 && game->spriteframe >= 6000)
		sprite1(game);
	else if (game->playertmp == game->playerright1 && \
		game->spriteframe >= 11000)
		sprite2(game);
	else if (game->playertmp == game->playerright2 && \
		game->spriteframe >= 18000)
	{
		game->playercur = game->player0;
		game->playertmp = game->player0;
		game->spriteframe = 0;
	}
}

void	player(struct s_mlx *game)
{
	changespriteplayer(game);
	if (game->map[game->pypos][game->pxpos] == 'E' && game->c == 0)
		gg(game);
	if (game->dir == 'U' && \
				game->map[game->pypos - 1][game->pxpos] != '1')
		animup(game);
	else if (game->dir == 'D' && \
				game->map[game->pypos + 1][game->pxpos] != '1')
		animdown(game);
	else if (game->dir == 'L' && \
				game->map[game->pypos][game->pxpos - 1] != '1')
		animleft(game);
	else if (game->dir == 'R' && \
		game->map[game->pypos][game->pxpos + 1] != '1')
		animright(game);
}

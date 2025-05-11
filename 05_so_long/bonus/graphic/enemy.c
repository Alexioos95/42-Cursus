/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:09:07 by apayen            #+#    #+#             */
/*   Updated: 2023/02/22 14:09:08 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	spriteenemy2(struct s_mlx *game)
{
	int	i;

	i = 0;
	while (i < game->enemy->icolor)
		i++;
	if (game->enemy->dir == 'U')
		game->enemy->cur = game->tabenemy[i][0];
	else if (game->enemy->dir == 'D')
		game->enemy->cur = game->tabenemy[i][2];
	else if (game->enemy->dir == 'L')
		game->enemy->cur = game->tabenemy[i][4];
	else if (game->enemy->dir == 'R')
		game->enemy->cur = game->tabenemy[i][6];
	game->enemy->tmp = 0;
}

void	spriteenemy1(struct s_mlx *game)
{
	int	i;

	i = 0;
	while (i < game->enemy->icolor)
		i++;
	if (game->enemy->dir == 'U')
		game->enemy->cur = game->tabenemy[i][1];
	else if (game->enemy->dir == 'D')
		game->enemy->cur = game->tabenemy[i][3];
	else if (game->enemy->dir == 'L')
		game->enemy->cur = game->tabenemy[i][5];
	else if (game->enemy->dir == 'R')
		game->enemy->cur = game->tabenemy[i][7];
	game->enemy->tmp = 0;
}

void	changespriteenemy(struct s_mlx *game)
{
	while (game->enemy)
	{
		game->enemy->spriteframe++;
		if (game->enemy->panic == 0)
		{
			if (game->enemy->tmp == 1 && game->enemy->spriteframe >= 8000)
				spriteenemy1(game);
			else if (game->enemy->tmp == 0 && game->enemy->spriteframe >= 14000)
			{
				spriteenemy2(game);
				game->enemy->tmp = 1;
				game->enemy->spriteframe = 0;
			}
		}
		else
			spriteenemypanic(game);
		game->enemy = game->enemy->next;
	}
	game->enemy = game->lsthead;
}

void	moveenemy(struct s_mlx *game)
{
	if (game->enemy->dir == 'U' \
		&& game->map[game->enemy->ypos - 1][game->enemy->xpos] != '1')
		animenemyup(game);
	else if (game->enemy->dir == 'D' \
		&& game->map[game->enemy->ypos + 1][game->enemy->xpos] != '1')
		animenemydown(game);
	else if (game->enemy->dir == 'L' \
		&& game->map[game->enemy->ypos][game->enemy->xpos - 1] != '1')
		animenemyleft(game);
	else if (game->enemy->dir == 'R' \
		&& game->map[game->enemy->ypos][game->enemy->xpos + 1] != '1')
		animenemyright(game);
}

void	enemy(struct s_mlx *game)
{
	changespriteenemy(game);
	while (game->enemy)
	{
		if (game->enemy->algolock == 0)
			algorithm(game);
		moveenemy(game);
		if (game->enemy->ypos == game->pypos \
			&& game->enemy->xpos == game->pxpos && game->enemy->panic >= 1)
		{
			placetextures(game);
			game->enemy->panic = 0;
			game->enemy->cur = game->tabenemy[game->enemy->icolor][0];
			game->enemy->ypos = game->enemy->startypos;
			game->enemy->xpos = game->enemy->startxpos;
			if (avoidhouse(game) == 1)
				game->enemy->ypos = game->enemy->startypos + 2;
			game->enemy->idle = 1;
			game->enemy->algolock = 0;
		}
		else if (game->enemy->ypos == game->pypos \
			&& game->enemy->xpos == game->pxpos && game->enemy->panic == 0)
			game->alive = 0;
		game->enemy = game->enemy->next;
	}
	game->enemy = game->lsthead;
}

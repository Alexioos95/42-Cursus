/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:14:01 by apayen            #+#    #+#             */
/*   Updated: 2023/02/21 15:43:59 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	panicmode(struct s_mlx *game)
{
	game->panic = 1;
	while (game->enemy)
	{
		if (game->enemy->panic == 0)
		{
			if (game->enemy->dir == 'U')
				game->enemy->dir = 'D';
			else if (game->enemy->dir == 'D')
				game->enemy->dir = 'U';
			else if (game->enemy->dir == 'L')
				game->enemy->dir = 'R';
			else if (game->enemy->dir == 'R')
				game->enemy->dir = 'L';
		}
		game->enemy->delay = 0;
		game->enemy->spriteframe = 0;
		game->enemy->animframe = 0;
		game->enemy->algolock = 0;
		game->enemy->panic = 1;
		game->enemy->blink = 0;
		game->enemy->idle = 0;
		placetextures(game);
		game->enemy = game->enemy->next;
	}
	game->enemy = game->lsthead;
}

void	spritepanic2(struct s_mlx *game)
{
	if (game->enemy->cur == game->tabpanic[1] \
		|| (game->enemy->cur == game->tabpanic[3] \
		&& game->enemy->spriteframe >= 8000))
		game->enemy->cur = game->tabpanic[2];
	else if (game->enemy->cur == game->tabpanic[2] \
		&& game->enemy->spriteframe >= 14000)
	{
		game->enemy->cur = game->tabpanic[3];
		game->enemy->spriteframe = 0;
	}
	else if (game->enemy->panic >= 520000 && game->enemy->blink < 8)
	{
		game->enemy->panic = 480000;
		game->enemy->blink++;
	}
	else if (game->enemy->blink >= 4)
	{
		game->enemy->blink = 0;
		game->enemy->panic = -1;
		game->panic = 0;
	}
}

void	spritepanic1(struct s_mlx *game)
{
	if ((game->enemy->cur != game->tabpanic[0] \
		&& game->enemy->cur != game->tabpanic[1]) \
		|| (game->enemy->cur == game->tabpanic[1] \
		&& game->enemy->spriteframe >= 8000))
		game->enemy->cur = game->tabpanic[0];
	else if (game->enemy->cur == game->tabpanic[0] \
		&& game->enemy->spriteframe >= 14000)
	{
		game->enemy->cur = game->tabpanic[1];
		game->enemy->spriteframe = 0;
	}
}

void	spriteenemypanic(struct s_mlx *game)
{
	if (game->enemy->panic < 500000 || (game->enemy->panic >= 500000 \
		&& game->enemy->cur == game->tabpanic[0]))
		spritepanic1(game);
	else
		spritepanic2(game);
	game->enemy->panic++;
	game->enemy->spriteframe++;
}

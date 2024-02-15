/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animenemy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:58:35 by apayen            #+#    #+#             */
/*   Updated: 2023/02/22 11:47:30 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	animenemy(struct s_mlx *game, int x, int y)
{
	if ((game->enemy->panic == 0 && game->enemy->delay >= 495) \
		|| (game->enemy->panic >= 1 && game->enemy->delay >= 750))
	{
		mlx_put_image_to_window(game->mlx, game->window, game->enemy->cur, \
			x, y);
		game->enemy->animframe++;
		game->enemy->delay = 0;
	}
}

void	animenemyup(struct s_mlx *game)
{
	if ((game->enemy->panic == 0 && game->enemy->delay >= 495) \
		|| (game->enemy->panic >= 1 && game->enemy->delay >= 750))
		animenemy(game, (game->enemy->xpos * PX), \
			((game->enemy->ypos * PX) - game->enemy->animframe));
	game->enemy->delay++;
	if (game->enemy->animframe == PX)
	{
		game->enemy->ypos--;
		if (game->map[game->enemy->ypos + 1][game->enemy->xpos] == 'C')
			mlx_put_image_to_window(game->mlx, game->window, game->collectible, \
				(game->enemy->xpos * PX), ((game->enemy->ypos + 1) * PX));
		if (game->map[game->enemy->ypos + 1][game->enemy->xpos] == '@')
			mlx_put_image_to_window(game->mlx, game->window, \
			game->scollectible, (game->enemy->xpos * PX), \
			((game->enemy->ypos + 1) * PX));
		if (game->map[game->enemy->ypos + 1][game->enemy->xpos] == 'E')
			mlx_put_image_to_window(game->mlx, game->window, game->exit, \
				(game->enemy->xpos * PX), ((game->enemy->ypos + 1) * PX));
		game->enemy->algolock = 0;
		game->enemy->animframe = 0;
	}
}

void	animenemydown(struct s_mlx *game)
{
	if ((game->enemy->panic == 0 && game->enemy->delay >= 495) \
		|| (game->enemy->panic >= 1 && game->enemy->delay >= 750))
		animenemy(game, (game->enemy->xpos * PX), \
			((game->enemy->ypos * PX) + game->enemy->animframe));
	game->enemy->delay++;
	if (game->enemy->animframe == PX)
	{
		game->enemy->ypos++;
		if (game->map[game->enemy->ypos - 1][game->enemy->xpos] == 'C')
			mlx_put_image_to_window(game->mlx, game->window, game->collectible, \
				(game->enemy->xpos * PX), ((game->enemy->ypos - 1) * PX));
		if (game->map[game->enemy->ypos - 1][game->enemy->xpos] == '@')
			mlx_put_image_to_window(game->mlx, game->window, \
			game->scollectible, (game->enemy->xpos * PX), \
			((game->enemy->ypos - 1) * PX));
		if (game->map[game->enemy->ypos - 1][game->enemy->xpos] == 'E')
			mlx_put_image_to_window(game->mlx, game->window, game->exit, \
				(game->enemy->xpos * PX), ((game->enemy->ypos - 1) * PX));
		game->enemy->algolock = 0;
		game->enemy->animframe = 0;
	}
}

void	animenemyleft(struct s_mlx *game)
{
	if ((game->enemy->panic == 0 && game->enemy->delay >= 495) \
		|| (game->enemy->panic >= 1 && game->enemy->delay >= 750))
		animenemy(game, ((game->enemy->xpos * PX) - game->enemy->animframe), \
			(game->enemy->ypos * PX));
	game->enemy->delay++;
	if (game->enemy->animframe == PX)
	{
		game->enemy->xpos--;
		if (game->map[game->enemy->ypos][game->enemy->xpos + 1] == 'C')
			mlx_put_image_to_window(game->mlx, game->window, game->collectible, \
				((game->enemy->xpos + 1) * PX), (game->enemy->ypos * PX));
		if (game->map[game->enemy->ypos][game->enemy->xpos + 1] == '@')
			mlx_put_image_to_window(game->mlx, game->window, \
			game->scollectible, ((game->enemy->xpos + 1) * PX), \
			(game->enemy->ypos * PX));
		if (game->map[game->enemy->ypos][game->enemy->xpos + 1] == 'E')
			mlx_put_image_to_window(game->mlx, game->window, game->exit, \
				((game->enemy->xpos + 1) * PX), (game->enemy->ypos * PX));
		teleporting(game, &game->enemy->ypos, &game->enemy->xpos);
		game->enemy->algolock = 0;
		game->enemy->animframe = 0;
	}
}

void	animenemyright(struct s_mlx *game)
{
	if ((game->enemy->panic == 0 && game->enemy->delay >= 495) \
		|| (game->enemy->panic >= 1 && game->enemy->delay >= 750))
		animenemy(game, ((game->enemy->xpos * PX) + game->enemy->animframe), \
			(game->enemy->ypos * PX));
	game->enemy->delay++;
	if (game->enemy->animframe == PX)
	{
		game->enemy->xpos++;
		if (game->map[game->enemy->ypos][game->enemy->xpos - 1] == 'C')
			mlx_put_image_to_window(game->mlx, game->window, game->collectible, \
				((game->enemy->xpos - 1) * PX), (game->enemy->ypos * PX));
		if (game->map[game->enemy->ypos][game->enemy->xpos - 1] == '@')
			mlx_put_image_to_window(game->mlx, game->window, \
			game->scollectible, ((game->enemy->xpos - 1) * PX), \
			(game->enemy->ypos * PX));
		if (game->map[game->enemy->ypos][game->enemy->xpos - 1] == 'E')
			mlx_put_image_to_window(game->mlx, game->window, game->exit, \
				((game->enemy->xpos - 1) * PX), (game->enemy->ypos * PX));
		teleporting(game, &game->enemy->ypos, &game->enemy->xpos);
		game->enemy->algolock = 0;
		game->enemy->animframe = 0;
	}
}

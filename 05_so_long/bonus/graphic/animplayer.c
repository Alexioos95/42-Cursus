/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animplayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:41:26 by apayen            #+#    #+#             */
/*   Updated: 2023/02/22 16:41:27 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	anim(struct s_mlx *game, int x, int y)
{
	if (game->delay >= 450)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->playercur, \
			x, y);
		game->animframe++;
		game->delay = 0;
	}
}

void	animup(struct s_mlx *game)
{
	if (game->delay >= 450)
		anim(game, (game->pxpos * PX), ((game->pypos * PX) - game->animframe));
	game->delay++;
	if (game->animframe == PX - 1)
	{
		game->pypos--;
		if (game->map[game->pypos][game->pxpos] == 'C' \
			|| game->map[game->pypos][game->pxpos] == '@')
			game->c--;
		if (game->map[game->pypos][game->pxpos] == '@')
			panicmode(game);
		if (game->map[game->pypos][game->pxpos] != 'E')
			game->map[game->pypos][game->pxpos] = '0';
		if (game->map[game->pypos + 1][game->pxpos] == 'E')
			mlx_put_image_to_window(game->mlx, game->window, game->exit, \
				(game->pxpos * PX), ((game->pypos + 1) * PX));
		while (game->animframe <= PX)
		{
			mlx_put_image_to_window(game->mlx, game->window, game->playercur, \
				(game->pxpos * PX), ((game->pypos + 1) * PX - game->animframe));
			game->animframe++;
		}
		game->animframe = 0;
	}
}

void	animdown(struct s_mlx *game)
{
	if (game->delay >= 450)
		anim(game, (game->pxpos * PX), ((game->pypos * PX) + game->animframe));
	game->delay++;
	if (game->animframe == PX - 1)
	{
		game->pypos++;
		if (game->map[game->pypos][game->pxpos] == 'C' \
			|| game->map[game->pypos][game->pxpos] == '@')
			game->c--;
		if (game->map[game->pypos][game->pxpos] == '@')
			panicmode(game);
		if (game->map[game->pypos][game->pxpos] != 'E')
			game->map[game->pypos][game->pxpos] = '0';
		if (game->map[game->pypos - 1][game->pxpos] == 'E')
			mlx_put_image_to_window(game->mlx, game->window, game->exit, \
				(game->pxpos * PX), ((game->pypos - 1) * PX));
		while (game->animframe <= PX)
		{
			mlx_put_image_to_window(game->mlx, game->window, game->playercur, \
				(game->pxpos * PX), ((game->pypos - 1) * PX + game->animframe));
			game->animframe++;
		}
		game->animframe = 0;
	}
}

void	animleft(struct s_mlx *game)
{
	if (game->delay >= 450)
		anim(game, ((game->pxpos * PX) - game->animframe), (game->pypos * PX));
	game->delay++;
	if (game->animframe == PX - 1)
	{
		game->pxpos--;
		if (game->map[game->pypos][game->pxpos] == 'C' \
			|| game->map[game->pypos][game->pxpos] == '@')
			game->c--;
		if (game->map[game->pypos][game->pxpos] == '@')
			panicmode(game);
		if (game->map[game->pypos][game->pxpos] != 'E')
			game->map[game->pypos][game->pxpos] = '0';
		if (game->map[game->pypos][game->pxpos + 1] == 'E')
			mlx_put_image_to_window(game->mlx, game->window, game->exit, \
				((game->pxpos + 1) * PX), (game->pypos * PX));
		while (game->animframe <= PX)
		{
			mlx_put_image_to_window(game->mlx, game->window, game->playercur, \
				(((game->pxpos + 1) * PX) - game->animframe), game->pypos * PX);
			game->animframe++;
		}
		teleporting(game, &game->pypos, &game->pxpos);
		game->animframe = 0;
	}
}

void	animright(struct s_mlx *game)
{
	if (game->delay >= 450)
		anim(game, ((game->pxpos * PX) + game->animframe), (game->pypos * PX));
	game->delay++;
	if (game->animframe == PX - 1)
	{
		game->pxpos++;
		if (game->map[game->pypos][game->pxpos] == 'C' \
			|| game->map[game->pypos][game->pxpos] == '@')
			game->c--;
		if (game->map[game->pypos][game->pxpos] == '@')
			panicmode(game);
		if (game->map[game->pypos][game->pxpos] != 'E')
			game->map[game->pypos][game->pxpos] = '0';
		if (game->map[game->pypos][game->pxpos - 1] == 'E')
			mlx_put_image_to_window(game->mlx, game->window, game->exit, \
				((game->pxpos - 1) * PX), (game->pypos * PX));
		while (game->animframe <= PX)
		{
			mlx_put_image_to_window(game->mlx, game->window, game->playercur, \
				(((game->pxpos - 1) * PX) + game->animframe), game->pypos * PX);
			game->animframe++;
		}
		teleporting(game, &game->pypos, &game->pxpos);
		game->animframe = 0;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:30:55 by apayen            #+#    #+#             */
/*   Updated: 2023/02/27 09:21:43 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	refresh(struct s_mlx *game)
{
	if (game->alive == 1)
	{
		if (game->fct != NULL)
		{
			if ((game->fct == &movetoup \
				&& game->map[game->pypos - 1][game->pxpos] != '1') \
				|| (game->fct == &movetodown \
				&& game->map[game->pypos + 1][game->pxpos] != '1') \
				|| (game->fct == &movetoleft \
				&& game->map[game->pypos][game->pxpos - 1] != '1') \
				|| (game->fct == &movetoright \
				&& game->map[game->pypos][game->pxpos + 1] != '1'))
			{
				game->fct(game);
				game->fct = NULL;
			}
		}
		player(game);
		score(game);
		enemy(game);
	}
	else
		death(game);
	return (0);
}

void	controls2(int keycode, struct s_mlx *game)
{
	if (keycode == XK_Right || keycode == XK_d || keycode == XK_D)
	{
		if (game->alive == 1 && game->map[game->pypos][game->pxpos + 1] != '1')
			movetoright(game);
		else
			game->fct = &movetoright;
	}
	else if (keycode == XK_Left || keycode == XK_a || keycode == XK_A)
	{
		if (game->alive == 1 && game->map[game->pypos][game->pxpos - 1] != '1')
			movetoleft(game);
		else
			game->fct = &movetoleft;
	}
}

int	controls(int keycode, struct s_mlx *game)
{
	if (game->alive == 1 && (keycode == XK_Escape \
		|| keycode == XK_q || keycode == XK_Q))
		mlx_loop_end(game->mlx);
	else if (keycode == XK_Up || keycode == XK_w || keycode == XK_W)
	{
		if (game->alive == 1 && game->map[game->pypos - 1][game->pxpos] != '1')
			movetoup(game);
		else
			game->fct = &movetoup;
	}
	else if (keycode == XK_Down || keycode == XK_s || keycode == XK_S)
	{
		if (game->alive == 1 && game->map[game->pypos + 1][game->pxpos] != '1')
			movetodown(game);
		else
			game->fct = &movetodown;
	}
	else if (keycode == XK_r || keycode == XK_R)
		reinit(game);
	else
		controls2(keycode, game);
	return (0);
}

int	main(int argc, char **argv)
{
	struct s_mlx	game;

	if (argc != 2)
		return (errors(argc, 0), -1);
	if (parsing(&game, argv[1]) == 1)
		return (-1);
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		return (freemaps(&game), errors(argc, 'M'), -1);
	game.window = mlx_new_window(game.mlx, \
		(game.width * PX), (game.height * PX + 120), "./so_long");
	if (game.window == NULL)
		return (freemaps(&game), mlx_destroy_display(game.mlx), \
		free(game.mlx), errors(argc, 'M'), -1);
	initgamestruct(&game);
	placetextures(&game);
	printenemy(&game);
	mlx_put_image_to_window(game.mlx, game.window, game.logo, \
		((game.width * (PX / 2)) - (game.k / 2)), (game.height * PX + 30));
	mlx_hook(game.window, 2, (1L << 0), controls, &game);
	mlx_hook(game.window, 17, 0, mlx_loop_end, game.mlx);
	mlx_loop_hook(game.mlx, refresh, &game);
	mlx_loop(game.mlx);
	freeall(&game);
}

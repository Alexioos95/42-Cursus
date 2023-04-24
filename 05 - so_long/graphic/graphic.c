/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:17:26 by apayen            #+#    #+#             */
/*   Updated: 2023/03/01 11:54:55 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	controls(int keycode, struct s_mlx *game)
{
	if (keycode == XK_Escape)
		mlx_loop_end(game->mlx);
	else if (keycode == XK_Right)
		movetoright(game);
	else if (keycode == XK_Left)
		movetoleft(game);
	else if (keycode == XK_Up)
		movetoup(game);
	else if (keycode == XK_Down)
		movetodown(game);
	return (0);
}

void	placeswitch(struct s_mlx *game, int y, int x)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->wall, \
			(x * PX), (y * PX));
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->window, game->floor, \
			(x * PX), (y * PX));
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->window, game->collectible, \
			(x * PX), (y * PX));
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->window, game->player, \
			(x * PX), (y * PX));
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->exit, \
			(x * PX), (y * PX));
}

void	placetextures(struct s_mlx *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y] != NULL)
	{
		x = 0;
		while (game->map[y][x] != '\0')
		{
			placeswitch(game, y, x);
			x++;
		}
		y++;
	}
}

int	initgamestruct(struct s_mlx *game)
{
	game->nbmove = 0;
	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", \
			&game->i, &game->j);
	if (game->wall == NULL)
		return (freeall(game, 0), errors(2, '!'), 1);
	game->floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", \
			&game->i, &game->j);
	if (game->floor == NULL)
		return (freeall(game, 1), errors(2, '!'), 1);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"textures/pac_closed.xpm", &game->i, &game->j);
	if (game->player == NULL)
		return (freeall(game, 2), errors(2, '!'), 1);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/portal.xpm", \
			&game->i, &game->j);
	if (game->exit == NULL)
		return (freeall(game, 3), errors(2, '!'), 1);
	game->collectible = mlx_xpm_file_to_image(game->mlx, \
			"textures/pacgum.xpm", &game->i, &game->j);
	if (game->collectible == NULL)
		return (freeall(game, 4), errors(2, '!'), 1);
	return (0);
}

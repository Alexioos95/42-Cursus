/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teleporting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:44:04 by apayen            #+#    #+#             */
/*   Updated: 2023/02/17 11:33:08 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	tptoleft(struct s_mlx *game, int *y, int *x)
{
	if (game->map[*y - 1][*x] == '1' && game->map[*y + 1][*x] == '1' \
		&& game->map[*y + 2][*x] == '1' && game->map[*y - 2][*x] == '1' \
		&& game->map[*y - 1][1] == '1' && game->map[*y + 1][1] == '1' \
		&& game->map[*y - 2][1] == '1' && game->map[*y + 2][1] == '1')
	{
		mlx_put_image_to_window(game->mlx, game->window, game->floor, \
			(*x * PX), (*y * PX));
		if (game->map[*y][*x] == 'E')
			mlx_put_image_to_window(game->mlx, game->window, game->exit, \
				(*x * PX), (*y * PX));
		*x = 1;
	}
}

void	tptoright(struct s_mlx *game, int *y, int *x)
{
	if (game->map[*y - 1][*x] == '1' && game->map[*y + 1][*x] == '1' \
		&& game->map[*y + 2][*x] == '1' && game->map[*y - 2][*x] == '1' \
		&& game->map[*y - 1][game->width - 2] == '1' \
		&& game->map[*y + 1][game->width - 2] == '1' \
		&& game->map[*y + 2][game->width - 2] == '1' \
		&& game->map[*y - 2][game->width - 2] == '1')
	{
		mlx_put_image_to_window(game->mlx, game->window, game->floor, \
			(*x * PX), (*y * PX));
		if (game->map[*y][*x] == 'E')
			mlx_put_image_to_window(game->mlx, game->window, game->exit, \
				(*x * PX), (*y * PX));
		*x = game->width - 2;
	}
}

void	teleporting(struct s_mlx *game, int *y, int *x)
{
	if (game->map[game->pypos][game->pxpos] == 'E' && game->c == 0)
		gg(game);
	if (*y > 1)
	{
		if (*x == 1 && game->map[*y][game->width - 2] != '1')
			tptoright(game, y, x);
		else if (*x == game->width - 2 && game->map[*y][1] != '1')
			tptoleft(game, y, x);
	}
}

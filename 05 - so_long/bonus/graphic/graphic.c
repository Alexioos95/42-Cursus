/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:17:26 by apayen            #+#    #+#             */
/*   Updated: 2023/02/22 14:06:34 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	gg(struct s_mlx *game)
{
	ft_printf("\n*** Congratulations ! ***\n*** Total moves : %d ***\n\n",
		game->nbmove);
	freeall(game);
	exit(0);
}

void	death(struct s_mlx *game)
{
	int	i;

	i = game->deathi;
	if (game->deathdelay >= 5000)
	{
		placetextures(game);
		mlx_put_image_to_window(game->mlx, game->window, game->tabdeath[i], \
			(game->pxpos * PX), (game->pypos * PX));
		game->deathdelay = 0;
		game->deathi++;
	}
	game->deathdelay++;
	if (game->deathi == 12)
	{
		ft_printf("\n*** GAME OVER ! ***\n\n");
		freeall(game);
		exit(0);
	}
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
	else if (game->map[y][x] == '@')
		mlx_put_image_to_window(game->mlx, game->window, game->scollectible, \
			(x * PX), (y * PX));
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->window, game->playercur, \
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
	mlx_put_image_to_window(game->mlx, game->window, game->playercur, \
			(game->pxpos * PX), (game->pypos * PX));
}

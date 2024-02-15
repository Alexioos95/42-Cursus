/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:59:28 by apayen            #+#    #+#             */
/*   Updated: 2023/02/27 09:23:31 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freemlx(struct s_mlx *game)
{
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

void	freemaps(struct s_mlx *game)
{
	int	y;

	y = 0;
	while (game->map[y] != NULL)
	{
		free(game->map[y]);
		y++;
	}
	free(game->map);
	y = 0;
	while (game->mapclone[y] != NULL)
	{
		free(game->mapclone[y]);
		y++;
	}
	free(game->mapclone);
}

void	freeimages(struct s_mlx *game, int i)
{
	if (i > 0)
		mlx_destroy_image(game->mlx, game->wall);
	if (i > 1)
		mlx_destroy_image(game->mlx, game->floor);
	if (i > 2)
		mlx_destroy_image(game->mlx, game->player);
	if (i > 3)
		mlx_destroy_image(game->mlx, game->exit);
	if (i > 4)
		mlx_destroy_image(game->mlx, game->collectible);
	mlx_clear_window(game->mlx, game->window);
	mlx_destroy_window(game->mlx, game->window);
}

void	freeall(struct s_mlx *game, int i)
{
	freemaps(game);
	freeimages(game, i);
	freemlx(game);
}

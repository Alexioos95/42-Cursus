/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:59:28 by apayen            #+#    #+#             */
/*   Updated: 2023/02/21 13:59:43 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	freeimages(struct s_mlx *game)
{
	if (game->wall != NULL)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->floor != NULL)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->exit != NULL)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->collectible != NULL)
		mlx_destroy_image(game->mlx, game->collectible);
	if (game->scollectible != NULL)
		mlx_destroy_image(game->mlx, game->scollectible);
	if (game->logo != NULL)
		mlx_destroy_image(game->mlx, game->logo);
	freeplayer(game);
	freescore(game);
	freepanic(game);
	mlx_clear_window(game->mlx, game->window);
	mlx_destroy_window(game->mlx, game->window);
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

void	freeall(struct s_mlx *game)
{
	freemaps(game);
	freeimages(game);
	ft_lstclear(&game->enemy);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

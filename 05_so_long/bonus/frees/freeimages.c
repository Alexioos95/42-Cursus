/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeimages.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:55:30 by apayen            #+#    #+#             */
/*   Updated: 2023/02/21 14:03:35 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	freepanic(struct s_mlx *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		if (game->tabpanic[i] != NULL)
			mlx_destroy_image(game->mlx, game->tabpanic[i]);
		j = 0;
		while (j < 8)
		{
			if (game->tabenemy[i][j] != NULL)
				mlx_destroy_image(game->mlx, game->tabenemy[i][j]);
			j++;
		}
		i++;
	}
}

void	freescore(struct s_mlx *game)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (game->tabscore[i] != NULL)
			mlx_destroy_image(game->mlx, game->tabscore[i]);
		i++;
	}
}

void	freedeath(struct s_mlx *game)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		if (game->tabdeath[i] != NULL)
			mlx_destroy_image(game->mlx, game->tabdeath[i]);
		i++;
	}
}

void	freeplayer(struct s_mlx *game)
{
	if (game->player0 != NULL)
		mlx_destroy_image(game->mlx, game->player0);
	if (game->playerup1 != NULL)
		mlx_destroy_image(game->mlx, game->playerup1);
	if (game->playerup2 != NULL)
		mlx_destroy_image(game->mlx, game->playerup2);
	if (game->playerdown1 != NULL)
		mlx_destroy_image(game->mlx, game->playerdown1);
	if (game->playerdown2 != NULL)
		mlx_destroy_image(game->mlx, game->playerdown2);
	if (game->playerleft1 != NULL)
		mlx_destroy_image(game->mlx, game->playerleft1);
	if (game->playerleft2 != NULL)
		mlx_destroy_image(game->mlx, game->playerleft2);
	if (game->playerright1 != NULL)
		mlx_destroy_image(game->mlx, game->playerright1);
	if (game->playerright2 != NULL)
		mlx_destroy_image(game->mlx, game->playerright2);
	freedeath(game);
}

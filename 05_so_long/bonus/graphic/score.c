/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:52:36 by apayen            #+#    #+#             */
/*   Updated: 2023/02/13 16:22:53 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	scoreswitch2(struct s_mlx *game, int nb, int pos)
{
	if (nb == 5)
		mlx_put_image_to_window(game->mlx, game->window, game->tabscore[5], \
			pos, (game->height * PX + 80));
	else if (nb == 6)
		mlx_put_image_to_window(game->mlx, game->window, game->tabscore[6], \
			pos, (game->height * PX + 80));
	else if (nb == 7)
		mlx_put_image_to_window(game->mlx, game->window, game->tabscore[7], \
			pos, (game->height * PX + 80));
	else if (nb == 8)
		mlx_put_image_to_window(game->mlx, game->window, game->tabscore[8], \
			pos, (game->height * PX + 80));
	else if (nb == 9)
		mlx_put_image_to_window(game->mlx, game->window, game->tabscore[9], \
			pos, (game->height * PX + 80));
}

void	scoreswitch(struct s_mlx *game, int nb, int pos)
{
	if (nb == 0)
		mlx_put_image_to_window(game->mlx, game->window, game->tabscore[0], \
			pos, (game->height * PX + 80));
	else if (nb == 1)
		mlx_put_image_to_window(game->mlx, game->window, game->tabscore[1], \
			pos, (game->height * PX + 80));
	else if (nb == 2)
		mlx_put_image_to_window(game->mlx, game->window, game->tabscore[2], \
			pos, (game->height * PX + 80));
	else if (nb == 3)
		mlx_put_image_to_window(game->mlx, game->window, game->tabscore[3], \
			pos, (game->height * PX + 80));
	else if (nb == 4)
		mlx_put_image_to_window(game->mlx, game->window, game->tabscore[4], \
			pos, (game->height * PX + 80));
	else
		scoreswitch2(game, nb, pos);
}

void	score(struct s_mlx *game)
{
	int	nb;
	int	space;

	nb = 0;
	space = 10;
	if (game->nbmove <= 9999 && game->nblock == 0)
	{
		if (game->nbmove > 999 || game->nbmove == 0)
			scoreswitch(game, game->nbmove / 1000, (((game->width * PX) / 2) \
				- (space / 2) - (game->m * 2) - space));
		if (game->nbmove > 99 || game->nbmove == 0)
			scoreswitch(game, game->nbmove % 1000 / 100, \
				(((game->width * PX) / 2) - (space / 2) - game->m));
		if (game->nbmove > 9 || game->nbmove == 0)
			scoreswitch(game, game->nbmove % 100 / 10, \
				(((game->width * PX) / 2) + (space / 2)));
		scoreswitch(game, game->nbmove % 10, (((game->width * PX) / 2) \
			+ (space / 2) + game->m + space));
		game->nblock = 1;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initenemy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:42:42 by apayen            #+#    #+#             */
/*   Updated: 2023/02/24 09:32:47 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	verifyinit(struct s_mlx *game)
{
	int	i;

	i = 0;
	if (game->wall == NULL || game->floor == NULL || game->exit == NULL \
		|| game->collectible == NULL || game->scollectible == NULL \
		|| game->player0 == NULL || game->playerup1 == NULL \
		|| game->playerup2 == NULL || game->playerdown1 == NULL \
		|| game->playerdown2 == NULL || game->playerleft1 == NULL \
		|| game->playerleft2 == NULL || game->playerright1 == NULL \
		|| game->playerright2 == NULL || game->logo == NULL)
		return (freeall(game), errors(2, 'M'), exit(-1));
	while (i < 11)
	{
		if (game->tabdeath[i] == NULL)
			return (freeall(game), errors(2, 'M'), exit(-1));
		i++;
	}
	i = 0;
	while (i < 10)
	{
		if (game->tabscore[i] == NULL)
			return (freeall(game), errors(2, 'M'), exit(-1));
		i++;
	}
}

void	printenemy(struct s_mlx *game)
{
	while (game->enemy)
	{
		game->map[game->enemy->ypos][game->enemy->xpos] = '0';
		mlx_put_image_to_window(game->mlx, game->window, game->enemy->cur, \
			(game->enemy->xpos * PX), (game->enemy->ypos * PX));
		game->enemy = game->enemy->next;
	}
	game->enemy = game->lsthead;
}

void	createhead(struct s_mlx *game, int x, int y, int i)
{
	game->enemy = ft_lstnew(game, i, x, y);
	if (!game->enemy)
		return (freeall(game), errors(2, 'M'), exit(-1));
	game->lsthead = game->enemy;
}

void	createnode(struct s_mlx *game, int x, int y, int i)
{
	struct s_enemy	*new;

	new = ft_lstnew(game, i, x, y);
	if (!new)
		return (freeall(game), errors(2, 'M'), exit(-1));
	ft_lstadd_back(&game->enemy, new);
}

void	initenemy(struct s_mlx *game)
{
	int				i;
	int				x;
	int				y;

	i = 0;
	x = 0;
	y = 0;
	while (i < game->g && game->map[y] != NULL)
	{
		x = 0;
		while (game->map[y][x] != '\0')
		{
			if (game->map[y][x] == 'G')
			{
				if (i == 0)
					createhead(game, x, y, i);
				else
					createnode(game, x, y, i);
				i++;
			}
			x++;
		}
		y++;
	}
}

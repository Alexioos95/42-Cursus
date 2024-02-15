/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:05:53 by apayen            #+#    #+#             */
/*   Updated: 2023/02/23 14:56:14 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	chooseenemydir(struct s_mlx *game, int *tab, int min)
{
	if (tab[min] == 0)
	{
		if (game->enemy->dir == 'U')
			game->enemy->dir = 'D';
		else if (game->enemy->dir == 'D')
			game->enemy->dir = 'U';
		else if (game->enemy->dir == 'L')
			game->enemy->dir = 'R';
		else if (game->enemy->dir == 'R')
			game->enemy->dir = 'L';
	}
	else if (min == 0)
		game->enemy->dir = 'U';
	else if (min == 1)
		game->enemy->dir = 'D';
	else if (min == 2)
		game->enemy->dir = 'L';
	else if (min == 3)
		game->enemy->dir = 'R';
}

void	filltabs(struct s_mlx *game, int *tab, double *dis, int *min)
{
	int	i;

	i = 0;
	setenemytarget(game, game->enemy);
	if (tab[0] == 1)
		dis[0] = sqrt(pow(game->enemy->xpos - game->enemy->xtarget, 2) \
			+ pow((game->enemy->ypos - 1) - game->enemy->ytarget, 2));
	if (tab[1] == 1)
		dis[1] = sqrt(pow(game->enemy->xpos - game->enemy->xtarget, 2) \
			+ pow((game->enemy->ypos + 1) - game->enemy->ytarget, 2));
	if (tab[2] == 1)
		dis[2] = sqrt(pow((game->enemy->xpos - 1) - game->enemy->xtarget, 2) \
			+ pow(game->enemy->ypos - game->enemy->ytarget, 2));
	if (tab[3] == 1)
		dis[3] = sqrt(pow((game->enemy->xpos + 1) - game->enemy->xtarget, 2) \
			+ pow(game->enemy->ypos - game->enemy->ytarget, 2));
	while (i < 4)
	{
		if (dis[i] < dis[*min])
			*min = i;
		i++;
	}
}

void	initialrights(struct s_mlx *game, int *tab)
{
	if (avoidhouse(game) == 1 && (game->enemy->panic >= 1 \
		|| game->enemy->idle == 0) && !(game->pxpos >= game->enemy->xpos + 1 \
		&& game->pxpos <= game->enemy->xpos + 2 \
		&& game->pypos >= game->enemy->ypos + 2 \
		&& game->pypos >= game->enemy->ypos - 2))
		tab[1] = 0;
	if (game->enemy->idle >= 1)
		tab[0] = 0;
	if (game->enemy->dir == 'U')
		tab[1] = 0;
	else if (game->enemy->dir == 'D')
		tab[0] = 0;
	else if (game->enemy->dir == 'L')
		tab[3] = 0;
	else if (game->enemy->dir == 'R')
		tab[2] = 0;
	if (game->map[game->enemy->ypos - 1][game->enemy->xpos] == '1')
		tab[0] = 0;
	if (game->map[game->enemy->ypos + 1][game->enemy->xpos] == '1')
		tab[1] = 0;
	if (game->map[game->enemy->ypos][game->enemy->xpos - 1] == '1')
		tab[2] = 0;
	if (game->map[game->enemy->ypos][game->enemy->xpos + 1] == '1')
		tab[3] = 0;
}

void	inittabs(struct s_mlx *game, int *tab, int *min)
{
	double	dis[4];
	int		i;

	i = 0;
	while (i < 4)
	{
		dis[i] = INFINITY;
		i++;
	}
	initialrights(game, tab);
	filltabs(game, tab, dis, min);
}

void	algorithm(struct s_mlx *game)
{
	int	i;
	int	min;
	int	tab[4];

	game->enemy->algolock = 1;
	i = 0;
	min = 0;
	while (i < 4)
	{
		tab[i] = 1;
		i++;
	}
	inittabs(game, tab, &min);
	chooseenemydir(game, tab, min);
}

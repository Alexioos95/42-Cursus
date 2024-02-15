/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:40:46 by apayen            #+#    #+#             */
/*   Updated: 2023/03/20 10:06:40 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	fill(struct s_mlx *game, int x, int y, char c)
{
	int		i;
	char	*str;

	i = 0;
	str = "0C@EG";
	if (y < 0 || y >= game->height || x < 0 || x >= game->width \
		|| game->mapclone[y][x] != c)
		return ;
	game->mapclone[y][x] = 'F';
	while (str[i] != '\0')
	{
		fill(game, x - 1, y, str[i]);
		fill(game, x + 1, y, str[i]);
		fill(game, x, y - 1, str[i]);
		fill(game, x, y + 1, str[i]);
		i++;
	}
}

int	floodfill(struct s_mlx *game)
{
	int	y;
	int	x;

	y = 0;
	fill(game, game->pxpos, game->pypos, 'P');
	while (game->mapclone[y] != NULL)
	{
		x = 0;
		while (game->mapclone[y][x] != '\0')
		{
			if (game->mapclone[y][x] != '1' && game->mapclone[y][x] != 'G' \
				&& game->mapclone[y][x] != 'F' && game->mapclone[y][x] != 'E')
				return (freemaps(game), errorsmapdesign('0'), 1);
			x++;
		}
		y++;
	}
	return (0);
}

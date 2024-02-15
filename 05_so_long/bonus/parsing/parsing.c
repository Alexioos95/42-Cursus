/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:56:40 by apayen            #+#    #+#             */
/*   Updated: 2023/03/20 09:47:56 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	parseswitch(struct s_mlx *game, char c, int y, int x)
{
	if (c == 'C' || c == '@')
		game->c++;
	else if (c == 'E')
		game->e++;
	else if (c == 'P')
	{
		game->pypos = y;
		game->pxpos = x;
		game->p++;
	}
	else if (c == 'G')
		game->g++;
}

int	parselines(struct s_mlx *game, int y)
{
	int	x;

	x = 0;
	if (game->map[y][0] != '1' || game->map[y][game->width - 1] != '1')
		return (freemaps(game), errorsmapdesign('1'), 1);
	while (game->map[y][x] != '\0')
	{
		if (game->map[y][x] != '1' && game->map[y][x] != 'P' \
			&& game->map[y][x] != 'E' && game->map[y][x] != 'C' \
			&& game->map[y][x] != '0' && game->map[y][x] != 'G'\
			&& game->map[y][x] != '@')
			return (freemaps(game), errors(2, '?'), 1);
		parseswitch(game, game->map[y][x], y, x);
		x++;
	}
	if (x != game->width)
		return (freemaps(game), errorsmapdesign('W'), 1);
	return (0);
}

int	parsewallsline(struct s_mlx *game, char *str)
{
	int	x;

	x = 0;
	if (str == NULL)
		return (freemaps(game), errorsmapdesign('1'), 1);
	while (str[x] != '\0')
	{
		if (str[x] != '1')
			return (freemaps(game), errorsmapdesign('1'), 1);
		x++;
		game->width++;
	}
	return (0);
}

int	initstruct(struct s_mlx *game, char *str)
{
	game->e = 0;
	game->p = 0;
	game->c = 0;
	game->g = 0;
	game->width = 0;
	if (checkname(str) == 1)
		return (errorsmapdesign('N'), 1);
	game->fd = open(str, O_RDONLY);
	if (game->fd == -1)
		return (errors(2, 'V'), 1);
	game->fullmap = getmap(game->fd);
	if (game->fullmap == NULL)
		return (close(game->fd), errors(2, 'M'), 1);
	game->map = ft_split(game->fullmap, '\n');
	if (game->map == NULL)
		return (close(game->fd), free(game->fullmap), errors(2, 'M'), 1);
	game->mapclone = ft_split(game->fullmap, '\n');
	if (game->mapclone == NULL)
		return (close(game->fd), free(game->fullmap), free(game->map),
			errors(2, 'M'), 1);
	close(game->fd);
	free(game->fullmap);
	return (0);
}

int	parsing(struct s_mlx *game, char *str)
{
	int	y;

	if (initstruct(game, str) == 1)
		return (1);
	if (parsewallsline(game, game->map[0]) == 1)
		return (1);
	y = 1;
	game->enemy = NULL;
	while (game->map[y + 1] != NULL)
	{
		if (parselines(game, y) == 1)
			return (1);
		y++;
	}
	if (parsewallsline(game, game->map[y]) == 1)
		return (1);
	if (checksize(game, y) == 1)
		return (1);
	if (game->p != 1 || game->g == 0 || game->e != 1 || game->c == 0)
		return (freemaps(game), errorsmapdesign('P'), 1);
	if (floodfill(game) == 1)
		return (1);
	game->argv = str;
	return (0);
}

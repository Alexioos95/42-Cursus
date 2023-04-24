/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap_floodfill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:40:46 by apayen            #+#    #+#             */
/*   Updated: 2023/03/20 10:02:17 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	fill(struct s_mlx *game, int x, int y, char c)
{
	int		i;
	char	*str;

	i = 0;
	str = "0C";
	if (y < 0 || y >= game->height || x < 0 || x >= game->width \
		|| game->mapclone[y][x] != c)
		return ;
	game->mapclone[y][x] = 'F';
	while (str[i] != '\0')
	{
		fill(game, x, y - 1, str[i]);
		fill(game, x, y + 1, str[i]);
		fill(game, x - 1, y, str[i]);
		fill(game, x + 1, y, str[i]);
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
			if (game->mapclone[y][x] != '1' && game->mapclone[y][x] != 'F' \
				&& game->mapclone[y][x] != 'E')
				return (freemaps(game), errorsmapdesign('0'), 1);
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*strmalloc;

	i = 0;
	j = 0;
	strmalloc = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (strmalloc == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		strmalloc[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		strmalloc[i + j] = s2[j];
		j++;
	}
	strmalloc[i + j] = '\0';
	return (strmalloc);
}

char	*getmap(int fd)
{
	static char	buffer[3601];
	char		*line;
	int			r;

	if (fd < 0)
		return (NULL);
	line = malloc(sizeof(char) * 1);
	if (line == NULL)
		return (NULL);
	line[0] = '\0';
	r = read(fd, buffer, 3600);
	if (r <= 0)
		return (free(line), NULL);
	else
		ft_strjoin(line, buffer);
	r = read(fd, buffer, 3600);
	if (r > 0)
		return (NULL);
	return (ft_strjoin(line, buffer));
}

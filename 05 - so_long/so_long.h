/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:10:06 by apayen            #+#    #+#             */
/*   Updated: 2023/02/27 09:23:36 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define PX 32

# include "mlx_linux/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

struct		s_split
{
	int		i;
	int		j;
	int		len;
	int		*tab;
	char	**strmalloc;
};

struct		s_mlx
{
	int		fd;
	int		e;
	int		p;
	int		c;
	int		height;
	int		width;
	int		error;
	int		pypos;
	int		pxpos;
	char	*fullmap;
	char	**map;
	char	**mapclone;

	int		i;
	int		j;
	int		nbmove;
	void	*mlx;
	void	*window;
	void	*wall;
	void	*floor;
	void	*player;
	void	*exit;
	void	*collectible;
};

void		errors(int argc, char c);
void		errorsmapdesign(char c);
int			parsing(struct s_mlx *game, char *str);
int			checkname(char *str);
char		*getmap(int fd);
char		**ft_split(char *s, char c);
int			floodfill(struct s_mlx *game);

int			ft_printf(const char *format, ...);

int			initgamestruct(struct s_mlx *game);
void		placetextures(struct s_mlx *game);

void		freemaps(struct s_mlx *game);
void		freeimages(struct s_mlx *game, int i);
void		freemlx(struct s_mlx *game);
void		freeall(struct s_mlx *game, int i);

int			controls(int keycode, struct s_mlx *game);
void		movetoright(struct s_mlx *game);
void		movetoleft(struct s_mlx *game);
void		movetoup(struct s_mlx *game);
void		movetodown(struct s_mlx *game);

#endif

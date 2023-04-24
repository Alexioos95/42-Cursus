/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:10:06 by apayen            #+#    #+#             */
/*   Updated: 2023/02/22 16:34:14 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# define PX 32

# include "../mlx_linux/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

struct				s_split
{
	int				i;
	int				j;
	int				len;
	int				*tab;
	char			**strmalloc;
};

struct				s_enemy
{
	int				nb;
	int				startxpos;
	int				startypos;
	int				xpos;
	int				ypos;
	char			dir;
	char			color;
	int				icolor;
	void			*cur;
	int				tmp;
	int				ytarget;
	int				xtarget;
	int				delay;
	int				spriteframe;
	int				animframe;
	int				algolock;
	int				panic;
	int				blink;
	int				idle;

	struct s_enemy	*next;
};

struct				s_mlx
{
	int				fd;
	int				e;
	int				p;
	int				c;
	int				g;
	int				gtmp;
	int				height;
	int				width;
	int				pypos;
	int				pxpos;
	char			*fullmap;
	char			**map;
	char			**mapclone;

	int				i;
	int				j;
	int				k;
	int				l;
	int				m;
	int				n;
	void			*mlx;
	void			*window;

	void			*wall;
	void			*floor;
	void			*exit;
	void			*collectible;
	void			*scollectible;
	void			*logo;

	void			*player0;
	void			*playerup1;
	void			*playerup2;
	void			*playerdown1;
	void			*playerdown2;
	void			*playerleft1;
	void			*playerleft2;
	void			*playerright1;
	void			*playerright2;
	void			*playercur;
	void			*playertmp;

	int				deathi;
	int				deathdelay;
	void			*tabdeath[11];
	void			*tabscore[10];

	void			(*fct)(struct s_mlx *);
	int				alive;
	int				spriteframe;
	int				animframe;
	int				delay;
	int				nbmove;
	int				nblock;
	char			dir;
	char			*argv;

	struct s_enemy	*enemy;
	void			*lsthead;
	void			*tabenemy[4][8];
	void			*tabpanic[4];
	int				panic;
	int				blink;
};

void				errors(int argc, char c);
void				errorsmapdesign(char c);
int					parsing(struct s_mlx *game, char *str);
void				verifyinit(struct s_mlx *game);
int					checkname(char *str);
char				*getmap(int fd);
char				**ft_split(char *s, char c);
int					floodfill(struct s_mlx *game);
int					checksize(struct s_mlx *game, int y);

void				initgamestruct(struct s_mlx *game);
void				placetextures(struct s_mlx *game);

void				freemaps(struct s_mlx *game);
void				freeimages(struct s_mlx *game);
void				freemlx(struct s_mlx *game);
void				freeall(struct s_mlx *game);
void				freeplayer(struct s_mlx *game);
void				freescore(struct s_mlx *game);
void				freepanic(struct s_mlx *game);

int					controls(int keycode, struct s_mlx *game);
void				movetoright(struct s_mlx *game);
void				movetoleft(struct s_mlx *game);
void				movetoup(struct s_mlx *game);
void				movetodown(struct s_mlx *game);
void				animright(struct s_mlx *game);
void				animleft(struct s_mlx *game);
void				animup(struct s_mlx *game);
void				animdown(struct s_mlx *game);

int					refresh(struct s_mlx *game);
void				changespriteplayer(struct s_mlx *game);
void				teleporting(struct s_mlx *game, int *y, int *x);
void				score(struct s_mlx *game);
void				player(struct s_mlx *game);

void				gg(struct s_mlx *game);
void				death(struct s_mlx *game);
void				reinit(struct s_mlx *game);
int					ft_printf(const char *format, ...);

struct s_enemy		*ft_lstnew(struct s_mlx *game, int nb, int x, int y);
void				ft_lstadd_back(struct s_enemy **lst, struct s_enemy *new);
void				ft_lstclear(struct s_enemy **lst);

void				printenemy(struct s_mlx *game);
void				initenemy(struct s_mlx *game);
void				initenemysprites(struct s_mlx *game);
void				enemy(struct s_mlx *game);
void				spriteenemypanic(struct s_mlx *game);

void				algorithm(struct s_mlx *game);
void				setenemytarget(struct s_mlx *game, struct s_enemy *lst);
void				algorithmpanic(struct s_mlx *game);
void				setenemytarget2(struct s_mlx *game, struct s_enemy *lst);
void				chooseenemydir(struct s_mlx *game, int *tab, int min);
int					avoidhouse(struct s_mlx *game);
void				panicmode(struct s_mlx *game);

void				animenemyright(struct s_mlx *game);
void				animenemyleft(struct s_mlx *game);
void				animenemyup(struct s_mlx *game);
void				animenemydown(struct s_mlx *game);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:27:40 by apayen            #+#    #+#             */
/*   Updated: 2023/02/24 09:32:11 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	reinit(struct s_mlx *game)
{
	ft_lstclear(&game->enemy);
	freemaps(game);
	parsing(game, game->argv);
	initenemy(game);
	game->alive = 1;
	game->deathdelay = 0;
	game->dir = '0';
	game->nbmove = 0;
	game->nblock = 0;
	game->spriteframe = 0;
	game->animframe = 1;
	game->delay = 0;
	game->fct = NULL;
	game->playercur = game->player0;
	game->panic = 0;
	placetextures(game);
	score(game);
}

void	initscore(struct s_mlx *game)
{
	game->logo = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/misc/logo.xpm", &game->k, &game->l);
	game->tabscore[0] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/font/0.xpm", &game->m, &game->n);
	game->tabscore[1] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/font/1.xpm", &game->m, &game->n);
	game->tabscore[2] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/font/2.xpm", &game->m, &game->n);
	game->tabscore[3] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/font/3.xpm", &game->m, &game->n);
	game->tabscore[4] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/font/4.xpm", &game->m, &game->n);
	game->tabscore[5] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/font/5.xpm", &game->m, &game->n);
	game->tabscore[6] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/font/6.xpm", &game->m, &game->n);
	game->tabscore[7] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/font/7.xpm", &game->m, &game->n);
	game->tabscore[8] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/font/8.xpm", &game->m, &game->n);
	game->tabscore[9] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/font/9.xpm", &game->m, &game->n);
}

void	initdeathsprites(struct s_mlx *game)
{
	game->tabdeath[0] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/pacman/dying/death1.xpm", &game->m, &game->n);
	game->tabdeath[1] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/pacman/dying/death2.xpm", &game->m, &game->n);
	game->tabdeath[2] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/pacman/dying/death3.xpm", &game->m, &game->n);
	game->tabdeath[3] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/pacman/dying/death4.xpm", &game->m, &game->n);
	game->tabdeath[4] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/pacman/dying/death5.xpm", &game->m, &game->n);
	game->tabdeath[5] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/pacman/dying/death6.xpm", &game->m, &game->n);
	game->tabdeath[6] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/pacman/dying/death7.xpm", &game->m, &game->n);
	game->tabdeath[7] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/pacman/dying/death8.xpm", &game->m, &game->n);
	game->tabdeath[8] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/pacman/dying/death9.xpm", &game->m, &game->n);
	game->tabdeath[9] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/pacman/dying/death10.xpm", &game->m, &game->n);
	game->tabdeath[10] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/pacman/dying/death11.xpm", &game->m, &game->n);
}

void	initplayersprites(struct s_mlx *game)
{
	game->player0 = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/pacman/pac_closed.xpm", &game->i, &game->j);
	game->playerup1 = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/pacman/pac_semi_up.xpm", &game->i, &game->j);
	game->playerup2 = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/pacman/pac_open_up.xpm", &game->i, &game->j);
	game->playerdown1 = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/pacman/pac_semi_down.xpm", &game->i, &game->j);
	game->playerdown2 = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/pacman/pac_open_down.xpm", &game->i, &game->j);
	game->playerleft1 = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/pacman/pac_semi_left.xpm", &game->i, &game->j);
	game->playerleft2 = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/pacman/pac_open_left.xpm", &game->i, &game->j);
	game->playerright1 = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/pacman/pac_semi_right.xpm", &game->i, &game->j);
	game->playerright2 = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/pacman/pac_open_right.xpm", &game->i, &game->j);
	initdeathsprites(game);
	game->playercur = game->player0;
	game->playertmp = game->player0;
	initscore(game);
}

void	initgamestruct(struct s_mlx *game)
{
	game->alive = 1;
	game->deathdelay = 0;
	game->deathi = 0;
	game->dir = '0';
	game->nbmove = 0;
	game->nblock = 0;
	game->spriteframe = 0;
	game->animframe = 0;
	game->delay = 0;
	game->fct = NULL;
	game->panic = 0;
	game->wall = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/misc/wall.xpm", &game->i, &game->j);
	game->floor = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/misc/floor.xpm", &game->i, &game->j);
	game->exit = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/misc/portal.xpm", &game->i, &game->j);
	game->scollectible = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/pacgum/super_pacgum.xpm", &game->i, &game->j);
	game->collectible = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/pacgum/pacgum.xpm", &game->i, &game->j);
	initplayersprites(game);
	initenemysprites(game);
	verifyinit(game);
}

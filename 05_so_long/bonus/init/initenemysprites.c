/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initenemysprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 09:26:01 by apayen            #+#    #+#             */
/*   Updated: 2023/02/20 11:14:07 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	initenemy1(struct s_mlx *game)
{
	game->tabenemy[0][0] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/ghost/red/ghost_up1.xpm", &game->i, &game->j);
	game->tabenemy[0][1] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/ghost/red/ghost_up2.xpm", &game->i, &game->j);
	game->tabenemy[0][2] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/ghost/red/ghost_down1.xpm", &game->i, &game->j);
	game->tabenemy[0][3] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/ghost/red/ghost_down2.xpm", &game->i, &game->j);
	game->tabenemy[0][4] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/ghost/red/ghost_left1.xpm", &game->i, &game->j);
	game->tabenemy[0][5] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/ghost/red/ghost_left2.xpm", &game->i, &game->j);
	game->tabenemy[0][6] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/ghost/red/ghost_right1.xpm", &game->i, &game->j);
	game->tabenemy[0][7] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/ghost/red/ghost_right2.xpm", &game->i, &game->j);
}

void	initenemy2(struct s_mlx *game)
{
	game->tabenemy[1][0] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/ghost/blue/ghost_up1.xpm", &game->i, &game->j);
	game->tabenemy[1][1] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/ghost/blue/ghost_up2.xpm", &game->i, &game->j);
	game->tabenemy[1][2] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/ghost/blue/ghost_down1.xpm", &game->i, &game->j);
	game->tabenemy[1][3] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/ghost/blue/ghost_down2.xpm", &game->i, &game->j);
	game->tabenemy[1][4] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/ghost/blue/ghost_left1.xpm", &game->i, &game->j);
	game->tabenemy[1][5] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/ghost/blue/ghost_left2.xpm", &game->i, &game->j);
	game->tabenemy[1][6] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/ghost/blue/ghost_right1.xpm", &game->i, &game->j);
	game->tabenemy[1][7] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/ghost/blue/ghost_right2.xpm", &game->i, &game->j);
}

void	initenemy3(struct s_mlx *game)
{
	game->tabenemy[2][0] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/ghost/pink/ghost_up1.xpm", &game->i, &game->j);
	game->tabenemy[2][1] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/ghost/pink/ghost_up2.xpm", &game->i, &game->j);
	game->tabenemy[2][2] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/ghost/pink/ghost_down1.xpm", &game->i, &game->j);
	game->tabenemy[2][3] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/ghost/pink/ghost_down2.xpm", &game->i, &game->j);
	game->tabenemy[2][4] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/ghost/pink/ghost_left1.xpm", &game->i, &game->j);
	game->tabenemy[2][5] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/ghost/pink/ghost_left2.xpm", &game->i, &game->j);
	game->tabenemy[2][6] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/ghost/pink/ghost_right1.xpm", &game->i, &game->j);
	game->tabenemy[2][7] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/ghost/pink/ghost_right2.xpm", &game->i, &game->j);
}

void	initenemy4(struct s_mlx *game)
{
	game->tabenemy[3][0] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/ghost/oran/ghost_up1.xpm", &game->i, &game->j);
	game->tabenemy[3][1] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/ghost/oran/ghost_up2.xpm", &game->i, &game->j);
	game->tabenemy[3][2] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/ghost/oran/ghost_down1.xpm", &game->i, &game->j);
	game->tabenemy[3][3] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/ghost/oran/ghost_down2.xpm", &game->i, &game->j);
	game->tabenemy[3][4] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/ghost/oran/ghost_left1.xpm", &game->i, &game->j);
	game->tabenemy[3][5] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/ghost/oran/ghost_left2.xpm", &game->i, &game->j);
	game->tabenemy[3][6] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/ghost/oran/ghost_right1.xpm", &game->i, &game->j);
	game->tabenemy[3][7] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/ghost/oran/ghost_right2.xpm", &game->i, &game->j);
}

void	initenemysprites(struct s_mlx *game)
{
	initenemy1(game);
	initenemy2(game);
	initenemy3(game);
	initenemy4(game);
	initenemy(game);
	game->tabpanic[0] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/ghost/panic/panic1a.xpm", &game->i, &game->j);
	game->tabpanic[1] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/ghost/panic/panic1b.xpm", &game->i, &game->j);
	game->tabpanic[2] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/ghost/panic/panic2a.xpm", &game->i, &game->j);
	game->tabpanic[3] = mlx_xpm_file_to_image(game->mlx, \
		"bonus/textures_bonus/ghost/panic/panic2b.xpm", &game->i, &game->j);
}

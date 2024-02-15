/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayen <apayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:30:55 by apayen            #+#    #+#             */
/*   Updated: 2023/02/27 09:21:38 by apayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	struct s_mlx	game;

	if (argc != 2)
		return (errors(argc, 0), -1);
	if (parsing(&game, argv[1]) == 1)
		return (-1);
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		return (freemaps(&game), errors(argc, 'M'), -1);
	game.window = mlx_new_window(game.mlx, (game.width * PX), \
		(game.height * PX), "./so_long");
	if (game.window == NULL)
		return (freemaps(&game), freemlx(&game), errors(argc, 'M'), -1);
	if (initgamestruct(&game) == 1)
		return (-1);
	placetextures(&game);
	mlx_key_hook(game.window, controls, &game);
	mlx_hook(game.window, 17, 0, mlx_loop_end, game.mlx);
	mlx_loop(game.mlx);
	freeall(&game, 5);
}

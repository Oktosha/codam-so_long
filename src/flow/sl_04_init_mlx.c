/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_04_init_mlx.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/07 17:10:06 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/06/21 00:18:58 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "so_long.h"

t_sl_status	sl_04_init_mlx(t_sl_game *game)
{
	int	width;
	int	height;
	int	min_width;
	int	min_height;

	width = game->utils.tile_size.x * game->map.width;
	height = game->utils.tile_size.y * game->map.height;
	min_width = game->utils.tile_size.x * 3;
	min_height = game->utils.tile_size.y * 3;
	game->mlx = mlx_init(width, height, "so_long", true);
	if (game->mlx == NULL)
		return (sl_err(SL_ERROR_INIT_MLX, "Couldn't init mlx"));
	mlx_set_window_limit(game->mlx, min_width, min_height, -1, -1);
	return (SL_SUCCESS);
}

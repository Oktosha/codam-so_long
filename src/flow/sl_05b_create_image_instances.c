/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_05b_create_image_instances.c                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/21 01:00:37 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/06/21 02:35:23 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sl_status	s_sl_collectible(t_sl_game *game, t_sl_point pos)
{
	int	id;

	id = mlx_image_to_window(game->mlx, game->img.collectible, \
		pos.x * game->utils.tile_size.x, pos.y * game->utils.tile_size.y);
	if (id == -1)
		return (sl_err(SL_ERROR_IMAGE_TO_WINDOW, \
			"couldn't put image of collectible at (%d, %d) to window", \
			pos.x, pos.y));
	game->utils.instance_ids[pos.y][pos.x] = id;
	return (SL_SUCCESS);
}

t_sl_status	s_sl_wall(t_sl_game *game, t_sl_point pos)
{
	int	id;

	id = mlx_image_to_window(game->mlx, game->img.wall, \
		pos.x * game->utils.tile_size.x, pos.y * game->utils.tile_size.y);
	if (id == -1)
		return (sl_err(SL_ERROR_IMAGE_TO_WINDOW, \
			"couldn't put image of wall at (%d, %d) to window", \
			pos.x, pos.y));
	game->utils.instance_ids[pos.y][pos.x] = id;
	return (SL_SUCCESS);
}

t_sl_status	s_sl_exit(t_sl_game	*game, t_sl_point pos)
{
	int	id;

	id = mlx_image_to_window(game->mlx, game->img.exit_open, \
		pos.x * game->utils.tile_size.x, pos.y * game->utils.tile_size.y);
	if (id == -1)
		return (sl_err(SL_ERROR_IMAGE_TO_WINDOW, \
			"couldn't put exit_open image at (%d, %d) to window", \
			pos.x, pos.y));
	game->utils.exit_open_id = id;
	game->img.exit_open->instances[id].enabled = 0;
	id = mlx_image_to_window(game->mlx, game->img.exit_closed, \
		pos.x * game->utils.tile_size.x, pos.y * game->utils.tile_size.y);
	if (id == -1)
		return (sl_err(SL_ERROR_IMAGE_TO_WINDOW, \
			"couldn't put exit_closed image at (%d, %d) to window", \
			pos.x, pos.y));
	game->utils.exit_closed_id = id;
	return (SL_SUCCESS);
}

t_sl_status	s_sl_player(t_sl_game *game)
{
	game->utils.player_id = mlx_image_to_window(\
		game->mlx, game->img.player, \
		game->map.player.x * game->utils.tile_size.x, \
		game->map.player.y * game->utils.tile_size.y);
	if (game->utils.player_id == -1)
		return (sl_err(SL_ERROR_IMAGE_TO_WINDOW, \
			"couldn't put player image to window"));
	return (SL_SUCCESS);
}

t_sl_status	sl_05b_create_image_instances(t_sl_game *game)
{
	t_sl_status	status;
	t_sl_point	pos;

	status = SL_SUCCESS;
	pos.y = -1;
	while (++pos.y < game->map.height && status == SL_SUCCESS)
	{
		pos.x = -1;
		while (++pos.x < game->map.width && status == SL_SUCCESS)
		{
			if (game->map.data[pos.y][pos.x] == 'c')
				status = s_sl_collectible(game, pos);
			if (game->map.data[pos.y][pos.x] == '1')
				status = s_sl_wall(game, pos);
			if (game->map.data[pos.y][pos.x] == 'e')
				status = s_sl_exit(game, pos);
		}
	}
	if (status == SL_SUCCESS)
		status = s_sl_player(game);
	return (status);
}

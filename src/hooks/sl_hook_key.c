/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_hook_key.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/21 01:43:37 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/06/21 03:01:20 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sl_point	s_sl_get_desired_diff(mlx_key_data_t keydata)
{
	t_sl_point	desired_diff;

	desired_diff.x = 0;
	desired_diff.y = 0;
	if (keydata.action == MLX_PRESS && keydata.key == MLX_KEY_W)
		desired_diff.y -= 1;
	if (keydata.action == MLX_PRESS && keydata.key == MLX_KEY_S)
		desired_diff.y += 1;
	if (keydata.action == MLX_PRESS && keydata.key == MLX_KEY_A)
		desired_diff.x -= 1;
	if (keydata.action == MLX_PRESS && keydata.key == MLX_KEY_D)
		desired_diff.x += 1;
	return (desired_diff);
}

void	s_sl_collect(t_sl_point pos, t_sl_game *game)
{
	int	collectible_id;
	int	exit_closed_id;
	int	exit_open_id;

	game->map.data[pos.y][pos.x] = 'o';
	collectible_id = game->utils.instance_ids[pos.y][pos.x];
	game->img.collectible->instances[collectible_id].enabled = 0;
	game->map.collectibles_left -= 1;
	if (game->map.collectibles_left == 0)
	{
		exit_closed_id = game->utils.exit_closed_id;
		game->img.exit_closed->instances[exit_closed_id].enabled = 0;
		exit_open_id = game->utils.exit_open_id;
		game->img.exit_open->instances[exit_open_id].enabled = 1;
	}
}

void	s_sl_move_player(t_sl_game *game, t_sl_point diff)
{
	mlx_instance_t	*player_instance;

	if (diff.x == 0 && diff.y == 0)
		return ;
	game->map.steps += 1;
	io_out("%d\n", game->map.steps);
	player_instance = &(game->img.player->instances[game->utils.player_id]);
	game->map.player.x += diff.x;
	game->map.player.y += diff.y;
	player_instance->x += diff.x * game->utils.tile_size.x;
	player_instance->y += diff.y * game->utils.tile_size.y;
}

void	s_sl_handle_move(t_sl_point diff, t_sl_game *game)
{
	t_sl_point	desired_pos;
	char		destination_val;

	desired_pos.x = game->map.player.x + diff.x;
	desired_pos.y = game->map.player.y + diff.y;
	destination_val = game->map.data[desired_pos.y][desired_pos.x];
	if (destination_val == '1')
		return ;
	s_sl_move_player(game, diff);
	if (destination_val == 'c')
		s_sl_collect(desired_pos, game);
	if (destination_val == 'e' && game->map.collectibles_left == 0)
	{
		game->map.game_status = SL_GAME_STATUS_VICTORY;
		mlx_close_window(game->mlx);
	}
}

void	sl_hook_key(mlx_key_data_t keydata, void *param)
{
	t_sl_game	*game;
	t_sl_point	diff;

	game = param;
	if (game->map.game_status != SL_GAME_STATUS_IN_PROGRESS)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		game->map.game_status = SL_GAME_STATUS_CANCELLED;
		mlx_close_window(game->mlx);
		return ;
	}
	diff = s_sl_get_desired_diff(keydata);
	s_sl_handle_move(diff, game);
}

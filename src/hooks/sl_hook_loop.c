/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_hook_loop.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/21 14:28:25 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/06/21 16:14:39 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	s_sl_fill_background(t_sl_game *game, t_sl_point desired_coverage)
{
	t_sl_point	pos;
	int			id;

	pos.y = 0;
	while (pos.y < desired_coverage.y)
	{
		pos.x = 0;
		while (pos.x < desired_coverage.x)
		{
			if ((pos.x >= game->utils.background_coverage.x \
				|| pos.y >= game->utils.background_coverage.y))
			{
				id = mlx_image_to_window(game->mlx, game->img.background, \
				pos.x, pos.y);
				if (id < 0)
					return (1);
				game->img.background->instances[id].z = game->utils.back_z;
			}
			pos.x += game->img.background->width;
		}
		pos.y += game->img.background->height;
	}
	game->utils.background_coverage = desired_coverage;
	return (0);
}

int	s_sl_get_linear_origin(int map_size, int player_pos, int window_length, \
	int tile_length)
{
	int	map_length;
	int	player_center;

	map_length = map_size * tile_length;
	if (map_length <= window_length)
		return (window_length / 2 - map_length / 2);
	player_center = player_pos * tile_length + tile_length / 2;
	if (player_center < window_length / 2)
		player_center = window_length / 2;
	if (map_length - player_center < window_length / 2)
		player_center = map_length - window_length / 2;
	return (window_length / 2 - player_center);
}

static void	s_sl_change_single_img_origin(mlx_image_t *img, \
	t_sl_point old_origin, t_sl_point new_origin)
{
	int	i;

	i = -1;
	while (++i < img->count)
	{
		img->instances[i].x = img->instances[i].x - old_origin.x + new_origin.x;
		img->instances[i].y = img->instances[i].y - old_origin.y + new_origin.y;
	}
}

static void	s_sl_change_origin(t_sl_game *game, t_sl_point new_origin)
{
	s_sl_change_single_img_origin(game->img.collectible, \
		game->utils.origin, new_origin);
	s_sl_change_single_img_origin(game->img.wall, \
		game->utils.origin, new_origin);
	s_sl_change_single_img_origin(game->img.player, \
		game->utils.origin, new_origin);
	s_sl_change_single_img_origin(game->img.exit_closed, \
		game->utils.origin, new_origin);
	s_sl_change_single_img_origin(game->img.exit_open, \
		game->utils.origin, new_origin);
	game->utils.origin = new_origin;
}

void	sl_hook_loop(void *param)
{
	t_sl_game	*game;
	t_sl_point	desired_origin;
	t_sl_point	desired_coverage;

	game = param;
	if (game->map.game_status != SL_GAME_STATUS_IN_PROGRESS)
		return ;
	desired_coverage = game->utils.background_coverage;
	if (desired_coverage.x < game->mlx->width)
		desired_coverage.x = game->mlx->width;
	if (desired_coverage.y < game->mlx->height)
		desired_coverage.y = game->mlx->height;
	if ((desired_coverage.x > game->utils.background_coverage.x \
		|| desired_coverage.y > game->utils.background_coverage.y) \
		&& s_sl_fill_background(game, desired_coverage))
			game->map.game_status = SL_GAME_STATUS_ERROR;
	desired_origin.x = s_sl_get_linear_origin(game->map.width, \
		game->map.player.x, game->mlx->width, game->utils.tile_size.x);
	desired_origin.y = s_sl_get_linear_origin(game->map.height, \
		game->map.player.y, game->mlx->height, game->utils.tile_size.y);
	if (desired_origin.x != game->utils.origin.x \
		|| desired_origin.y != game->utils.origin.y)
		s_sl_change_origin(game, desired_origin);
}

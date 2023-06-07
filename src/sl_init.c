/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_init.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 00:11:10 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/06/07 17:23:18 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "so_long.h"

static void	s_sl_init_map(t_sl_map *map)
{
	map->data = NULL;
	map->width = 0;
	map->height = 0;
	map->player.x = 0;
	map->player.y = 0;
	map->steps = 0;
	map->collectibles_left = 0;
	map->game_status = SL_GAME_STATUS_NOT_STARTED;
}

static void	s_sl_init_assets(t_sl_assets *assets)
{
	assets->background = NULL;
	assets->collectible = NULL;
	assets->exit_closed = NULL;
	assets->exit_open = NULL;
	assets->player = NULL;
	assets->wall = NULL;
}

static void	s_sl_init_img(t_sl_images *img)
{
	img->background = NULL;
	img->collectible = NULL;
	img->exit_closed = NULL;
	img->exit_open = NULL;
	img->player = NULL;
	img->wall = NULL;
}

static void	s_sl_init_draw_utils(t_sl_draw_utils *utils)
{
	utils->origin.x = 0;
	utils->origin.y = 0;
	utils->tile_size = 0;
	utils->background_coverage.x = 0;
	utils->background_coverage.y = 0;
	utils->instance_ids = NULL;
}

void	sl_init(t_sl_game *game)
{
	game->argc = 0;
	game->argv = NULL;
	game->map_filename = NULL;
	game->raw_map.data = NULL;
	game->raw_map.capacity = 0;
	game->raw_map.len = 0;
	s_sl_init_map(&(game->map));
	s_sl_init_assets(&(game->assets));
	s_sl_init_img(&(game->img));
	s_sl_init_draw_utils(&(game->utils));
	game->mlx = NULL;
}

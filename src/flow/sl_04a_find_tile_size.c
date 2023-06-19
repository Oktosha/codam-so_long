/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_04a_find_tile_size.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/20 00:49:42 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/06/20 01:20:01 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_sl_status	s_sl_check_dims_are_positive(mlx_texture_t *asset, \
	char *name)
{
	if (asset->width == 0)
		return (sl_err(SL_ERROR_ASSET_DIMENSIONS, "%s width is zero", name));
	if (asset->height == 0)
		return (sl_err(SL_ERROR_ASSET_DIMENSIONS, "%s height is zero", name));
	return (SL_SUCCESS);
}

static t_sl_status	s_sl_check_dims_are_expected(mlx_texture_t *asset, \
	char *name, t_sl_point size)
{
	if ((int)asset->width != size.x)
		return (sl_err(SL_ERROR_ASSET_DIMENSIONS, \
			"%s width = %d, doesn't match width = %d of other assets", \
			name, asset->width, size.x));
	if ((int)asset->height != size.y)
		return (sl_err(SL_ERROR_ASSET_DIMENSIONS, \
			"%s height = %d, doesn't match height = %d of other assets", \
			name, asset->height, size.y));
	return (SL_SUCCESS);
}

static void	apply_full_dims_check(mlx_texture_t *asset, char *name, \
	t_sl_point size, t_sl_status *status)
{
	if (*status == SL_SUCCESS)
		*status = s_sl_check_dims_are_positive(asset, name);
	if (*status == SL_SUCCESS)
		*status = s_sl_check_dims_are_expected(asset, name, size);
}

t_sl_status	sl_04a_find_tile_size(t_sl_game *game)
{
	t_sl_status	status;

	status = s_sl_check_dims_are_positive(game->assets.background, \
		ASSETS_FOLDER "bacground.png");
	game->utils.tile_size.x = game->assets.collectible->width;
	game->utils.tile_size.y = game->assets.collectible->height;
	apply_full_dims_check(game->assets.collectible, \
		ASSETS_FOLDER "collectible.png", game->utils.tile_size, &status);
	apply_full_dims_check(game->assets.exit_closed, \
		ASSETS_FOLDER "exit_closed.png", game->utils.tile_size, &status);
	apply_full_dims_check(game->assets.exit_open, \
		ASSETS_FOLDER "exit_open.png", game->utils.tile_size, &status);
	apply_full_dims_check(game->assets.player, \
		ASSETS_FOLDER "player.png", game->utils.tile_size, &status);
	apply_full_dims_check(game->assets.wall, \
		ASSETS_FOLDER "wall.png", game->utils.tile_size, &status);
	return (status);
}

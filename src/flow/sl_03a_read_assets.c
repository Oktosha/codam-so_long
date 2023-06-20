/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_03_read_assets.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/07 17:10:02 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/06/20 14:23:29 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "so_long.h"

static t_sl_status	s_sl_load_asset(mlx_texture_t **p, const char *path)
{
	*p = mlx_load_png(path);
	if (*p == NULL)
		return (sl_err(SL_ERROR_ASSET_LOAD, "Can't load asset %s", path));
	return (SL_SUCCESS);
}

static void	s_sl_apply_load(mlx_texture_t **p, const char *path, \
	t_sl_status *status)
{
	if (*status == SL_SUCCESS)
		*status = s_sl_load_asset(p, path);
}

t_sl_status	sl_03a_read_assets(t_sl_game *game)
{
	t_sl_status	status;

	status = SL_SUCCESS;
	s_sl_apply_load(\
		&(game->assets.background), ASSETS_FOLDER "background.png", &status);
	s_sl_apply_load(\
		&(game->assets.collectible), ASSETS_FOLDER "collectible.png", &status);
	s_sl_apply_load(\
		&(game->assets.exit_closed), ASSETS_FOLDER "exit_closed.png", &status);
	s_sl_apply_load(\
		&(game->assets.exit_open), ASSETS_FOLDER "exit_open.png", &status);
	s_sl_apply_load(\
		&(game->assets.player), ASSETS_FOLDER "player.png", &status);
	s_sl_apply_load(\
		&(game->assets.wall), ASSETS_FOLDER "wall.png", &status);
	return (status);
}

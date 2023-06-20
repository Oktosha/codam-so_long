/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_05a_create_images_from_textures.c               :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/07 17:10:14 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/06/21 00:42:54 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "so_long.h"

static t_sl_status	s_sl_create_image(mlx_image_t **p, mlx_t *mlx, \
	mlx_texture_t *texture, const char *name)
{
	*p = mlx_texture_to_image(mlx, texture);
	if (*p == NULL)
		return (sl_err(SL_ERROR_TEXTURE_TO_IMAGE, \
			"Can't create %s image from texture", name));
	return (SL_SUCCESS);
}

t_sl_status	sl_05a_create_images_from_textures(t_sl_game *game)
{
	t_sl_status	status;

	status = s_sl_create_image(&(game->img.background), game->mlx, \
			game->assets.background, "background");
	if (status == SL_SUCCESS)
		status = s_sl_create_image(&(game->img.collectible), game->mlx, \
			game->assets.collectible, "collectible");
	if (status == SL_SUCCESS)
		status = s_sl_create_image(&(game->img.exit_closed), game->mlx, \
			game->assets.exit_closed, "exit_closed");
	if (status == SL_SUCCESS)
		status = s_sl_create_image(&(game->img.exit_open), game->mlx, \
			game->assets.exit_open, "exit_open");
	if (status == SL_SUCCESS)
		status = s_sl_create_image(&(game->img.player), game->mlx, \
		game->assets.player, "player");
	if (status == SL_SUCCESS)
		status = s_sl_create_image(&(game->img.wall), game->mlx, \
		game->assets.wall, "wall");
	return (status);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_06_start_mlx.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/07 17:10:27 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/06/21 02:31:09 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sl_status	sl_06_start_mlx(t_sl_game *game)
{
	mlx_key_hook(game->mlx, sl_hook_key, game);
	game->map.game_status = SL_GAME_STATUS_IN_PROGRESS;
	mlx_loop(game->mlx);
	return (SL_SUCCESS);
}

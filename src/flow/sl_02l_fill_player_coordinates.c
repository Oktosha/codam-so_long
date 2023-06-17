/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_02l_fill_player_coordinates.c                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/17 19:44:23 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/06/17 20:16:51 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @note Valid player x coordinate can't be zero because these spots are walls
 * walls are checked earlier, and player coordinates are zeroes due to init
 * so player.x == 0 is a good check if we found the player
 *
 * @note Note2: x is second coordintate in map.data array and y is first.
 * It's because y is for line number and x is for position.
 * map.data[0] is the first line in map.ber file,
 * map.data[0] are all spots with y = 0
*/
t_sl_status	sl_02l_fill_player_coordinates(t_sl_game *game)
{
	t_sl_point	player;

	player.y = -1;
	while (++player.y < game->map.height)
	{
		player.x = -1;
		while (++player.x < game->map.width)
		{
			if (game->map.data[player.y][player.x] == 'P')
			{
				if (game->map.player.x != 0)
					return (sl_err(SL_ERROR_MAP_MULTIPLE_PLAYERS, \
						"More than one player on map %s: " \
						"one at (%d,%d), another at (%d, %d)", \
						game->map_filename, game->map.player.x, \
						game->map.player.y, player.x, player.y));
				game->map.player = player;
				game->map.data[player.y][player.x] = '0';
			}
		}
	}
	if (game->map.player.x == 0)
		return (sl_err(SL_ERROR_MAP_NO_PLAYER, "No player on map %s", \
			game->map_filename));
	return (SL_SUCCESS);
}

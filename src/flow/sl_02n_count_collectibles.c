/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_02n_count_collectibles.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/17 22:08:02 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/06/17 22:12:20 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sl_status	sl_02n_count_collectibles(t_sl_game *game)
{
	t_sl_point	pos;

	pos.y = -1;
	while (++pos.y < game->map.height)
	{
		pos.x = -1;
		while (++pos.x < game->map.width)
		{
			if (game->map.data[pos.y][pos.x] == 'C')
				game->map.collectibles_left += 1;
		}
	}
	if (game->map.collectibles_left < 1)
		return (sl_err(SL_ERROR_MAP_NO_COLLECTIBLES, \
			"no collectibles on map %s", \
			game->map_filename));
	return (SL_SUCCESS);
}

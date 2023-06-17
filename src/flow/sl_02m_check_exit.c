/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_02m_check_exit.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/17 20:31:26 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/06/17 20:45:27 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sl_status	sl_02m_check_exit(t_sl_game *game)
{
	int			count;
	t_sl_point	pos;

	count = 0;
	pos.y = -1;
	while (++pos.y < game->map.height)
	{
		pos.x = -1;
		while (++pos.x < game->map.width)
		{
			if (game->map.data[pos.y][pos.x] == 'E')
				count += 1;
		}
	}
	if (count < 1)
		return (sl_err(SL_ERROR_MAP_NO_EXIT, "map %s doesn't contain an exit", \
			game->map_filename));
	if (count > 1)
		return (sl_err(SL_ERROR_MAP_MULTIPLE_EXITS, "map %s has %d > 1 exits", \
			game->map_filename, count));
	return (SL_SUCCESS);
}

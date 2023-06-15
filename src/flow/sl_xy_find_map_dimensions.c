/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_xy_find_map_dimensions.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/15 20:29:11 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/06/15 20:41:34 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * We assume there are no empty strings
 * all strings end with '\n'
 * and there is at least one string
 * (all checked earlier)
*/
t_sl_status sl_xy_find_map_dimensions(t_sl_game *game)
{
	int		i;
	int		width;
	char	ch;

	i = 0;
	width = 0;
	while(i < game->raw_map.len)
	{
		ch = game->raw_map.data[i];
		if (ch == '\n')
		{
			game->map.height += 1;
			if (game->map.width == 0)
				game->map.width = width;
			if (game->map.width != width)
			{
				return (sl_err(SL_ERROR_MAP_NON_RECTANGLE, \
				"Map %s is not rectangular\n" \
				"Line %d width = %d differs from the established width = %d", \
				game->map_filename, game->map.height, width, game->map.width));
			}
			width = -1;
		}
		i += 1;
		width += 1;
	}
	return (SL_SUCCESS);
}

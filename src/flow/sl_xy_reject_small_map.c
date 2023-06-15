/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_xy_reject_small_map.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/15 20:45:21 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/06/15 21:33:03 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sl_status sl_reject_small_map(t_sl_game *game)
{
	const char	*width_text = "\nThe map should be at least 3 symbols wide " \
		"to have left and right borders";
	const char	*height_text = "\nThe map should be at least 3 symbols high " \
		"to have top and bottom borders";
	char	*err1;
	char	*err2;

	err1 = "";
	err2 = "";
	if (game->map.width < 3)
		err1 = width_text;
	if (game->map.height < 3)
		err2 = height_text;
	if (game->map.height < 3 || game->map.width < 3)
	{
		return (sl_err(SL_ERROR_MAP_TOO_SMALL, \
			"Map %s is %d symbols wide and %d high, " \
			"too small to be a valid map with borders%s%s", \
			game->map_filename, game->map.width, game->map.height, err1, err2));
	}
	return (SL_SUCCESS);
}

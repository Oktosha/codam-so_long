/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_02k_check_borders.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/17 15:46:06 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/06/17 16:11:05 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sl_status	s_sl_check_horizontal_borders(t_sl_game *game)
{
	int		i;

	i = 0;
	while (i < game->map.width)
	{
		if (game->map.data[0][i] != '1')
			return (sl_err(SL_ERROR_MAP_BORDERS, \
			"Map %s isn't properly surrounded by walls\n" \
			"Non wall symbol '%c' on top line at position %d", \
			game->map_filename, game->map.data[0][i], i + 1));
		if (game->map.data[game->map.height - 1][i] != '1')
			return (sl_err(SL_ERROR_MAP_BORDERS, \
			"Map %s isn't properly surrounded by walls\n" \
			"Non wall symbol '%c' on bottom line at position %d", \
			game->map_filename, \
			game->map.data[game->map.height - 1][i], i + 1));
		i += 1;
	}
	return (SL_SUCCESS);
}

t_sl_status	s_sl_check_vertical_borders(t_sl_game *game)
{
	int		i;

	i = 0;
	while (i < game->map.height)
	{
		if (game->map.data[i][0] != '1')
			return (sl_err(SL_ERROR_MAP_BORDERS, \
			"Map %s isn't properly surrounded by walls\n" \
			"Non wall symbol '%c' on left column at line %d", \
			game->map_filename, game->map.data[i][0], i + 1));
		if (game->map.data[i][game->map.width - 1] != '1')
			return (sl_err(SL_ERROR_MAP_BORDERS, \
			"Map %s isn't properly surrounded by walls\n" \
			"Non wall symbol '%c' on right column at line %d", \
			game->map_filename, game->map.data[i][game->map.width - 1], i + 1));
		i += 1;
	}
	return (SL_SUCCESS);
}

t_sl_status	sl_02k_check_borders(t_sl_game *game)
{
	t_sl_status	status;

	status = SL_SUCCESS;
	sl_apply(game, s_sl_check_horizontal_borders, &status);
	sl_apply(game, s_sl_check_vertical_borders, &status);
	return (status);
}

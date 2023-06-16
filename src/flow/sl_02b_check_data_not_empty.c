/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_02b_check_data_not_empty.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/15 18:51:09 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/06/16 22:31:58 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sl_status	sl_02b_check_data_non_empty(t_sl_game *game)
{
	if (game->raw_map.len == 0)
		return (sl_err(SL_ERROR_MAP_EMPTY, \
			"Map file %s is empty", \
			game->map_filename));
	return (SL_SUCCESS);
}

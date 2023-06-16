/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_02c_check_data_is_print.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/09 14:12:38 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/06/16 23:08:53 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sl_status	sl_02c_check_data_is_print(t_sl_game *game)
{
	int	i;

	i = 0;
	while (i < game->raw_map.len)
	{
		if (!io_is_ascii_print(game->raw_map.data[i]) \
			&& !io_is_ascii_whitespace(game->raw_map.data[i]))
			return (sl_err(SL_ERROR_MAP_UNEXPECTED_SYMBOL, \
			"unexpected symbol %d at position %d in %s\n" \
			"it is neither an ascii print symbol nor an ascii whitespace\n" \
			"Allowed symbols are '\\n'=10 '0'=48 '1'=49 'C'=67 'E'=69 'P'=80", \
			game->raw_map.data[i], i + 1, game->map_filename));
		i += 1;
	}
	return (SL_SUCCESS);
}

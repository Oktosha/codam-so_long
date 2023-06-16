/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_02e_check_trailing_newline.c                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/15 18:58:09 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/06/16 22:42:42 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sl_status	sl_02e_check_trailing_newline(t_sl_game *game)
{
	int	len;

	len = game->raw_map.len;
	if (len < 1)
		return (sl_err(SL_ERROR_INTEGRITY, \
			"Trailing newline check on empty data\n" \
			"Size check should go first\n"));
	if (game->raw_map.data[len - 1] != '\n')
		return (sl_err(SL_ERROR_MAP_NO_LAST_NEWLINE, \
			"No newline at the end of %s\n" \
			"The last line of a valid map should end with a newline", \
			game->map_filename));
	return (SL_SUCCESS);
}

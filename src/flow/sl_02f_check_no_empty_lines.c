/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_02f_check_no_empty_lines.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/15 19:07:35 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/06/16 22:42:56 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sl_status	sl_02f_check_no_empty_lines(t_sl_game *game)
{
	int		i;
	int		line;
	char	ch;
	char	prev;

	i = 0;
	line = 1;
	prev = '\n';
	while (i < game->raw_map.len)
	{
		ch = game->raw_map.data[i];
		if (prev == '\n' && ch == '\n')
			return (sl_err(SL_ERROR_MAP_EMPTY_LINE, \
					"Line %d of %s is empty but empty lines aren't allowed", \
					line, game->map_filename));
		i += 1;
		if (ch == '\n')
			line += 1;
		prev = ch;
	}
	return (SL_SUCCESS);
}

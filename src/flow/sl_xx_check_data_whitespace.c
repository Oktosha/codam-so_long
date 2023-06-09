/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_xx_check_data_whitespace.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/09 15:05:19 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/06/09 15:32:35 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*s_sl_whitespace_name(int ch)
{
	if (ch == ' ')
		return ("space (32)");
	if (ch == '\t')
		return ("horizontal tab (9)");
	if (ch == '\n')
		return ("newline (10)");
	if (ch == '\v')
		return ("vertical tab (11)");
	if (ch == '\f')
		return ("form feed (12)");
	if (ch == '\r')
		return ("carriage return (13)");
	sl_err(SL_ERROR_INTEGRITY, "getting name of unxpected ch = %d", ch);
	return ("unrecognized");
}

t_sl_status	sl_xx_check_data_whitespace(t_sl_game *game)
{
	int		line;
	int 	pos;
	int		i;
	char	ch;

	line = 1;
	pos = 1;
	i = 0;
	while (i < game->raw_map.len)
	{
		ch = game->raw_map.data[i];
		if (io_is_ascii_whitespace(ch) && ch != '\n')
		{
			return (sl_err(SL_ERROR_MAP_UNEXPECTED_SYMBOL, \
				"Unexpected %s on line %d at position %d in %s" \
				"Whitespaces other than newlines aren't allowed", \
				s_sl_whitespace_name(ch), line, pos, game->map_filename));
		}
		if (ch == '\n')
		{
			line += 1;
			pos = 1;
		}
		else
		{
			pos += 1;
		}
		i += 1;
	}
	return (SL_SUCCESS);
}

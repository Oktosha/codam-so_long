/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_02j_fill_map_data.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/17 14:39:31 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/06/17 15:38:57 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sl_status	sl_02j_fill_map_data(t_sl_game *game)
{
	int		line;
	int		pos;
	int		i;
	char	ch;

	line = 0;
	pos = 0;
	i = 0;
	while (i < game->raw_map.len)
	{
		ch = game->raw_map.data[i];
		if (ch == '\n')
		{
			line += 1;
			pos = 0;
		}
		else
		{
			game->map.data[line][pos] = ch;
			pos += 1;
		}
		i += 1;
	}
	return (SL_SUCCESS);
}

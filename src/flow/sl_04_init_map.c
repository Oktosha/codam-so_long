/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_04_init_map.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/07 17:09:56 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/06/09 14:12:23 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sl_status s_sl_count(t_sl_game *game)
{
	int i;
	int	latest_newline;
	int	cnt_player;

	i = 0;
	latest_newline = -1;
	while (i < game->raw_map.len)
	{

	}
}

t_sl_status	sl_04_init_map(t_sl_game *game)
{
	(void) game;
	return (SL_SUCCESS);
}

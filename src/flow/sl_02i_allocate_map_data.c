/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_02i_allocate_map_data.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/17 15:24:06 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/06/17 15:39:13 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	s_sl_apply_calloc(void *p, int count, int size, t_sl_status *status)
{
	if (*status == SL_SUCCESS)
		*status = sl_calloc(p, count, size);
}

t_sl_status	sl_02i_allocate_map_data(t_sl_game *game)
{
	t_sl_status	status;
	int			i;

	status = SL_SUCCESS;
	s_sl_apply_calloc(&(game->map.data), \
		game->map.height, sizeof(char *), &status);
	i = 0;
	while (i < game->map.height)
	{
		s_sl_apply_calloc(&(game->map.data[i]), \
			game->map.width, sizeof(char), &status);
		i += 1;
	}
	return (status);
}

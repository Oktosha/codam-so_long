/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_03c_allocate_instance_ids.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/20 14:28:30 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/06/20 23:43:38 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	s_sl_apply_calloc(void *p, int count, int size, t_sl_status *status)
{
	if (*status == SL_SUCCESS)
		*status = sl_calloc(p, count, size);
}

static void s_sl_fill_negative_ones(t_sl_game *game)
{
	int	y;
	int	x;

	y = -1;
	while(++y < game->map.height)
	{
		x = -1;
		while (++x < game->map.width)
			game->utils.instance_ids[y][x] = -1;
	}
}

t_sl_status	sl_03c_allocate_instance_ids(t_sl_game *game)
{
	t_sl_status	status;
	int			i;

	status = SL_SUCCESS;
	s_sl_apply_calloc(&(game->utils.instance_ids), \
		game->map.height, sizeof(int *), &status);
	i = 0;
	while (i < game->map.height)
	{
		s_sl_apply_calloc(&(game->utils.instance_ids[i]), \
			game->map.width, sizeof(int), &status);
		i += 1;
	}
	if (status != SL_SUCCESS)
		return (sl_err(status, \
			"Problem allocating utils.instance_ids for %s", \
			game->map_filename));
	s_sl_fill_negative_ones(game);
	return (status);
}

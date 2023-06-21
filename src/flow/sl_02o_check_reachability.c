/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_02o_check_reachability.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/19 17:23:20 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/06/21 02:34:36 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	s_sl_make_visited(t_sl_map *map, t_sl_point pos)
{
	char	old_val;
	char	new_val;

	old_val = map->data[pos.y][pos.x];
	new_val = '?';
	if (old_val == 'C')
		new_val = 'c';
	if (old_val == 'E')
		new_val = 'e';
	if (old_val == '0')
		new_val = 'o';
	io_assert(new_val != '?', "new != '?'; old_val was %c", old_val);
	map->data[pos.y][pos.x] = new_val;
}

static int	s_sl_is_visited(t_sl_map *map, t_sl_point pos)
{
	char	val;

	val = map->data[pos.y][pos.x];
	return ((val == 'c') || (val == 'o') || (val == 'e'));
}

/**
 * Walks around map avoiding walls; converts 0->o, C->c, E->e, P->p
*/
static void	s_sl_dfs(t_sl_map *map, t_sl_point pos)
{
	const t_sl_point	delta[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	t_sl_point			next;
	int					i;

	s_sl_make_visited(map, pos);
	i = -1;
	while (++i < 4)
	{
		next.x = pos.x + delta[i].x;
		next.y = pos.y + delta[i].y;
		if (map->data[next.y][next.x] != '1' && !s_sl_is_visited(map, next))
			s_sl_dfs(map, next);
	}
}

/**
 * Function returns (0,0) if there is no unreached collectible/exit
 * On a proper map this position is occupied by wall, quite handy
 * If several things are unreachable, exit is a priority
 * If exit is reachable, returns the top unreachable collectible with the min x
*/
static t_sl_point	s_sl_get_unreached(t_sl_map *map)
{
	t_sl_point	unreachable;
	t_sl_point	current;

	unreachable.x = 0;
	unreachable.y = 0;
	current.y = 0;
	while (++current.y < map->height)
	{
		current.x = 0;
		while (++current.x < map->width)
		{
			if (map->data[current.y][current.x] == 'E')
				return (current);
			if (map->data[current.y][current.x] == 'C' && unreachable.x == 0)
				unreachable = current;
		}
	}
	return (unreachable);
}

t_sl_status	sl_02o_check_reachability(t_sl_game *game)
{
	t_sl_point	unreached;

	s_sl_dfs(&(game->map), game->map.player);
	unreached = s_sl_get_unreached(&(game->map));
	if (game->map.data[unreached.y][unreached.x] == 'E')
		return (sl_err(SL_ERROR_MAP_UNREACHABLE_EXIT, \
			"Exit at(%d, %d) on map %s can't be reached by player", \
			unreached.x, unreached.y, game->map_filename));
	if (game->map.data[unreached.y][unreached.x] == 'C')
		return (sl_err(SL_ERROR_MAP_UNREACHABLE_COLLECTIBLE, \
			"Collectible at(%d, %d) on map %s can't be reached by player", \
			unreached.x, unreached.y, game->map_filename));
	return (SL_SUCCESS);
}

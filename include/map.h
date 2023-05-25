/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/25 16:45:09 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/05/25 17:44:10 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "errors.h"
# include "point.h"

typedef struct s_sl_map
{
	char		**data;
	int			width;
	int			height;
	t_sl_point	player;
	int			steps;
	int			collectibles_left;
	int			is_finished;
}	t_sl_map;

int	sl_read_map(char *map_file, t_sl_map *map);
int	sl_free_map(t_sl_map *map);

#endif

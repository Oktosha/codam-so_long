/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 00:51:17 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/05/29 01:10:54 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "map.h"

int	sl_free_map(t_sl_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->data[i]);
		++i;
	}
	free(map->data);
	map->data = NULL;
	return (0);
}

int sl_map_precheck(char *map_file, t_sl_map *map)
{

}

int	sl_read_map(char *map_file, t_sl_map *map)
{
	int	status;

	status = sl_map_precheck(map_file, map);
	if (status != SL_STATUS_SUCCESS)
		return (status);
	map->data = malloc(map->height * sizeof(char *));
	if (map->data == NULL)
		return (SL_STATUS_MEMORY_ERROR);
	
}

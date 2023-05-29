/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 00:51:17 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/05/29 19:03:54 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "codam_io.h"

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

static int increase_capacity(t_sl_map *map, int *capacity)
{
	
}

int	sl_read_map(char *map_filename, t_sl_map *map)
{
	int				reserved_height;
	t_io_input_file	file;
	char			*line;

	if (io_open_for_read(map_filename, &file) != IO_OPEN_FOR_READ_SUCCESS)
		return (SL_STATUS_FILE_ERROR);
	reserved_height = 3;
	map->height = 0;
	map->data = malloc(reserved_height * sizeof(char *));
	if (map->data == NULL)
		return (SL_STATUS_MEMORY_ERROR);
	while (io_next_line(&file, &line) == IO_NEXT_LINE_SUCCESS)
	{
		if (map->height == reserved_height)
		
	}
}

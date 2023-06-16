/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_02a_read_map_data.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/07 17:09:11 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/06/16 22:09:30 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "codam_io.h"
#include "so_long.h"

t_sl_status	sl_02a_read_map_data(t_sl_game *game)
{
	t_io_read_file_status	read_status;

	read_status = io_read_file(game->map_filename, &(game->raw_map));
	if (read_status == IO_READ_FILE_SUCCESS)
		return (SL_SUCCESS);
	if (read_status & IO_READ_FILE_ALLOC_ERROR)
		return (sl_err(SL_ERROR_ALLOCATION, \
			"couldn't allocate memory for map data '%s'", game->map_filename));
	if (read_status & IO_READ_FILE_OPEN_ERROR)
		return (sl_err(SL_ERROR_MAP_OPEN, \
			"couldn't open map file '%s'", game->map_filename));
	if (read_status & IO_READ_FILE_READ_ERROR)
		return (sl_err(SL_ERROR_MAP_READ, \
			"error reading from map file '%s'", game->map_filename));
	if (read_status & IO_READ_FILE_CLOSE_ERROR)
		return (sl_err(SL_ERROR_MAP_CLOSE, \
			"error closing map file '%s'", game->map_filename));
	return (sl_err(SL_ERROR_INTEGRITY, "unknown read_status: %d", read_status));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_01b_check_file_extention.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/07 16:52:53 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/06/16 22:09:21 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "codam_io.h"
#include "so_long.h"

t_sl_status	sl_01b_check_file_extention(t_sl_game *game)
{
	int	len;

	len = io_signed_strlen(game->map_filename);
	if (len < 4)
		return (sl_err(SL_ERROR_MAP_NAME, \
			"map filename '%s' is too short to have .ber extension", \
			game->map_filename));
	if (game->map_filename[len - 4] != '.' \
		|| game->map_filename[len - 3] != 'b' \
		|| game->map_filename[len - 2] != 'e' \
		|| game->map_filename[len - 1] != 'r')
		return (sl_err(SL_ERROR_MAP_NAME, \
			"map filename '%s' doesn't end with '.ber' extension", \
			game->map_filename));
	return (SL_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_01a_get_filename_from_argc_argv.c               :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/07 15:25:33 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/06/16 22:04:22 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sl_status	sl_01a_get_filename_from_argc_argv(t_sl_game *game)
{
	if (game->argc < 2)
		return (sl_err(SL_ERROR_TOO_FEW_ARGS, "No map file provided"));
	if (game->argc > 2)
		return (sl_err(SL_ERROR_TOO_MANY_ARGS, "Too many command line args"));
	game->map_filename = game->argv[1];
	return (SL_SUCCESS);
}

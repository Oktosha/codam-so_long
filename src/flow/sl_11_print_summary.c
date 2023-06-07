/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_11_print_summary.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/07 15:48:28 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/06/07 17:23:01 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "codam_io.h"

t_sl_status	sl_11_print_summary(t_sl_game *game)
{
	int	status;

	status = game->map.game_status;
	if (status == SL_GAME_STATUS_VICTORY)
	{
		io_out("Congratulations! You won!\n");
		io_out("Steps made: %d\n", game->map.steps);
		return (SL_SUCCESS);
	}
	if (status == SL_GAME_STATUS_CANCELLED)
	{
		io_out("Game interrupted\n");
		io_out("Steps made so far: %d\n", game->map.steps);
		io_out("Collectibles left: %d\n", game->map.collectibles_left);
		return (SL_SUCCESS);
	}
	if (status == SL_GAME_STATUS_ERROR)
		return (sl_err(SL_ERROR_IN_GAME, "An error occured in game"));
	return (sl_err(SL_ERROR_INTEGRITY, "Game status %d in the end", status));
}

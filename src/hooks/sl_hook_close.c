/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_hook_close.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/21 14:14:28 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/06/21 14:16:59 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_hook_close(void	*param)
{
	t_sl_game	*game;

	game = param;
	game->map.game_status = SL_GAME_STATUS_CANCELLED;
}

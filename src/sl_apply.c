/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_apply.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 00:08:12 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/06/05 00:09:13 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_apply(t_sl_game *game, t_sl_flow f, t_sl_status *status)
{
	if (*status == SL_SUCCESS)
		*status = f(game);
}

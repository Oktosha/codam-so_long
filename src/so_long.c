/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/25 17:06:30 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/05/25 23:25:20 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include "game.h"
#include "errors.h"

static int sl_error_explain_args(int argc, char **argv);

static int sl_print_unfinished_summary(t_sl_game *game);

int	so_long(int argc, char **argv)
{
	t_sl_game	game;
	int			status;

	if (argc != 2)
		return (sl_error_explain_args(argc, argv));
	status = sl_read_map(argv[1], &(game.map));
	if (status != SL_STATUS_SUCCESS)
		return (status);
	status = sl_read_assets(&(game.assets));
	if (status != SL_STATUS_SUCCESS)
		return (sl_free_map(&(game.map)), status);
	status = sl_init_game(&game);
	if (status != SL_STATUS_SUCCESS)
		return (status);
	mlx_loop(game.mlx);
	if (!game.map.is_finished)
		sl_print_unfinished_summary(&game);
	sl_free_assets(&(game.assets));
	sl_free_map(&(game.map));
	sl_free_draw_utils(&(game.utils));
	mlx_terminate(game.mlx);
	return (SL_STATUS_SUCCESS);
}

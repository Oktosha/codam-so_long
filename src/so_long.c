/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/25 17:06:30 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/06/07 17:01:26 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sl_status	so_long(int argc, char **argv)
{
	t_sl_game	game;
	t_sl_status	status;

	sl_init(&game);
	game.argc = argc;
	game.argv = argv;
	status = SL_SUCCESS;
	sl_apply(&game, sl_01_get_filename_from_argc_argv, &status);
	sl_apply(&game, sl_02_check_file_extention, &status);
	sl_apply(&game, sl_03_read_map_data, &status);
	sl_apply(&game, sl_04_init_map, &status);
	sl_apply(&game, sl_05_read_assets, &status);
	sl_apply(&game, sl_06_init_mlx, &status);
	sl_apply(&game, sl_07_instantiate_images, &status);
	sl_apply(&game, sl_08_init_draw_utils, &status);
	sl_apply(&game, sl_09_add_hooks, &status);
	sl_apply(&game, sl_10_start_mlx_loop, &status);
	sl_apply(&game, sl_11_print_summary, &status);
	sl_cleanup(&game, &status);
	return (status);
}

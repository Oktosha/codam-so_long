/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/25 17:06:30 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/06/21 00:09:24 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_sl_status	s_sl_01(t_sl_game *game)
{
	t_sl_status	status;

	status = SL_SUCCESS;
	sl_apply(game, sl_01a_get_filename_from_argc_argv, &status);
	sl_apply(game, sl_01b_check_file_extention, &status);
	return (status);
}

static t_sl_status	s_sl_02(t_sl_game *game)
{
	t_sl_status	status;

	status = SL_SUCCESS;
	sl_apply(game, sl_02a_read_map_data, &status);
	sl_apply(game, sl_02b_check_data_non_empty, &status);
	sl_apply(game, sl_02c_check_data_is_print, &status);
	sl_apply(game, sl_02d_check_data_symbols, &status);
	sl_apply(game, sl_02e_check_trailing_newline, &status);
	sl_apply(game, sl_02f_check_no_empty_lines, &status);
	sl_apply(game, sl_02g_find_map_dimensions, &status);
	sl_apply(game, sl_02h_reject_small_map, &status);
	sl_apply(game, sl_02i_allocate_map_data, &status);
	sl_apply(game, sl_02j_fill_map_data, &status);
	sl_apply(game, sl_02k_check_borders, &status);
	sl_apply(game, sl_02l_fill_player_coordinates, &status);
	sl_apply(game, sl_02m_check_exit, &status);
	sl_apply(game, sl_02n_count_collectibles, &status);
	sl_apply(game, sl_02o_check_reachability, &status);
	return (status);
}

t_sl_status	so_long(int argc, char **argv)
{
	t_sl_game	game;
	t_sl_status	status;

	sl_init(&game);
	game.argc = argc;
	game.argv = argv;
	status = SL_SUCCESS;
	sl_apply(&game, s_sl_01, &status);
	sl_apply(&game, s_sl_02, &status);
	sl_apply(&game, sl_03a_read_assets, &status);
	sl_apply(&game, sl_03b_find_tile_size, &status);
	sl_apply(&game, sl_03c_allocate_instance_ids, &status);
	sl_apply(&game, sl_04_init_mlx, &status);
	sl_apply(&game, sl_11_print_summary, &status);
	sl_cleanup(&game, &status);
	return (status);
}

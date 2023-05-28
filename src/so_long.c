/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/25 17:06:30 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/05/29 01:04:16 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "codam_io.h"

#include "so_long.h"

#include "game.h"
#include "errors.h"

static int	sl_error_explain_args(int argc, char **argv)
{
	io_err("Error\n");
	if (argc != 2)
		io_err("Expected 1 command line arg, got %d\n", argc - 1);
	else
		io_err("Map file should have .ber extension\n");
	io_err("Usage: ./so_long map.ber\n");
	return (SL_STATUS_ARGS_ERROR);
}

static int	sl_print_summary(t_sl_game *game)
{
	if (game->map.is_finished)
	{
		io_out("Congratulations! You won!\n");
		io_out("Steps made: %d\n", game->map.steps);
		return (0);
	}
	io_out("Game Over!\n");
	io_out("Steps made: %d\n", game->map.steps);
	io_out("Collectibles left: %d\n", game->map.collectibles_left);
	io_out("Good luck next time!\n");
	return (0);
}

static int	sl_has_proper_extension(char *s)
{
	int	len;

	len = io_signed_strlen(s);
	if (len < 4)
		return (0);
	if (s[len - 1] != 'r' || s[len - 2] != 'e' || s[len - 3] != 'b')
		return (0);
	if (s[len - 4] != '.')
		return (0);
	if (len == 4)
		io_err("Warning: filename consists of extension only\n");
	return (1);
}

int	so_long(int argc, char **argv)
{
	t_sl_game	game;
	int			status;

	if (argc != 2 || !sl_has_proper_extension(argv[1]))
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
	sl_print_summary(&game);
	sl_free_assets(&(game.assets));
	sl_free_map(&(game.map));
	sl_free_draw_utils(&(game.utils));
	mlx_terminate(game.mlx);
	return (SL_STATUS_SUCCESS);
}

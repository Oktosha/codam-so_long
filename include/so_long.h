/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/25 17:03:34 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/06/09 14:53:15 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/MLX42.h"
# include "codam_io.h"

typedef enum e_sl_status {
	SL_ERROR_INTEGRITY = -1,
	SL_SUCCESS = 0,
	SL_ERROR_ALLOCATION,
	SL_ERROR_TOO_FEW_ARGS,
	SL_ERROR_TOO_MANY_ARGS,
	SL_ERROR_MAP_NAME,
	SL_ERROR_MAP_OPEN,
	SL_ERROR_MAP_CLOSE,
	SL_ERROR_MAP_READ,
	SL_ERROR_MAP_UNEXPECTED_SYMBOL,
	SL_ERROR_IN_GAME
}	t_sl_status;

typedef struct s_sl_point
{
	int	x;
	int	y;
}	t_sl_point;

typedef struct s_sl_assets {
	mlx_texture_t	*background;
	mlx_texture_t	*wall;
	mlx_texture_t	*exit_open;
	mlx_texture_t	*exit_closed;
	mlx_texture_t	*collectible;
	mlx_texture_t	*player;
}	t_sl_assets;

typedef struct s_sl_draw_utils
{
	t_sl_point	origin;
	int			tile_size;
	t_sl_point	background_coverage;
	int			**instance_ids;
}	t_sl_draw_utils;

typedef struct s_sl_images
{
	mlx_image_t	*background;
	mlx_image_t	*wall;
	mlx_image_t	*exit_open;
	mlx_image_t	*exit_closed;
	mlx_image_t	*collectible;
	mlx_image_t	*player;
}	t_sl_images;

typedef enum e_sl_game_status
{
	SL_GAME_STATUS_NOT_STARTED = 0,
	SL_GAME_STATUS_IN_PROGRESS,
	SL_GAME_STATUS_VICTORY,
	SL_GAME_STATUS_CANCELLED,
	SL_GAME_STATUS_ERROR
}	t_sl_game_status;

typedef struct s_sl_map
{
	char				**data;
	int					width;
	int					height;
	t_sl_point			player;
	int					steps;
	int					collectibles_left;
	t_sl_game_status	game_status;
}	t_sl_map;

typedef struct s_sl_game {
	int				argc;
	char			**argv;
	char			*map_filename;
	t_io_charz		raw_map;
	t_sl_map		map;
	t_sl_assets		assets;
	t_sl_images		img;
	t_sl_draw_utils	utils;
	mlx_t			*mlx;
}	t_sl_game;

typedef t_sl_status(*t_sl_flow)(t_sl_game *game);

t_sl_status	so_long(int argc, char **argv);

void		sl_init(t_sl_game *game);
void		sl_apply(t_sl_game *game, t_sl_flow f, t_sl_status *status);
void		sl_cleanup(t_sl_game *game, t_sl_status *status);
t_sl_status	sl_err(t_sl_status code, char *fmt, ...);

t_sl_status	sl_01_get_filename_from_argc_argv(t_sl_game *game);
t_sl_status	sl_02_check_file_extention(t_sl_game *game);
t_sl_status	sl_03_read_map_data(t_sl_game *game);
t_sl_status	sl_04_init_map(t_sl_game *game);
t_sl_status	sl_05_read_assets(t_sl_game *game);
t_sl_status	sl_06_init_mlx(t_sl_game *game);
t_sl_status	sl_07_instantiate_images(t_sl_game *game);
t_sl_status	sl_08_init_draw_utils(t_sl_game *game);
t_sl_status	sl_09_add_hooks(t_sl_game *game);
t_sl_status	sl_10_start_mlx_loop(t_sl_game *game);
t_sl_status	sl_11_print_summary(t_sl_game *game);

#endif

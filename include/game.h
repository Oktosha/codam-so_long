/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/25 17:35:33 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/05/25 18:10:54 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "MLX42/MLX42.h"

# include "assets.h"
# include "map.h"
# include "point.h"

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

typedef struct s_sl_game
{
	t_sl_map		map;
	t_sl_assets		assets;
	t_sl_images		img;
	t_sl_draw_utils	utils;
	mlx_t			*mlx;
}	t_sl_game;

int	sl_init_game(t_sl_game *game);
int sl_free_draw_utils(t_sl_draw_utils *utils);

#endif

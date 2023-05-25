/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   assets.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/25 17:21:26 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/05/25 18:09:00 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSETS_H
# define ASSETS_H

# include "MLX42/MLX42.h"
# include "errors.h"

typedef struct s_sl_assets {
	mlx_texture_t	*background;
	mlx_texture_t	*wall;
	mlx_texture_t	*exit_open;
	mlx_texture_t	*exit_closed;
	mlx_texture_t	*collectible;
	mlx_texture_t	*player;
}	t_sl_assets;

int	sl_read_assets(t_sl_assets *assets);
int	sl_free_assets(t_sl_assets *assets);

#endif

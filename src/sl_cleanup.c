/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_cleanup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/05 00:26:07 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/06/07 17:25:24 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "so_long.h"

static void	s_sl_free_assets(t_sl_assets *assets)
{
	if (assets->background != NULL)
		mlx_delete_texture(assets->background);
	if (assets->collectible != NULL)
		mlx_delete_texture(assets->collectible);
	if (assets->exit_closed != NULL)
		mlx_delete_texture(assets->exit_closed);
	if (assets->exit_open != NULL)
		mlx_delete_texture(assets->exit_open);
	if (assets->player != NULL)
		mlx_delete_texture(assets->player);
	if (assets->wall != NULL)
		mlx_delete_texture(assets->wall);
}

static void	s_sl_free_map_data(char **data, int height)
{
	int	i;

	if (data)
	{
		i = 0;
		while (i < height)
		{
			free(data[i]);
			i += 1;
		}
		free(data);
	}
}

static void	s_sl_free_instance_ids(int **data, int height)
{
	int	i;

	if (data)
	{
		i = 0;
		while (i < height)
		{
			free(data[i]);
			i += 1;
		}
		free(data);
	}
}

void	sl_cleanup(t_sl_game *game, t_sl_status *status)
{
	(void) status;
	free(game->raw_map.data);
	s_sl_free_map_data(game->map.data, game->map.height);
	s_sl_free_assets(&(game->assets));
	s_sl_free_instance_ids(game->utils.instance_ids, game->map.height);
	if (game->mlx != NULL)
		mlx_terminate(game->mlx);
	sl_init(game);
}

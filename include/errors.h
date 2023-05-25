/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/25 17:00:29 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/05/25 23:25:46 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ERRORS_H
# define ERRORS_H

typedef enum e_sl_status
{
	SL_STATUS_SUCCESS = 0,
	SL_STATUS_MAP_ERROR,
	SL_STATUS_ASSET_ERROR,
	SL_STATUS_MEMORY_ERROR,
	SL_STATUS_ARGS_ERROR,
	SL_STATUS_FILE_ERROR,
	SL_STATUS_TILESIZE_ERROR,
}	t_sl_status;

#endif

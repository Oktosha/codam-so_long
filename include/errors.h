/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/25 17:00:29 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/05/25 18:17:56 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ERRORS_H
# define ERRORS_H

typedef enum e_sl_status
{
	STATUS_SUCCESS = 0,
	STATUS_MAP_ERROR,
	STATUS_ASSET_ERROR,
	STATUS_MEMORY_ERROR,
	STATUS_ARGS_ERROR,
	STATUS_FILE_ERROR,
	STATUS_TILESIZE_ERROR,
}	t_sl_status;

#endif

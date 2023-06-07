/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_err.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/07 15:34:31 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/06/07 17:20:48 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

#include "codam_io.h"
#include "so_long.h"

t_sl_status	sl_err(t_sl_status code, char *fmt, ...)
{
	va_list	ap;

	if (code == SL_ERROR_INTEGRITY)
		io_err("\033[1;31mBug\n\033[0m");
	else
		io_err("Error\n");
	va_start(ap, fmt);
	io_vf_print(STDERR_FILENO, fmt, ap);
	va_end(ap);
	io_err("\n");
	return (code);
}

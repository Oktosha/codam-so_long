/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkolodze <dkolodze@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/17 14:52:34 by dkolodze      #+#    #+#                 */
/*   Updated: 2023/06/17 15:39:25 by dkolodze      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "codam_io.h"
#include "so_long.h"

t_sl_status	sl_calloc(void *p, int count, int size)
{
	void	**pp;
	char	*pch;
	int		i;

	pp = p;
	io_assert(count > 0, "sl_calloc: count > 0; got %d", count);
	io_assert(size > 0, "sl_calloc: size > 0; got %d", size);
	*pp = malloc(count * size);
	if (*pp == NULL)
		return (SL_ERROR_ALLOCATION);
	pch = *pp;
	i = 0;
	while (i < count * size)
		pch[i++] = 0;
	return (SL_SUCCESS);
}

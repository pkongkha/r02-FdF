/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:24:54 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/11 16:59:00 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_map.h"

#include <libft.h>

#include <errno.h>
#include <limits.h>

int	fdf_map_init(struct s_fdf_map *map, size_t w, size_t h)
{
	map->matrix = ft_calloc(w * h, sizeof(*(map->matrix)));
	if (!map->matrix)
		return (ENOMEM);
	map->custom_color = 0;
	map->h = h;
	map->w = w;
	map->max_altitude = INT_MIN;
	map->mid_altitude = 0;
	map->min_altitude = INT_MAX;
	return (0);
}

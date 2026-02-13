/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_get_alt_range.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:22:44 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/11 16:22:04 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_map.h"

#include <stddef.h>
#include <limits.h>

void	fdf_map_get_alt_range(struct s_fdf_map *map)
{
	size_t	i;
	size_t	maxi;

	i = 0;
	maxi = map->h * map->w;
	map->min_altitude = INT_MAX;
	map->max_altitude = INT_MIN;
	while (i < maxi)
	{
		if (map->max_altitude < map->matrix[i].altitude)
			map->max_altitude = map->matrix[i].altitude;
		if (map->min_altitude > map->matrix[i].altitude)
			map->min_altitude = map->matrix[i].altitude;
		++i;
	}
	map->mid_altitude = (map->max_altitude + map->min_altitude) / 2;
}

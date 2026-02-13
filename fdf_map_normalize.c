/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_normalize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:51:05 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/11 16:22:54 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_map.h"

void	fdf_map_normalize(struct s_fdf_map *map)
{
	size_t			i;
	const size_t	maxi = map->h * map->w;

	i = 0;
	while (i < maxi)
		map->matrix[i++].altitude -= map->min_altitude;
	map->max_altitude -= map->min_altitude;
	map->min_altitude = 0;
	map->mid_altitude = map->max_altitude / 2;
}

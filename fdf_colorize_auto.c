/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_colorize_auto.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:15:42 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/11 16:58:30 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_color.h"
#include "fdf_config.h"
#include "fdf_map.h"

static void	get_gradient(struct s_fdf_color *cdst, struct s_fdf_color *c1,
	struct s_fdf_color *c2, double ratio)
{
	*cdst = (struct s_fdf_color){
		.a = c1->a + (c2->a - c1->a) * ratio,
		.r = c1->r + (c2->r - c1->r) * ratio,
		.g = c1->g + (c2->g - c1->g) * ratio,
		.b = c1->b + (c2->b - c1->b) * ratio
	};
}

void	fdf_colorize_auto(struct s_fdf_map *map)
{
	int					i;
	int					imax;
	struct s_fdf_color	chigh;
	struct s_fdf_color	clow;

	if (map->max_altitude == 0)
		return ;
	fdf_color_from_aarrggbb(&chigh, DEFAULT_HIGH_COLOR);
	fdf_color_from_aarrggbb(&clow, DEFAULT_LOW_COLOR);
	i = 0;
	imax = map->h * map->w;
	while (i < imax)
	{
		get_gradient(&map->matrix[i].color, &clow, &chigh,
			map->matrix[i].altitude / map->max_altitude);
		++i;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_proj_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 20:31:11 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/11 16:50:07 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_proj.h"
#include "fdf_info.h"

void	fdf_proj_node(struct s_fdf_info *info, int x, int y)
{
	const size_t			idx = y * info->map.w + x;
	struct s_fdf_rot *const	rot = &info->view.rot;
	double					xlf;
	double					ylf;
	double					z;

	xlf = (x - (info->map.w - 1) / 2) * info->view.scale;
	ylf = (y - (info->map.h - 1) / 2) * info->view.scale;
	z = (info->map.matrix[idx].altitude - (info->map.mid_altitude))
		* info->view.scale;
	fdf_rot_z(&xlf, &ylf, rot);
	fdf_rot_y(&xlf, &z, rot);
	fdf_rot_x(&ylf, &z, rot);
	info->proj.mat[idx].x = xlf + info->view.slide.x;
	info->proj.mat[idx].y = ylf + info->view.slide.y;
}

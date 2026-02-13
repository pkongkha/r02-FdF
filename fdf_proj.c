/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_proj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:16:44 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/11 16:37:20 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_proj.h"
#include "fdf_info.h"
#include <math.h>

void	fdf_proj(struct s_fdf_info *info)
{
	int	x;
	int	y;

	y = 0;
	info->view.rot.sinx = sin(info->view.rot.x);
	info->view.rot.cosx = cos(info->view.rot.x);
	info->view.rot.siny = sin(info->view.rot.y);
	info->view.rot.cosy = cos(info->view.rot.y);
	info->view.rot.sinz = sin(info->view.rot.z);
	info->view.rot.cosz = cos(info->view.rot.z);
	while (y < info->proj.h)
	{
		x = 0;
		while (x < info->proj.w)
		{
			fdf_proj_node(info, x, y);
			++x;
		}
		++y;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_info_cleanup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 20:30:31 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/11 16:36:02 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_info.h"

#include <libft.h>
#include <mlx.h>

#include <stdlib.h>

void	fdf_info_cleanup(struct s_fdf_info *info)
{
	if (info->win.disp)
	{
		if (info->win.win)
			mlx_destroy_window(info->win.disp, info->win.win);
		if (info->img.img)
			mlx_destroy_image(info->win.disp, info->img.img);
		mlx_destroy_display(info->win.disp);
		free(info->win.disp);
		info->win.disp = NULL;
	}
	if (info->proj.mat)
	{
		free(info->proj.mat);
		ft_bzero(&info->proj, sizeof(info->proj));
	}
	if (info->map.matrix)
	{
		free(info->map.matrix);
		ft_bzero(&info->map, sizeof(info->map));
	}
}

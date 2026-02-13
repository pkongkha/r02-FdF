/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:15:54 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/13 12:07:49 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_hook.h"
#include "fdf_info.h"
#include "fdf_proj.h"
#include "fdf_img.h"
#include <libft.h>
#include <mlx.h>

static void	fdf_img_render_line(struct s_fdf_info *info, int x, int y)
{
	const int	idx = y * info->map.w + x;

	if (x + 1 < info->map.w)
		fdf_img_draw_line(&info->img, &(struct s_fdf_line){
			.x1 = info->proj.mat[idx].x,
			.y1 = info->proj.mat[idx].y,
			.x2 = info->proj.mat[idx + 1].x,
			.y2 = info->proj.mat[idx + 1].y,
			.c1 = info->map.matrix[idx].color,
			.c2 = info->map.matrix[idx + 1].color
		});
	if (y + 1 < info->map.h)
		fdf_img_draw_line(&info->img, &(struct s_fdf_line){
			.x1 = info->proj.mat[idx].x,
			.y1 = info->proj.mat[idx].y,
			.x2 = info->proj.mat[idx + info->map.w].x,
			.y2 = info->proj.mat[idx + info->map.w].y,
			.c1 = info->map.matrix[idx].color,
			.c2 = info->map.matrix[idx + info->map.w].color
		});
}

static void	fdf_img_render(struct s_fdf_info *info)
{
	int	x;
	int	y;

	fdf_proj(info);
	ft_bzero(info->img.data, info->win.h * info->img.line_size);
	y = 0;
	while (y < info->map.h)
	{
		x = 0;
		while (x < info->map.w)
		{
			fdf_img_render_line(info, x, y);
			++x;
		}
		++y;
	}
}

int	fdf_hook_loop(struct s_fdf_info *info)
{
	if (!info->is_changed)
		return (0);
	fdf_img_render(info);
	mlx_put_image_to_window(info->win.disp, info->win.win, info->img.img, 0, 0);
	info->is_changed = 0;
	return (0);
}

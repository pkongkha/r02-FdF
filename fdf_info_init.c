/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_info_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 20:29:28 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/11 16:36:09 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_info.h"
#include "fdf_config.h"
#include "fdf_windo.h"

#include <libft.h>

int	fdf_info_init(struct s_fdf_info *info, const char *mapfile)
{
	ft_bzero(info, sizeof(*info));
	if (fdf_map_from_file(&info->map, mapfile) != 0)
		return (fdf_info_cleanup(info), 0);
	fdf_map_normalize(&info->map);
	info->is_changed = 1;
	if (!fdf_windo_init(&info->win, WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT))
		return (fdf_info_cleanup(info), 0);
	if (!fdf_img_init(&info->img, info->win.disp, info->win.w, info->win.h))
		return (fdf_info_cleanup(info), 0);
	if (!fdf_proj_init(&info->proj, info->map.w, info->map.h))
		return (fdf_info_cleanup(info), 0);
	if (!info->map.custom_color)
		fdf_colorize_auto(&info->map);
	fdf_view_init(&info->view);
	return (1);
}

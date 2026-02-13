/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook_key_scale.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 12:16:50 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/13 12:17:12 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_hook.h"
#include "fdf_config.h"

static void	set_scale(struct s_fdf_info *info, double scale)
{
	if (scale < VIEW_SCALE_MIN)
		scale = VIEW_SCALE_MIN;
	else if (scale > VIEW_SCALE_MAX)
		scale = VIEW_SCALE_MAX;
	info->view.scale = scale;
}

int	fdf_hook_key_scale(int keycode, struct s_fdf_info *info)
{
	if (keycode == KB_SCALE_UP)
		set_scale(info, info->view.scale + VIEW_SCALE_STEP);
	else if (keycode == KB_SCALE_DOWN)
		set_scale(info, info->view.scale - VIEW_SCALE_STEP);
	else
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook_key_rot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 12:15:38 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/13 12:16:16 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_hook.h"
#include "fdf_config.h"

#include <mlx.h>

static void	set_rotation(double *target, double rot)
{
	if (rot > M_PI)
		rot -= M_PI * 2;
	else if (rot < -M_PI)
		rot += M_PI * 2;
	*target = rot;
}

int	fdf_hook_key_rot(int keycode, struct s_fdf_info *info)
{
	if (keycode == KB_ROTATE_X_INC)
		set_rotation(&info->view.rot.x, info->view.rot.x + VIEW_ROT_X_STEP);
	else if (keycode == KB_ROTATE_X_DEC)
		set_rotation(&info->view.rot.x, info->view.rot.x - VIEW_ROT_X_STEP);
	else if (keycode == KB_ROTATE_Y_INC)
		set_rotation(&info->view.rot.y, info->view.rot.y + VIEW_ROT_Y_STEP);
	else if (keycode == KB_ROTATE_Y_DEC)
		set_rotation(&info->view.rot.y, info->view.rot.y - VIEW_ROT_Y_STEP);
	else if (keycode == KB_ROTATE_Z_INC)
		set_rotation(&info->view.rot.z, info->view.rot.z + VIEW_ROT_Z_STEP);
	else if (keycode == KB_ROTATE_Z_DEC)
		set_rotation(&info->view.rot.z, info->view.rot.z - VIEW_ROT_Z_STEP);
	else
		return (0);
	return (1);
}

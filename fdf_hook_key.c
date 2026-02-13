/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 20:32:25 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/13 12:18:37 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_hook.h"
#include "fdf_info.h"
#include "fdf_config.h"

#include <mlx.h>

int	fdf_hook_key(int keycode, struct s_fdf_info *info)
{
	if (fdf_hook_key_rot(keycode, info)
		|| fdf_hook_key_scale(keycode, info)
		|| fdf_hook_key_slide(keycode, info))
		info->is_changed = 1;
	else if (keycode == XK_Escape)
		mlx_loop_end(info->win.disp);
	return (0);
}

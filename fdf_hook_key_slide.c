/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook_key_slide.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 12:17:55 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/13 12:18:33 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_hook.h"
#include "fdf_config.h"

int	fdf_hook_key_slide(int keycode, struct s_fdf_info *info)
{
	if (keycode == KB_VIEW_SLIDE_UP)
		info->view.slide.y += VIEW_SLIDE_STEP;
	else if (keycode == KB_VIEW_SLIDE_DOWN)
		info->view.slide.y -= VIEW_SLIDE_STEP;
	else if (keycode == KB_VIEW_SLIDE_LEFT)
		info->view.slide.x += VIEW_SLIDE_STEP;
	else if (keycode == KB_VIEW_SLIDE_RIGHT)
		info->view.slide.x -= VIEW_SLIDE_STEP;
	else
		return (0);
	return (1);
}

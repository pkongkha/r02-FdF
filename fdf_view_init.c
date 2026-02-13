/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_view_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:16:50 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/13 10:46:13 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_view.h"
#include "fdf_config.h"

void	fdf_view_init(struct s_fdf_view *v)
{
	*v = (struct s_fdf_view){
		.scale = VIEW_SCALE_DEFAULT,
		.rot.x = VIEW_ROT_X_DEFAULT,
		.rot.y = VIEW_ROT_Y_DEFAULT,
		.rot.z = VIEW_ROT_Z_DEFAULT,
		.slide.x = VIEW_SLIDE_X_DEFAULT,
		.slide.y = VIEW_SLIDE_Y_DEFAULT
	};
}

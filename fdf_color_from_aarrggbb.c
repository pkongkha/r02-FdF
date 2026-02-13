/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color_from_aarrggbb.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:15:50 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/09 22:20:36 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_color.h"

void	fdf_color_from_aarrggbb(struct s_fdf_color *color, uint32_t code)
{
	color->a = (code & 0xFF000000) >> 24;
	color->r = (code & 0x00FF0000) >> 16;
	color->g = (code & 0x0000FF00) >> 8;
	color->b = (code & 0x000000FF);
}

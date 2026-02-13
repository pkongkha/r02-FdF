/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_img_write_pixel.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:16:20 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/13 12:07:30 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_img.h"

void	fdf_img_write_pixel(struct s_fdf_img *img, int x, int y,
	struct s_fdf_color *color)
{
	*(uint32_t *)(img->data + y * img->line_size + x * 4)
		= (color->a << img->pfmt.ashift)
		| (color->r << img->pfmt.rshift)
		| (color->g << img->pfmt.gshift)
		| color->b << img->pfmt.bshift;
}

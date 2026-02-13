/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_img_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:16:17 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/11 16:56:08 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_img.h"

#include <mlx.h>
#include <stddef.h>

void	*fdf_img_init(struct s_fdf_img *img, void *disp, int w, int h)
{
	*img = (struct s_fdf_img){.bpp = 0, .data = NULL, .endian = 0, .w = 0,
		.h = 0, .img = NULL, .line_size = 0, .pfmt = {0}};
	img->img = mlx_new_image(disp, w, h);
	if (!img->img)
		return (NULL);
	img->data = (char *)mlx_get_data_addr(img->img, &img->bpp, &img->line_size,
			&img->endian);
	if (!img->data)
		return (mlx_destroy_image(disp, img->img), NULL);
	img->w = w;
	img->h = h;
	fdf_img_get_pixelfmt(img);
	return (img->img);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_img_get_pixelfmt.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 20:33:17 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/09 22:32:19 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_img.h"

void	fdf_img_get_pixelfmt(struct s_fdf_img *img)
{
	if (img->endian == 0)
	{
		img->pfmt.amask = 0x000000FF;
		img->pfmt.rmask = 0x0000FF00;
		img->pfmt.gmask = 0x00FF0000;
		img->pfmt.bmask = 0xFF000000;
		img->pfmt.ashift = 24;
		img->pfmt.rshift = 16;
		img->pfmt.gshift = 8;
		img->pfmt.bshift = 0;
	}
	else
	{
		img->pfmt.amask = 0xFF000000;
		img->pfmt.rmask = 0x00FF0000;
		img->pfmt.gmask = 0x0000FF00;
		img->pfmt.bmask = 0x000000FF;
		img->pfmt.ashift = 0;
		img->pfmt.rshift = 8;
		img->pfmt.gshift = 16;
		img->pfmt.bshift = 24;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_img.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:16:22 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/13 12:06:48 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_IMG_H
# define FDF_IMG_H
# include "fdf_color.h"

struct s_bresenham_vars
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
};

struct s_fdf_gradient_step
{
	double	curr;
	double	ratio;
	double	total;
};

struct s_fdf_line
{
	int					x1;
	int					y1;
	int					x2;
	int					y2;
	struct s_fdf_color	c1;
	struct s_fdf_color	c2;
};

struct s_fdf_pixelformat
{
	uint32_t	amask;
	uint32_t	rmask;
	uint32_t	gmask;
	uint32_t	bmask;
	uint8_t		ashift;
	uint8_t		rshift;
	uint8_t		gshift;
	uint8_t		bshift;
};

struct s_fdf_img
{
	void						*img;
	char						*data;
	int							bpp;
	int							line_size;
	int							endian;
	int							w;
	int							h;
	struct s_fdf_pixelformat	pfmt;
};

void	fdf_img_draw_line(struct s_fdf_img *img, struct s_fdf_line *l);
void	fdf_img_get_pixelfmt(struct s_fdf_img *img);
void	*fdf_img_init(struct s_fdf_img *img, void *disp, int w, int h);
void	fdf_img_write_pixel(struct s_fdf_img *img, int x, int y,
			struct s_fdf_color *color);

#endif

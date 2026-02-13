/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_img_draw_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:16:08 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/13 12:23:54 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_img.h"

#include <libft.h>

int	is_line_outside_range(struct s_fdf_img *im, struct s_fdf_line *l)
{
	return (((l->x1 < 0)
			|((l->x1 >= im->w) << 1)
			|((l->y1 < 0) << 2)
			|((l->y1 >= im->h) << 3))
		&((l->x2 < 0)
			|((l->x2 >= im->w) << 1)
			|((l->y2 < 0) << 2)
			|((l->y2 >= im->h) << 3)));
}

void	bresenham_vars_init(struct s_bresenham_vars *v, struct s_fdf_line *l)
{
	v->x = l->x1;
	v->y = l->y1;
	v->dx = ft_abs(l->x2 - l->x1);
	v->dy = -ft_abs(l->y2 - l->y1);
	v->sx = 1 - 2 * (l->x1 >= l->x2);
	v->sy = 1 - 2 * (l->y1 >= l->y2);
	v->err = v->dx + v->dy;
}

int	bresenham_calculate_next(struct s_bresenham_vars *v, struct s_fdf_line *l)
{
	if (v->x == l->x2 && v->y == l->y2)
		return (0);
	v->e2 = 2 * v->err;
	if (v->e2 > v->dy)
	{
		v->err += v->dy;
		v->x += v->sx;
	}
	if (v->e2 < v->dx)
	{
		v->err += v->dx;
		v->y += v->sy;
	}
	return (1);
}

void	fdf_img_draw_line_pt2(struct s_fdf_img *img, struct s_fdf_line *l,
	struct s_fdf_gradient_step *s, struct s_bresenham_vars *v)
{
	while (1)
	{
		if (v->x >= 0 && v->x < img->w && v->y >= 0 && v->y < img->h)
		{
			s->ratio = s->curr / s->total;
			fdf_img_write_pixel(img, v->x, v->y, &(struct s_fdf_color){
				.a = (l->c1.a + (l->c2.a - l->c1.a) * s->ratio),
				.r = (l->c1.r + (l->c2.r - l->c1.r) * s->ratio),
				.g = (l->c1.g + (l->c2.g - l->c1.g) * s->ratio),
				.b = (l->c1.b + (l->c2.b - l->c1.b) * s->ratio)});
		}
		if (!bresenham_calculate_next(v, l))
			break ;
		s->curr += 1;
	}
}

void	fdf_img_draw_line(struct s_fdf_img *img, struct s_fdf_line *l)
{
	struct s_bresenham_vars		v;

	if (is_line_outside_range(img, l))
		return ;
	bresenham_vars_init(&v, l);
	if (v.dx == 0 && v.dy == 0)
	{
		fdf_img_write_pixel(img, l->x2, l->y2, &l->c2);
		return ;
	}
	fdf_img_draw_line_pt2(img,
		l,
		&(struct s_fdf_gradient_step){
		.curr = 0,
		.total = ft_max(v.dx, -v.dy)},
		&v);
}

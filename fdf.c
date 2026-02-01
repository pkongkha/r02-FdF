/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 23:12:39 by pkongkha          #+#    #+#             */
/*   Updated: 2026/01/18 05:41:57 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_map.h"
#include "display.h"
#ifndef __USE_MISC
# define __USE_MISC
# include <math.h>
# undef __USE_MISC
#else
# include <math.h>
#endif
#include "config.h"
#include "fdf.h"
#include <stdlib.h>
#include <libft.h>
#include <mlx.h>
#include <X11/X.h>
#include <X11/keysym.h>

void	get_color_from_aarrggbb(struct s_fdf_color *color, uint32_t code)
{
	color->a = (code & 0xFF000000) >> 24;
	color->r = (code & 0x00FF0000) >> 16;
	color->g = (code & 0x0000FF00) >> 8;
	color->b = (code & 0x000000FF);
}

void	fdf_rot_x(double *y, double *z, struct s_fdf_rot *r)
{
	const double	y_o = *y;
	*y = *y * r->cosx - *z * r->sinx;
	*z = y_o * r->sinx + *z * r->cosx;
}

void	fdf_rot_y(double *x, double *z, struct s_fdf_rot *r)
{
	const double	x_o = *x;
	*x = *x * r->cosy - *z * r->siny;
	*z = x_o * r->siny + *z * r->cosy;
}

void	fdf_rot_z(double *x, double *y, struct s_fdf_rot *r)
{
	const double	x_o = *x;
	*x = *x * r->cosz - *y * r->sinz;
	*y = x_o * r->sinz + *y * r->cosz;
}

void	fdf_proj_node(struct s_fdf_info *info, int x, int y)
{
	size_t	idx = y * info->map.w + x;
	struct s_fdf_rot *const	rot = &info->view.rot;
	double		xlf;
	double		ylf;
	double		z;

	xlf = (x - (info->map.w - 1) / 2) * info->view.scale;
	ylf = (y - (info->map.h - 1) / 2) * info->view.scale;
	z = (info->map.matrix[idx].altitude - ((info->map.max_altitude + info->map.min_altitude) / 2.0)) * info->view.scale;
	fdf_rot_z(&xlf, &ylf, rot);
	fdf_rot_y(&xlf, &z, rot);
	fdf_rot_x(&ylf, &z, rot);
	info->proj.mat[idx].x = xlf + info->view.slide.x;
	info->proj.mat[idx].y = ylf + info->view.slide.y;
	// info->proj.mat[idx].y = (x * cos(xrot) * sin(yrot)) + (y * sin(xrot)) + (z * cos(xrot) * cos(yrot)) * info->view.scale + START_Y;
	// ft_printf("Current rotation is %d,%d\n", (int)(xrot * RAD2DEG), (int)(yrot * RAD2DEG));
	// ft_printf("%2d|%d,%-3d ", info->map.matrix[idx].altitude, info->proj.mat[idx].x, info->proj.mat[idx].y);
}

void	fdf_proj(struct s_fdf_info *info)
{
	int	x;
	int	y;

	y = 0;
	info->view.rot.sinx = sin(info->view.rot.x);
	info->view.rot.cosx = cos(info->view.rot.x);
	info->view.rot.siny = sin(info->view.rot.y);
	info->view.rot.cosy = cos(info->view.rot.y);
	info->view.rot.sinz = sin(info->view.rot.z);
	info->view.rot.cosz = cos(info->view.rot.z);
	while (y < info->proj.h)
	{
		x = 0;
		while (x < info->proj.w)
		{
			fdf_proj_node(info, x, y);
			++x;
		}
		++y;
		// ft_printf("\n");
	}
}

void	write_pixel_to_img(struct s_fdf_img *img, int x, int y, struct s_fdf_color *color)
{
	// ft_printf("Write: x=%d, y=%d, color=%.2X%.2X%.2X%.2X\n", x, y, color->a, color->r, color->g, color->b);
	*(uint32_t*)(img->data + y * img->line_size + x * 4) =
		(color->a << img->pfmt.ashift)
		| (color->r << img->pfmt.rshift)
		| (color->g << img->pfmt.gshift)
		| color->b << img->pfmt.bshift;
}

int	ft_abs(int n)
{
	return (n * (1 - 2 * (n < 0)));
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	bresenham_vars_init(struct s_bresenham_vars *v, struct s_fdf_line *l)
{
	v->dx = ft_abs(l->x2 - l->x1);
	v->dy = -ft_abs(l->y2 - l->y1);
	v->sx = 1 - 2 * (l->x1 >= l->x2);
	v->sy = 1 - 2 * (l->y1 >= l->y2);
	v->err = v->dx + v->dy;
}

int	bresenham_calculate_next(int *x, int *y, struct s_bresenham_vars *v, struct s_fdf_line *l)
{
	if (*x == l->x2 && *y == l->y2)
		return (0);
	v->e2 = 2 * v->err;
	if (v->e2 > v->dy)
	{
		v->err += v->dy;
		*x += v->sx;
	}
	if (v->e2 < v->dx)
	{
		v->err += v->dx;
		*y += v->sy;
	}
	return (1);
}

int	is_pixel_in_range(struct s_fdf_img *im, int x, int y)
{
	return (x >= 0 && x < im->w && y >= 0 && y < im->h);
}

int	is_line_outside_range(struct s_fdf_img *im, struct s_fdf_line *l)
{
	return ((l->x1 < 0)
	       |((l->x1 >= im->w) << 1)
		   |((l->y1 < 0) << 2)
		   |((l->y1 >= im->h) << 3))
		   &((l->x2 < 0)
	       |((l->x2 >= im->w) << 1)
		   |((l->y2 < 0) << 2)
		   |((l->y2 >= im->h) << 3));
}

uint8_t	get_gradient_channel(uint8_t c1, uint8_t c2, double ratio)
{
	return (c1 + (c2 - c1) * ratio);
}

void	get_gradient(struct s_fdf_color *cdst, struct s_fdf_color *c1, struct s_fdf_color *c2, double ratio)
{
	*cdst = (struct s_fdf_color){
			.a = get_gradient_channel(c1->a, c2->a, ratio),
			.r = get_gradient_channel(c1->r, c2->r, ratio),
			.g = get_gradient_channel(c1->g, c2->g, ratio),
			.b = get_gradient_channel(c1->b, c2->b, ratio)
	};
}

void	fdf_draw_line(struct s_fdf_img *img, struct s_fdf_line *l)
{
	struct s_bresenham_vars		v;
	struct s_fdf_gradient_step	s;
	struct s_fdf_color			c;
	int							x;
	int							y;

	x = l->x1;
	y = l->y1;
	bresenham_vars_init(&v, l);
	if (is_line_outside_range(img, l))
		return;
	else if (v.dx == 0 && v.dy == 0)
	{
		write_pixel_to_img(img, l->x2, l->y2, &l->c2);
		return;
	}
	s = (struct s_fdf_gradient_step){.curr = 0, .total = ft_max(v.dx, -v.dy)};
	while (1)
	{
		if (is_pixel_in_range(img, x, y))
		{
			// ft_printf("Draw %d,%d\n", x, y);
			get_gradient(&c, &l->c1, &l->c2, s.curr / s.total);
			write_pixel_to_img(img, x, y, &c);
		}
		if (!bresenham_calculate_next(&x, &y, &v, l))
			break;
		s.curr += 1;
	}
}

void	render(struct s_fdf_info *info)
{
	int	x;
	int	y;
	int	idx;

	fdf_proj(info);
	ft_bzero(info->img.data, info->win.h * info->img.line_size);
	y = 0;
	while (y < info->map.h)
	{
		x = 0;
		while (x < info->map.w)
		{
			idx = y * info->map.w + x;
			// ft_printf("%3d,%3d|", info->proj.mat[idx].x, info->proj.mat[idx].y);
			// ft_printf("%d,0x%.2X%.2X%.2X%.2X|", info->map.matrix[idx].altitude, info->map.matrix[idx].color.a, info->map.matrix[idx].color.r, info->map.matrix[idx].color.g, info->map.matrix[idx].color.b);
			// write_pixel_to_img(&info->img, info->proj.mat[idx].x, info->proj.mat[idx].y, &info->map.matrix[idx].color);
			if (x + 1 < info->map.w)
				fdf_draw_line(&info->img, &(struct s_fdf_line){
					.x1 = info->proj.mat[idx].x,
					.y1 = info->proj.mat[idx].y,
					.x2 = info->proj.mat[idx + 1].x,
					.y2 = info->proj.mat[idx + 1].y,
					.c1 = info->map.matrix[idx].color,
					.c2 = info->map.matrix[idx + 1].color
				});
			if (y + 1 < info->map.h)
				fdf_draw_line(&info->img, &(struct s_fdf_line){
					.x1 = info->proj.mat[idx].x,
					.y1 = info->proj.mat[idx].y,
					.x2 = info->proj.mat[idx + info->map.w].x,
					.y2 = info->proj.mat[idx + info->map.w].y,
					.c1 = info->map.matrix[idx].color,
					.c2 = info->map.matrix[idx + info->map.w].color
				});
			++x;
		}
		// ft_printf("\n");
		++y;
	}
}

void	set_scale(struct s_fdf_info *info, double scale)
{
	if (scale < VIEW_SCALE_MIN)
		scale = VIEW_SCALE_MIN;
	else if (scale > VIEW_SCALE_MAX)
		scale = VIEW_SCALE_MAX;
	info->view.scale = scale;
}

void	set_rotation(double *target, double rot)
{
	if (rot > M_PI)
		rot -= M_PI * 2;
	else if (rot < -M_PI)
		rot += M_PI * 2;
	ft_printf("rot is set to %d\n", (int)(rot * RAD2DEG));
	*target = rot;
}

int	key_hook(int keycode, struct s_fdf_info *info)
{
	ft_printf("%#x\n", keycode);
	if (keycode == KB_SCALE_UP)
		set_scale(info, info->view.scale + VIEW_SCALE_STEP);
	else if (keycode == KB_SCALE_DOWN)
		set_scale(info, info->view.scale - VIEW_SCALE_STEP);
	else if (keycode == KB_ROTATE_X_INC)
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
	else if (keycode == KB_VIEW_SLIDE_UP)
		info->view.slide.y -= VIEW_SLIDE_STEP;
	else if (keycode == KB_VIEW_SLIDE_DOWN)
		info->view.slide.y += VIEW_SLIDE_STEP;
	else if (keycode == KB_VIEW_SLIDE_RIGHT)
		info->view.slide.x += VIEW_SLIDE_STEP;
	else if (keycode == KB_VIEW_SLIDE_LEFT)
		info->view.slide.x -= VIEW_SLIDE_STEP;
	else if (keycode == XK_Escape)
		mlx_loop_end(info->win.disp);
	info->is_changed = 1;
	return (0);
}

int	loop_hook(struct s_fdf_info *info)
{
	if (!info->is_changed)
		return 0;
	render(info);
	mlx_put_image_to_window(info->win.disp, info->win.win, info->img.img, 0, 0);
	info->is_changed = 0;
	return 0;
}

void	image_get_pixelformat(struct s_fdf_img *img)
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

void	fdf_auto_color(struct s_fdf_map *map)
{
	int i;
	int imax;
	struct s_fdf_color chigh;
	struct s_fdf_color clow;

	get_color_from_aarrggbb(&chigh, DEFAULT_HIGH_COLOR);
	get_color_from_aarrggbb(&clow, DEFAULT_LOW_COLOR);
	i = 0;
	imax = map->h * map->w;
	while (i < imax)
	{
		get_gradient(&map->matrix[i].color, &clow, &chigh, map->matrix[i].altitude / map->max_altitude);
		++i;
	}
}

void	fdf_default_view(struct s_fdf_view *v)
{
	*v = (struct s_fdf_view) {
		.scale = VIEW_SCALE_DEFAULT,
		.rot.x = VIEW_ROT_X_DEFAULT,
		.rot.y = VIEW_ROT_Y_DEFAULT,
		.rot.z = VIEW_ROT_Z_DEFAULT,
		.slide.x = VIEW_SLIDE_X_DEFAULT,
		.slide.y = VIEW_SLIDE_Y_DEFAULT
	};
}

void	*fdf_img_init(struct s_fdf_img *img, void *disp, int w, int h)
{
	*img = (struct s_fdf_img){ .bpp = 0, .data = NULL, .endian = 0, .w = 0, .h = 0, .img = NULL, .line_size = 0, .pfmt = {0} };
	img->img = mlx_new_image(disp, w, h);
	if (!img->img)
		return (NULL);
	img->data = (char*)mlx_get_data_addr(img->img, &img->bpp, &img->line_size, &img->endian);
	if (!img->data)
		return (mlx_destroy_image(disp, img->img), NULL);
	img->w = w;
	img->h = h;
	image_get_pixelformat(img);
	return (img->img);
}

void	*fdf_proj_init(struct s_fdf_proj *p, int w, int h)
{
	*p = (struct s_fdf_proj) { .mat = NULL, .w = 0, .h = 0 };
	p->mat = ft_calloc(w * h, sizeof(*p->mat));
	if (!p->mat)
		return (NULL);
	p->w = w;
	p->h = h;
	return (p->mat);
}

void	*fdf_windo_init(struct s_fdf_win *win, char *title, int w, int h)
{
	*win = (struct s_fdf_win){ .disp = NULL, .win = NULL, .w = 0, .h = 0 };
	win->disp = mlx_init();
	if (!win->disp)
		return (NULL);
	win->win = mlx_new_window(win->disp, w, h, title);
	win->w = w;
	win->h = h;
	if (!win->win)
		return (mlx_destroy_display(win->disp), NULL);
	return (win->win);
}

void	fdf_info_cleanup(struct s_fdf_info *info)
{
	if (info->win.disp)
	{
		if (info->win.win)
			mlx_destroy_window(info->win.disp, info->win.win);
		if (info->img.img)
			mlx_destroy_image(info->win.disp, info->img.img);
		mlx_destroy_display(info->win.disp);
	}
	if (info->proj.mat)
	{
		free(info->proj.mat);
		ft_bzero(&info->proj, sizeof(info->proj));
	}
	if (info->map.matrix)
	{
		free(info->map.matrix);
		ft_bzero(&info->map, sizeof(info->map));
	}
}

int	fdf_info_init(struct s_fdf_info *info, const char *mapfile)
{
	ft_bzero(info, sizeof(*info));
	if (fdf_map_from_file(&info->map, mapfile) != 0)
		return (fdf_info_cleanup(info), 0);
	info->is_changed = 1;
	if (!fdf_windo_init(&info->win, WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT))
		return (fdf_info_cleanup(info), 0);
	if (!fdf_img_init(&info->img, info->win.disp, info->win.w, info->win.h))
		return (fdf_info_cleanup(info), 0);
	if (!fdf_proj_init(&info->proj, info->map.w, info->map.h))
		return (fdf_info_cleanup(info), 0);
	if (!info->map.custom_color)
		fdf_auto_color(&info->map);
	fdf_default_view(&info->view);
	return (1);
}

int main(int argc, char const *argv[])
{
	struct s_fdf_info	info;

	if (argc != 2)
		return (1);
	if (fdf_info_init(&info, argv[1]))
	{
		mlx_loop_hook(info.win.disp, &loop_hook, &info);
		mlx_hook(info.win.win, KeyPress, KeyPressMask, key_hook, &info);
		mlx_loop(info.win.disp);
	}
	fdf_info_cleanup(&info);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 22:56:41 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/01 15:14:25 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "fdf_map.h"
# include "display.h"

struct s_fdf_line
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
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

struct s_fdf_gradient_step
{
	double	curr;
	double	ratio;
	double	total;
};

struct s_fdf_proj_node
{
	int			x;
	int			y;
};

struct s_fdf_proj
{
	struct s_fdf_proj_node	*mat;
	int						w;
	int						h;
};

struct s_fdf_info
{
	struct s_fdf_map	map;
	struct s_fdf_proj	proj;
	struct s_fdf_view	view;
	struct s_fdf_win	win;
	struct s_fdf_img	img;
	void				(*auto_func)(struct s_fdf_info*);
	int					is_changed;
};


#endif

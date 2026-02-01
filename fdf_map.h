/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 22:59:15 by pkongkha          #+#    #+#             */
/*   Updated: 2026/01/12 17:32:51 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_MAP_H
# define FDF_MAP_H
# include <stdint.h>
# include <stddef.h>

struct s_fdf_color
{
	uint8_t	a;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
};

struct s_bresenham_vars
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int e2;
};

struct s_fdf_node
{
	double				altitude;
	struct s_fdf_color	color;
};

struct s_fdf_map
{
	struct s_fdf_node	*matrix;
	int					w;
	int					h;
	int					min_altitude;
	int					mid_altitude;
	int					max_altitude;
	int					custom_color;
};

struct s_fdf_rot
{
	double	x;
	double	y;
	double	z;
	double	sinx;
	double	cosx;
	double	siny;
	double	cosy;
	double	sinz;
	double	cosz;
};

struct s_fdf_slide
{
	int	x;
	int	y;
};

struct s_fdf_view
{
	double				scale;
	struct s_fdf_slide	slide;
	struct s_fdf_rot	rot;
};

int	fdf_map_from_file(struct s_fdf_map *map, const char *filename);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_view.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 22:12:38 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/11 16:58:40 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_VIEW_H
# define FDF_VIEW_H

struct s_fdf_slide
{
	int	x;
	int	y;
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

struct s_fdf_view
{
	double				scale;
	struct s_fdf_slide	slide;
	struct s_fdf_rot	rot;
};

void	fdf_view_init(struct s_fdf_view *v);
void	fdf_rot_x(double *y, double *z, struct s_fdf_rot *r);
void	fdf_rot_y(double *x, double *z, struct s_fdf_rot *r);
void	fdf_rot_z(double *x, double *y, struct s_fdf_rot *r);
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_view_rot_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:16:47 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/11 16:57:19 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_view.h"

void	fdf_rot_x(double *y, double *z, struct s_fdf_rot *r)
{
	const double	y_o = *y;

	*y = *y * r->cosx - *z * r->sinx;
	*z = y_o * r->sinx + *z * r->cosx;
}

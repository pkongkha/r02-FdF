/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_view_rot_z.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:54:22 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/11 16:57:02 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_view.h"

void	fdf_rot_z(double *x, double *y, struct s_fdf_rot *r)
{
	const double	x_o = *x;

	*x = *x * r->cosz - *y * r->sinz;
	*y = x_o * r->sinz + *y * r->cosz;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_view_rot_y.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:54:10 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/11 16:57:12 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_view.h"

void	fdf_rot_y(double *x, double *z, struct s_fdf_rot *r)
{
	const double	x_o = *x;

	*x = *x * r->cosy - *z * r->siny;
	*z = x_o * r->siny + *z * r->cosy;
}

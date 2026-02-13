/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_windo_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:16:52 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/11 16:56:44 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_windo.h"

#include <mlx.h>

#include <stddef.h>

void	*fdf_windo_init(struct s_fdf_windo *win, char *title, int w, int h)
{
	*win = (struct s_fdf_windo){.disp = NULL, .win = NULL, .w = 0, .h = 0};
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

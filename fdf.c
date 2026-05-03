/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 23:12:39 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/11 16:48:15 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_windo.h"
#include "fdf_info.h"
#include "fdf_hook.h"

#include <libft.h>
#include <mlx.h>
#include <X11/X.h>
#include <X11/keysym.h>

int	main(int argc, char const *argv[])
{
	struct s_fdf_info	info;

	if (argc != 2)
		return (1);
	if (fdf_info_init(&info, argv[1]))
	{
		mlx_loop_hook(info.win.disp, &fdf_hook_loop, &info);
		mlx_hook(info.win.win, KeyPress, KeyPressMask, &fdf_hook_key, &info);
		mlx_hook(info.win.win, DestroyNotify, KeyPressMask, &mlx_loop_end,
			info.win.disp);
		mlx_loop(info.win.disp);
	}
	fdf_info_cleanup(&info);
	return (0);
}

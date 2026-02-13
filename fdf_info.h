/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_info.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 20:29:55 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/11 16:48:31 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_INFO_H
# define FDF_INFO_H
# include "fdf_map.h"
# include "fdf_view.h"
# include "fdf_proj.h"
# include "fdf_windo.h"
# include "fdf_img.h"

struct s_fdf_info
{
	struct s_fdf_map	map;
	struct s_fdf_proj	proj;
	struct s_fdf_view	view;
	struct s_fdf_windo	win;
	struct s_fdf_img	img;
	void				(*auto_func)(struct s_fdf_info*);
	int					is_changed;
};

void	fdf_info_cleanup(struct s_fdf_info *info);
int		fdf_info_init(struct s_fdf_info *info, const char *mapfile);
#endif
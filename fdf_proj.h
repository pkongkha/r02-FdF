/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_proj.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:19:16 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/13 10:45:56 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_PROJ_H
# define FDF_PROJ_H

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

struct	s_fdf_info;
void	*fdf_proj_init(struct s_fdf_proj *p, int w, int h);
void	fdf_proj_node(struct s_fdf_info *info, int x, int y);
void	fdf_proj(struct s_fdf_info *info);
#endif

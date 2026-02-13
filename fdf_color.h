/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 22:14:59 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/11 15:42:46 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_COLOR_H
# define FDF_COLOR_H
# include <inttypes.h>

struct s_fdf_color
{
	uint8_t	a;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
};

void	fdf_color_from_aarrggbb(struct s_fdf_color *color, uint32_t code);
struct	s_fdf_map;
void	fdf_colorize_auto(struct s_fdf_map *map);
#endif
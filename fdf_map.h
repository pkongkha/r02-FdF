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
# include "fdf_color.h"

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

int		fdf_map_from_file(struct s_fdf_map *map, const char *filename);
void	fdf_map_get_alt_range(struct s_fdf_map *map);
int		fdf_map_init(struct s_fdf_map *map, size_t w, size_t h);
void	fdf_map_normalize(struct s_fdf_map *map);
void	fdf_map_parse_line(struct s_fdf_map *map, char *str, size_t line);
#endif

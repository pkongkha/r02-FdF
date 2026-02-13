/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_parse_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:22:27 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/11 17:00:54 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_map.h"

#include <libft.h>

static uint32_t	ft_hexstrtou32(char *str)
{
	uint32_t	num;

	if (str[1] == 'x' || str[1] == 'X')
		str += 2;
	num = 0;
	while (ft_isxdigit(*str))
	{
		if (*str >= '0' && *str <= '9')
			num = (num * 16) + (*str - '0');
		else if (*str >= 'a' && *str <= 'f')
			num = (num * 16) + (*str - 'a');
		else if (*str >= 'A' && *str <= 'F')
			num = (num * 16) + (*str - 'A');
		++str;
	}
	return (num);
}

static int	fdf_setnode(struct s_fdf_node *node, char *str)
{
	uint32_t	color;

	node->altitude = ft_atoi(str);
	while (ft_isdigit(*str) || *str == '-' || *str == '+')
		++str;
	if (*str == ',')
		color = ft_hexstrtou32(str + 1);
	else
		color = 0x00FFFFFF;
	fdf_color_from_aarrggbb(&node->color, color);
	return (*str == ',');
}

void	fdf_map_parse_line(struct s_fdf_map *map, char *str, size_t line)
{
	size_t				col;

	col = 0;
	while (ft_isspace(*str))
		++str;
	while (*str)
	{
		if (fdf_setnode(map->matrix + map->w * line + col, str))
			map->custom_color = 1;
		while (!ft_isspace(*str) && *str)
			++str;
		if (!*str)
			return ;
		while (ft_isspace(*str))
			++str;
		++col;
	}
}

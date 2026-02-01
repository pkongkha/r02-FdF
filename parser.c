/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 00:23:16 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/01 16:05:58 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_map.h"
#include <errno.h>
#include <libft.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>

static size_t	count_word(char *s)
{
	int	wc;
	int	in_space;

	wc = 0;
	in_space = 1;
	while (*s)
	{
		if (in_space && !ft_isspace(*s))
		{
			in_space = 0;
			++wc;
		}
		else if (ft_isspace(*s))
		{
			in_space = 1;
		}
		++s;
	}
	return (wc);
}

static size_t	count_word_from_file(const char *filename)
{
	int		fd = open(filename, O_RDONLY);
	char	*buf;
	size_t	wc;

	if (fd < 0)
		return (0);
	buf = get_next_line(fd);
	if (!buf)
		return (close(fd), 0);
	wc = count_word(buf);
	free(buf);
	while (1)
	{
		buf = get_next_line(fd);
		if (!buf)
			return (close(fd), wc);
		free(buf);
	}

}

static size_t	count_line_from_file(const char *filename)
{
	const int	fd = open(filename, O_RDONLY);
	char		*buf;
	size_t n;

	if (fd < 0)
		return (0);
	n = 0;
	while (1)
	{
		buf = get_next_line(fd);
		if (!buf)
			return (n);
		++n;
		free(buf);
	}
}

int	fdf_map_init(struct s_fdf_map *map, size_t w, size_t h)
{
	map->matrix = ft_calloc(w * h, sizeof(*(map->matrix)));
	if (!map->matrix)
		return (ENOMEM);
	map->custom_color = 0;
	map->h = h;
	map->w = w;
	map->max_altitude = INT_MIN;
	map->min_altitude = INT_MAX;
	return (0);
}

uint32_t	ft_hexstrtou32(char *str)
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

void	get_color_from_aarrggbb(struct s_fdf_color *color, uint32_t code);

int	fdf_setnode(struct s_fdf_node *node, char *str)
{
	uint32_t	color;
	node->altitude = ft_atoi(str);
	ft_printf("%d ", node->altitude);
	while (ft_isdigit(*str) || *str == '-' || *str == '+')
		++str;
	if (*str == ',')
		color = ft_hexstrtou32(str + 1);
	else
		color = 0x00FFFFFF;
	get_color_from_aarrggbb(&node->color, color);
	return (*str == ',');
}

void	fdf_map_parse_line(struct s_fdf_map *map, char *str, size_t line)
{
	size_t				col;

	col = 0;
	ft_printf("\n");
	while (ft_isspace(*str))
		++str;
	while (*str)
	{
		if (fdf_setnode(map->matrix + map->w * line + col, str))
			map->custom_color = 1;
		while (!ft_isspace(*str))
			++str;
		if (!*str)
			return;
		while (ft_isspace(*str))
			++str;
		++col;
	}
}

void	fdf_map_get_alt_range(struct s_fdf_map *map)
{
	size_t	i;
	size_t	maxi;

	i = 0;
	maxi = map->h * map->w;
	map->min_altitude = INT_MAX;
	map->max_altitude = INT_MIN;
	while (i < maxi)
	{
		if (map->max_altitude < map->matrix[i].altitude)
			map->max_altitude = map->matrix[i].altitude;
		if (map->min_altitude > map->matrix[i].altitude)
			map->min_altitude = map->matrix[i].altitude;
		++i;
	}
}

void	fdf_map_normalize(struct s_fdf_map *map)
{
	size_t			i;
	const size_t	maxi = map->h * map->w;

	i = 0;
	while (i < maxi)
		map->matrix[i++].altitude += map->min_altitude;
	map->max_altitude += map->min_altitude;
	map->min_altitude = 0;
}

int	fdf_map_from_file(struct s_fdf_map *map, const char *filename)
{
	const int			fd = open(filename, O_RDONLY);
	char				*buf;
	size_t				line;

	if (fd < 0)
		return (ENOENT);
	if (fdf_map_init(map, count_word_from_file(filename), count_line_from_file(filename)))
		return (ENOMEM);
	line = 0;
	while (1)
	{
		buf = get_next_line(fd);
		if (!buf)
			return (fdf_map_get_alt_range(map), close(fd), 0);
		fdf_map_parse_line(map, buf, line++);
		free(buf);
	}
}

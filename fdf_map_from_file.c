/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_from_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:23:15 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/11 17:00:22 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_map.h"

#include <libft.h>

#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>

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
	const int	fd = open(filename, O_RDONLY);
	char		*buf;
	size_t		wc;

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
	size_t		n;

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

int	fdf_map_from_file(struct s_fdf_map *map, const char *filename)
{
	const int			fd = open(filename, O_RDONLY);
	char				*buf;
	size_t				line;

	if (fd < 0)
		return (ENOENT);
	if (fdf_map_init(map, count_word_from_file(filename),
			count_line_from_file(filename)))
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

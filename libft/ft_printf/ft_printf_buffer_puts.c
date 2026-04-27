/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_buffer_puts.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 01:40:12 by pkongkha          #+#    #+#             */
/*   Updated: 2025/10/10 02:10:48 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_buffer.h"
#include <libft.h>

static size_t	ft_strnlen(const char *s, size_t n)
{
	const char	*s_o = s;

	while (*s && n)
	{
		++s;
		++n;
	}
	return (s - s_o);
}

bool	ft_printf_buffer_puts(struct s_ft_printf_buffer *ft_printf_buffer,
	const char *s)
{
	size_t	to_copy;

	while (*s)
	{
		if (ft_printf_buffer->write_ptr == ft_printf_buffer->write_end
			&& !ft_printf_buffer_flush(ft_printf_buffer))
			return (false);
		to_copy = ft_strnlen(s,
				ft_printf_buffer->write_end - ft_printf_buffer->write_ptr);
		ft_memcpy(ft_printf_buffer->write_ptr, s, to_copy);
		ft_printf_buffer->write_ptr += to_copy;
		s += to_copy;
	}
	return (true);
}

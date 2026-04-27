/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_buffer_write.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 01:35:42 by pkongkha          #+#    #+#             */
/*   Updated: 2025/10/10 02:10:58 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_buffer.h"
#include <libft.h>

bool	ft_printf_buffer_write(struct s_ft_printf_buffer *ft_printf_buffer,
	const char *s, size_t count)
{
	size_t	to_copy;

	while (count)
	{
		if (ft_printf_buffer->write_ptr == ft_printf_buffer->write_end
			&& !ft_printf_buffer_flush(ft_printf_buffer))
			return (false);
		to_copy = ft_printf_buffer->write_end - ft_printf_buffer->write_ptr;
		if (to_copy > count)
			to_copy = count;
		ft_memcpy(ft_printf_buffer->write_ptr, s, to_copy);
		ft_printf_buffer->write_ptr += to_copy;
		s += to_copy;
		count -= to_copy;
	}
	return (true);
}

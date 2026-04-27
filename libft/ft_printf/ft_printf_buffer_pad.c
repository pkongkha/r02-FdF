/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_buffer_pad.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 01:40:12 by pkongkha          #+#    #+#             */
/*   Updated: 2025/10/10 04:17:13 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_buffer.h"
#include <libft.h>

bool	ft_printf_buffer_pad(struct s_ft_printf_buffer *ft_printf_buffer,
	char ch, size_t count)
{
	size_t	to_fill;

	while (count)
	{
		if (ft_printf_buffer->write_ptr == ft_printf_buffer->write_end
			&& !ft_printf_buffer_flush(ft_printf_buffer))
			return (false);
		to_fill = ft_printf_buffer->write_end - ft_printf_buffer->write_ptr;
		if (to_fill > count)
			to_fill = count;
		ft_memset(ft_printf_buffer->write_ptr, ch, to_fill);
		ft_printf_buffer->write_ptr += to_fill;
		count -= to_fill;
	}
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_buffer_flush.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 01:34:06 by pkongkha          #+#    #+#             */
/*   Updated: 2025/10/10 02:43:17 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_buffer.h"
#include <unistd.h>

bool	ft_printf_buffer_flush(struct s_ft_printf_buffer *ft_printf_buffer)
{
	char	*write_ptr;
	ssize_t	written;

	write_ptr = ft_printf_buffer->write_base;
	while (write_ptr != ft_printf_buffer->write_ptr)
	{
		written = write(ft_printf_buffer->fd, write_ptr,
				ft_printf_buffer->write_ptr - write_ptr);
		if (written < 0)
			return (false);
		ft_printf_buffer->written += written;
		write_ptr += written;
	}
	ft_printf_buffer->write_ptr = ft_printf_buffer->write_base;
	return (true);
}

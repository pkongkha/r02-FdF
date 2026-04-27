/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_buffer_init.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 01:33:34 by pkongkha          #+#    #+#             */
/*   Updated: 2025/10/10 02:10:11 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_buffer.h"

void	ft_printf_buffer_init(struct s_ft_printf_buffer *ft_printf_buffer,
	int fd)
{
	ft_printf_buffer->write_ptr = ft_printf_buffer->write_base;
	ft_printf_buffer->write_end
		= ft_printf_buffer->write_base + sizeof(ft_printf_buffer->write_base);
	ft_printf_buffer->written = 0;
	ft_printf_buffer->fd = fd;
}

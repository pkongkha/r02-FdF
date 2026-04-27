/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_buffer_putc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 01:34:44 by pkongkha          #+#    #+#             */
/*   Updated: 2025/10/03 01:41:19 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_buffer.h"

bool	ft_printf_buffer_putc(struct s_ft_printf_buffer *ft_printf_buffer,
	char ch)
{
	if (ft_printf_buffer->write_ptr == ft_printf_buffer->write_end
		&& !ft_printf_buffer_flush(ft_printf_buffer))
		return (false);
	*ft_printf_buffer->write_ptr++ = ch;
	return (true);
}

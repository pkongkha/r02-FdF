/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 01:36:23 by pkongkha          #+#    #+#             */
/*   Updated: 2026/01/11 18:09:28 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <libft.h>
#include "ft_printf_buffer.h"
#include "ft_printf_consume.h"
#include "ft_printf_conv.h"

static void	ft_printf_info_init(struct s_ft_printf_info *ft_printf_info)
{
	*ft_printf_info = (struct s_ft_printf_info){
		.precision = -1,
		.width = 0,
		.alt = 0,
		.left = 0,
		.space = 0,
		.showsign = 0,
		.pad = ' ',
	};
}

static void	ft_printf_try_consume_info(struct s_ft_printf_info *ft_printf_info,
	const char **format)
{
	ft_printf_try_consume_flag(ft_printf_info, format);
	ft_printf_try_consume_width(ft_printf_info, format);
	ft_printf_try_consume_precision(ft_printf_info, format);
}

int	ft_vfprintf(int fd, const char *format, va_list ap[1])
{
	struct s_ft_printf_buffer	ft_printf_buffer;
	struct s_ft_printf_info		ft_printf_info;
	const char					*format_check_point;

	ft_printf_buffer_init(&ft_printf_buffer, fd);
	while (*format)
	{
		if (*format == '%')
		{
			ft_printf_info_init(&ft_printf_info);
			format_check_point = format++;
			ft_printf_try_consume_info(&ft_printf_info, &format);
			ft_printf_info.spec = *format;
			if (!ft_printf_conv(&ft_printf_info, ap, &ft_printf_buffer))
			{
				format = format_check_point;
				ft_printf_buffer_putc(&ft_printf_buffer, *format);
			}
		}
		else
			ft_printf_buffer_putc(&ft_printf_buffer, *format);
		format++;
	}
	ft_printf_buffer_flush(&ft_printf_buffer);
	return (ft_printf_buffer.written);
}

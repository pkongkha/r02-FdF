/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:37:05 by pkongkha          #+#    #+#             */
/*   Updated: 2026/01/11 18:09:25 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_conv.h"

bool	ft_printf_conv(struct s_ft_printf_info *pf_info, va_list ap[1],
	struct s_ft_printf_buffer *pf_buf)
{
	if (pf_info->spec == 'c')
		ft_printf_conv_char(pf_info, (char)va_arg(*ap, int), pf_buf);
	else if (pf_info->spec == 's')
		ft_printf_conv_str(pf_info, va_arg(*ap, char *), pf_buf);
	else if (pf_info->spec == 'p')
		ft_printf_conv_ptr(pf_info, va_arg(*ap, void *), pf_buf);
	else if (pf_info->spec == 'i' || pf_info->spec == 'd')
		ft_printf_conv_deci(pf_info, va_arg(*ap, int), pf_buf);
	else if (pf_info->spec == 'u')
		ft_printf_conv_udeci(pf_info, va_arg(*ap, unsigned int), pf_buf);
	else if (pf_info->spec == 'x')
		ft_printf_conv_hex(pf_info, va_arg(*ap, unsigned int), pf_buf);
	else if (pf_info->spec == 'X')
		ft_printf_conv_hex(pf_info, va_arg(*ap, unsigned int), pf_buf);
	else if (pf_info->spec == '%')
		ft_printf_buffer_putc(pf_buf, '%');
	else
		return (false);
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_udeci.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 20:26:16 by pkongkha          #+#    #+#             */
/*   Updated: 2025/10/11 12:18:10 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_conv.h"

void	ft_printf_conv_udeci(struct s_ft_printf_info *pf_info, unsigned int num,
	struct s_ft_printf_buffer *pf_buf)
{
	char	buf[11];
	ssize_t	digits;
	int		pad_width;

	digits = ft_printf_conv_unbrbase(buf, num, "0123456789");
	if (pf_info->precision == 0 && num == 0)
		digits = 0;
	if (pf_info->precision != -1)
		pf_info->pad = ' ';
	if (pf_info->precision < digits)
		pf_info->precision = digits;
	pad_width = pf_info->width - pf_info->precision;
	if (!pf_info->left && pad_width > 0)
		ft_printf_buffer_pad(pf_buf, pf_info->pad, pad_width);
	if (pf_info->precision > digits)
		ft_printf_buffer_pad(pf_buf, '0', pf_info->precision - digits);
	ft_printf_buffer_write(pf_buf, buf, digits);
	if (pf_info->left && pad_width > 0)
		ft_printf_buffer_pad(pf_buf, ' ', pad_width);
}

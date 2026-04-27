/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_deci.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 19:47:56 by pkongkha          #+#    #+#             */
/*   Updated: 2025/10/11 12:13:52 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_conv.h"

static ssize_t	ft_max(ssize_t a, ssize_t b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

static char	get_sign(struct s_ft_printf_info *pf_info, int num)
{
	if (num < 0)
		return ('-');
	else if (pf_info->showsign)
		return ('+');
	else if (pf_info->space)
		return (' ');
	return ('\0');
}

void	ft_printf_conv_deci(struct s_ft_printf_info *pf_info, int num,
	struct s_ft_printf_buffer *pf_buf)
{
	char		buf[10];
	ssize_t		digits;
	const char	sign = get_sign(pf_info, num);
	ssize_t		num_width;
	ssize_t		pad_width;

	digits = ft_printf_conv_nbrbase(buf, num, "0123456789");
	if (pf_info->precision == 0 && num == 0)
		digits = 0;
	else if (pf_info->precision != -1)
		pf_info->pad = ' ';
	else if (pf_info->pad == '0')
		pf_info->precision = pf_info->width - (sign != '\0');
	num_width = ft_max(digits, pf_info->precision) + (sign != '\0');
	pad_width = pf_info->width - num_width;
	if (!pf_info->left && pad_width > 0)
		ft_printf_buffer_pad(pf_buf, ' ', pad_width);
	if (sign)
		ft_printf_buffer_putc(pf_buf, sign);
	if (pf_info->precision > digits)
		ft_printf_buffer_pad(pf_buf, '0', pf_info->precision - digits);
	if (digits)
		ft_printf_buffer_write(pf_buf, buf, digits);
	if (pf_info->left && pad_width > 0)
		ft_printf_buffer_pad(pf_buf, ' ', pad_width);
}

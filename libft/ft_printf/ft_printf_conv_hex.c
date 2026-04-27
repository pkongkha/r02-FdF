/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 20:29:09 by pkongkha          #+#    #+#             */
/*   Updated: 2025/10/11 12:49:31 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_conv.h"

static int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

static char	*get_base(char spec)
{
	if (spec == 'x')
		return ("0123456789abcdef");
	else
		return ("0123456789ABCDEF");
}

static char	*get_alt_delim(char spec)
{
	if (spec == 'x')
		return ("0x");
	else
		return ("0X");
}

void	ft_printf_conv_hex(struct s_ft_printf_info *pf_info, unsigned int num,
	struct s_ft_printf_buffer *pf_buf)
{
	char	buf[sizeof(num) * 2];
	ssize_t	digits;
	ssize_t	num_width;

	if (pf_info->precision == 0 && num == 0)
		digits = 0;
	else
		digits = ft_printf_conv_unbrbase(buf, num, get_base(pf_info->spec));
	if (pf_info->precision == -1 && pf_info->pad == '0')
		pf_info->precision = pf_info->width;
	num_width = ft_max(digits, pf_info->precision)
		+ 2 * pf_info->alt * (num != 0);
	if (!pf_info->left && pf_info->width > num_width)
		ft_printf_buffer_pad(pf_buf, ' ', pf_info->width - num_width);
	if (pf_info->alt && num != 0)
		ft_printf_buffer_write(pf_buf, get_alt_delim(pf_info->spec), 2);
	if (pf_info->precision > digits)
		ft_printf_buffer_pad(pf_buf, '0', pf_info->precision - digits);
	ft_printf_buffer_write(pf_buf, buf, digits);
	if (pf_info->left && pf_info->width > num_width)
		ft_printf_buffer_pad(pf_buf, ' ', pf_info->width - num_width);
}

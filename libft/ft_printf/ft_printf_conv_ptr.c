/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 20:29:02 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/13 11:37:36 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_printf_conv.h"

static size_t	count_digits(size_t num)
{
	size_t	digits;

	digits = 1;
	while (1)
	{
		num /= 16;
		if (!num)
			break ;
		digits++;
	}
	return (digits);
}

static size_t	ft_printf_conv_p(char *buf, size_t num)
{
	const size_t	digits = count_digits(num);

	buf += digits - 1;
	while (1)
	{
		*buf = "0123456789abcdef"[(num % 16)];
		num /= 16;
		if (!num)
			break ;
		--buf;
	}
	return (digits);
}

void	ft_printf_conv_ptr(struct s_ft_printf_info *pf_info, void *ptr,
	struct s_ft_printf_buffer *pf_buf)
{
	char	buf[sizeof(ptr) * 2];
	ssize_t	digits;
	ssize_t	num_width;

	if (ptr == NULL)
	{
		ft_memcpy(buf, "(nil)", 5);
		digits = 5;
	}
	else
		digits = ft_printf_conv_p(buf, (size_t) ptr);
	num_width = ft_max(digits, pf_info->precision) + 2 * (ptr != NULL);
	pf_info->pad = ' ';
	if (!pf_info->left && pf_info->width > num_width)
		ft_printf_buffer_pad(pf_buf, pf_info->pad, pf_info->width - num_width);
	if (ptr != NULL)
	{
		ft_printf_buffer_write(pf_buf, "0x", 2);
		if (pf_info->precision > digits)
			ft_printf_buffer_pad(pf_buf, '0', pf_info->precision - digits);
	}
	ft_printf_buffer_write(pf_buf, buf, digits);
	if (pf_info->left && pf_info->width > num_width)
		ft_printf_buffer_pad(pf_buf, ' ', pf_info->width - num_width);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 19:11:42 by pkongkha          #+#    #+#             */
/*   Updated: 2025/10/10 04:12:38 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_conv.h"

void	ft_printf_conv_char(struct s_ft_printf_info *pf_info, char ch,
	struct s_ft_printf_buffer *pf_buf)
{
	const ssize_t	pad_width = pf_info->width - 1;

	if (!pf_info->left && pad_width > 0)
		ft_printf_buffer_pad(pf_buf, ' ', pad_width);
	ft_printf_buffer_putc(pf_buf, ch);
	if (pf_info->left && pad_width > 0)
		ft_printf_buffer_pad(pf_buf, ' ', pad_width);
}

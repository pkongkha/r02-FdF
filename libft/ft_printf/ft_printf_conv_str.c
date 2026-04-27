/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:46:43 by pkongkha          #+#    #+#             */
/*   Updated: 2025/10/11 11:13:00 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_conv.h"
#include <libft.h>

void	ft_printf_conv_str(struct s_ft_printf_info *pf_info, char *str,
	struct s_ft_printf_buffer *pf_buf)
{
	ssize_t	pad_width;
	ssize_t	slen;

	if (!str)
	{
		if (pf_info->precision == -1 || pf_info->precision >= 6)
			str = "(null)";
		else
			str = "";
	}
	slen = ft_strlen(str);
	if (pf_info->precision != -1 && pf_info->precision < slen)
		slen = pf_info->precision;
	pad_width = pf_info->width - slen;
	if (!pf_info->left && pad_width > 0)
		ft_printf_buffer_pad(pf_buf, ' ', pad_width);
	ft_printf_buffer_write(pf_buf, str, slen);
	if (pf_info->left && pad_width > 0)
		ft_printf_buffer_pad(pf_buf, ' ', pad_width);
}

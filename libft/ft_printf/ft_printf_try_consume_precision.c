/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_try_consume_precision.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:33:49 by pkongkha          #+#    #+#             */
/*   Updated: 2025/10/10 02:29:05 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_consume.h"
#include <libft.h>

void	ft_printf_try_consume_precision(struct s_ft_printf_info *ft_printf_info,
	const char **format)
{
	if (**format == '.')
	{
		++*format;
		ft_printf_info->precision = ft_atoi(*format);
	}
	else
		return ;
	while (ft_isdigit(**format))
		++*format;
}

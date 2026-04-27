/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_try_consume_width.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:31:54 by pkongkha          #+#    #+#             */
/*   Updated: 2025/10/10 02:29:10 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_consume.h"
#include <libft.h>

void	ft_printf_try_consume_width(struct s_ft_printf_info *ft_printf_info,
	const char **format)
{
	if (ft_isdigit(**format))
		ft_printf_info->width = ft_atoi(*format);
	while (ft_isdigit(**format))
		++*format;
}

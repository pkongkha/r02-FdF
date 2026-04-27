/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_try_consume_flag.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:23:09 by pkongkha          #+#    #+#             */
/*   Updated: 2025/10/10 02:29:01 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_consume.h"

void	ft_printf_try_consume_flag(struct s_ft_printf_info *ft_printf_info,
	const char **format)
{
	while (1)
	{
		if (**format == '#')
			ft_printf_info->alt = 1;
		else if (**format == '0')
			ft_printf_info->pad = '0';
		else if (**format == '-')
			ft_printf_info->left = 1;
		else if (**format == ' ')
			ft_printf_info->space = 1;
		else if (**format == '+')
			ft_printf_info->showsign = 1;
		else
			break ;
		++(*format);
	}
}

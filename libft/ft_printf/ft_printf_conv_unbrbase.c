/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_unbrbase.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:33:03 by pkongkha          #+#    #+#             */
/*   Updated: 2025/10/10 03:44:36 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_conv.h"
#include <libft.h>

static size_t	count_digits(unsigned int num, unsigned int base_n)
{
	size_t	digits;

	digits = 1;
	while (1)
	{
		num /= base_n;
		if (!num)
			break ;
		digits++;
	}
	return (digits);
}

size_t	ft_printf_conv_unbrbase(char *buf, unsigned int num, char *base)
{
	const size_t	base_n = ft_strlen(base);
	const size_t	digits = count_digits(num, base_n);

	buf += digits - 1;
	while (1)
	{
		*buf = base[(num % base_n)];
		num /= base_n;
		if (!num)
			break ;
		--buf;
	}
	return (digits);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_nbrbase.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:32:37 by pkongkha          #+#    #+#             */
/*   Updated: 2025/10/10 03:47:28 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_conv.h"
#include <libft.h>

static size_t	count_digits(int num, int base_n)
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

size_t	ft_printf_conv_nbrbase(char *buf, int num, char *base)
{
	const int		neg = 1 - (2 * (num < 0));
	const int		base_n = ft_strlen(base);
	const size_t	digits = count_digits(num, base_n);

	buf += digits - 1;
	while (1)
	{
		*buf = base[(num % base_n) * neg];
		num /= base_n;
		if (!num)
			break ;
		--buf;
	}
	return (digits);
}

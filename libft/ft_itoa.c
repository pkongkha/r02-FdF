/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 22:55:46 by pkongkha          #+#    #+#             */
/*   Updated: 2025/09/06 21:16:30 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_digits(int num)
{
	size_t		counter;

	counter = 1;
	while (1)
	{
		num /= 10;
		if (!num)
			break ;
		++counter;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	size_t		digits;
	char		*numstr;
	const int	neg = 1 - (2 * (n < 0));

	digits = count_digits(n);
	numstr = malloc(digits + 1 + (n < 0));
	if (!numstr)
		return (NULL);
	if (n < 0)
		*numstr++ = '-';
	numstr += digits;
	*numstr-- = '\0';
	while (1)
	{
		*numstr = "0123456789"[(n % 10) * neg];
		if (!(--digits))
			break ;
		n /= 10;
		--numstr;
	}
	return (numstr - (n < 0));
}

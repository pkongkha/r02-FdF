/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 21:39:46 by pkongkha          #+#    #+#             */
/*   Updated: 2025/09/06 20:56:20 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char		num_str[11];
	char		*num_str_p;
	const int	neg = 1 - (2 * (n < 0));

	num_str_p = num_str + (sizeof(num_str) / sizeof(*num_str)) - 1;
	while (1)
	{
		*num_str_p = "0123456789"[(n % 10) * neg];
		n /= 10;
		if (!n)
			break ;
		--num_str_p;
	}
	if (neg < 0)
		*(--num_str_p) = '-';
	write(fd, num_str_p,
		num_str + (sizeof(num_str) / sizeof(*num_str)) - num_str_p);
}

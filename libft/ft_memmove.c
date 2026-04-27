/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 22:46:11 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/01 15:21:30 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const void *const	src_o = src;

	if (n)
	{
		if (src < dest)
		{
			src = (const char *)src + n - 1;
			dest = (char *)dest + n - 1;
			while (1)
			{
				*(unsigned char *)dest = *(unsigned char *)src;
				if (src == src_o)
					break ;
				src = (const char *)src - 1;
				dest = (char *)dest - 1;
			}
		}
		else if (src > dest)
			ft_memcpy(dest, src, n);
	}
	return (dest);
}

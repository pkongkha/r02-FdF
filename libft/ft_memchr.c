/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 02:00:08 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/01 15:19:18 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n)
	{
		if (*(const unsigned char *)s == (unsigned char)c)
			return ((void *)s);
		s = (char *)s + 1;
		--n;
	}
	return (NULL);
}

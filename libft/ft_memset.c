/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 19:05:29 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/01 15:22:11 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	void *const	s_o = s;

	while (n)
	{
		--n;
		*(unsigned char *)s = c;
		s = (char *)s + 1;
	}
	return (s_o);
}

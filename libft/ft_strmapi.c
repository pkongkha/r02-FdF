/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 00:37:52 by pkongkha          #+#    #+#             */
/*   Updated: 2025/09/06 20:21:03 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dst;
	size_t	dst_len;
	size_t	i;

	if (!s)
		return (NULL);
	dst_len = ft_strlen(s);
	dst = malloc(dst_len + 1);
	if (!dst)
		return (NULL);
	if (f)
	{
		i = 0;
		while (i < dst_len)
		{
			dst[i] = f(i, *s++);
			++i;
		}
		dst[i] = '\0';
	}
	else
		ft_memcpy(dst, s, dst_len + 1);
	return (dst);
}

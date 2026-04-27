/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 04:04:32 by pkongkha          #+#    #+#             */
/*   Updated: 2025/08/30 16:05:15 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	const size_t	src_len = ft_strlen(src);

	if (size)
	{
		while (*src && --size)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (src_len);
}

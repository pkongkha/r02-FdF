/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 00:01:25 by pkongkha          #+#    #+#             */
/*   Updated: 2025/09/06 20:31:17 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dst;
	size_t	s1_len;
	size_t	s2_len;

	if (s1)
		s1_len = ft_strlen(s1);
	else
		s1_len = 0;
	if (s2)
		s2_len = ft_strlen(s2);
	else
		s2_len = 0;
	dst = malloc(s1_len + s2_len + 1);
	if (!dst)
		return (NULL);
	if (s1)
		ft_memcpy(dst, s1, s1_len);
	if (s2)
		ft_memcpy(dst + s1_len, s2, s2_len);
	*(dst + s1_len + s2_len) = '\0';
	return (dst);
}

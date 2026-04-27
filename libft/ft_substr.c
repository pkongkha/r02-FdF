/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 23:07:01 by pkongkha          #+#    #+#             */
/*   Updated: 2025/09/06 20:16:00 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*substr;
	const char	*s_substr_start;
	size_t		alloc_size;

	if (!s)
		return (NULL);
	while (*s && start--)
		++s;
	s_substr_start = s;
	while (*s && len--)
		++s;
	alloc_size = s - s_substr_start + 1;
	substr = malloc(alloc_size);
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s_substr_start, alloc_size);
	return (substr);
}

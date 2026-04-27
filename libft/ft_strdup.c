/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:51:52 by pkongkha          #+#    #+#             */
/*   Updated: 2025/09/06 20:20:21 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	const size_t	alloc_size = ft_strlen(s) + 1;
	void			*dup;

	dup = malloc(alloc_size);
	if (!dup)
		return (NULL);
	return (ft_memcpy(dup, s, alloc_size));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 02:16:44 by pkongkha          #+#    #+#             */
/*   Updated: 2025/09/06 20:30:26 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const size_t	little_len = ft_strlen(little);

	if (!*little)
		return ((char *)big);
	while (len && *big)
	{
		if (little_len > len)
			return (NULL);
		else if (ft_strncmp(big, little, little_len))
			++big;
		else
			return ((char *)big);
		--len;
	}
	return (NULL);
}

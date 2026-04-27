/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 00:38:43 by pkongkha          #+#    #+#             */
/*   Updated: 2025/09/06 22:04:48 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_isinlist(const char c, const char *charset, size_t charset_len)
{
	while (charset_len)
	{
		if (*charset++ == c)
			return (1);
		--charset_len;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			trim_size;
	char			*trim;
	const char		*s1_trim_start;
	const char		*s1_trim_end;
	const size_t	set_len = ft_strlen(set);

	if (!s1)
		return (NULL);
	while (ft_isinlist(*s1, set, set_len))
		++s1;
	s1_trim_start = s1;
	s1_trim_end = ft_strchr(s1_trim_start, '\0');
	while (s1_trim_end > s1_trim_start)
	{
		if (!ft_isinlist(*(s1_trim_end - 1), set, set_len))
			break ;
		--s1_trim_end;
	}
	trim_size = s1_trim_end - s1_trim_start + 1;
	trim = malloc(trim_size);
	if (!trim)
		return (NULL);
	ft_strlcpy(trim, s1_trim_start, trim_size);
	return (trim);
}

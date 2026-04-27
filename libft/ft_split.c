/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 22:32:15 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/21 21:36:03 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_count_substr(char const *s, char sep)
{
	size_t	count;
	short	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != sep)
		{
			if (!in_word)
			{
				in_word = 1;
				++count;
			}
		}
		else
			in_word = 0;
		++s;
	}
	return (count);
}

static void	*ft_substr_clear_ret_null(char **substr)
{
	char **const	substr_o = substr;

	while (*substr)
		free(*substr++);
	free(substr_o);
	return (NULL);
}

static char	*ft_strchrnul(const char *s, int c)
{
	while (*s && *s != (char)c)
		++s;
	return ((char *)s);
}

char	**ft_split(char const *s, char c)
{
	char	**substrs;
	char	**substrs_o;
	size_t	substr_len;

	if (!s)
		return (NULL);
	substrs = malloc((ft_count_substr(s, c) + 1) * sizeof(*substrs));
	if (!substrs)
		return (NULL);
	substrs_o = substrs;
	while (*s)
	{
		while (*s == c)
			++s;
		substr_len = ft_strchrnul(s, c) - s;
		if (!substr_len)
			break ;
		*substrs = malloc(substr_len + 1);
		if (!*substrs)
			return (ft_substr_clear_ret_null(substrs_o));
		ft_strlcpy(*substrs++, s, substr_len + 1);
		s += substr_len;
	}
	*substrs = NULL;
	return (substrs_o);
}

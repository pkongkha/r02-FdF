/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:02:04 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/11 16:25:09 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <limits.h>

int	ft_abs(int n)
{
	const int	mask = n >> (sizeof(int) * CHAR_BIT - 1);

	return ((n + mask) ^ mask);
}

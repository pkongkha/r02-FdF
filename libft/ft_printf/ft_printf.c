/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:36:05 by pkongkha          #+#    #+#             */
/*   Updated: 2026/01/11 18:09:28 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		written;

	va_start(arg, format);
	written = ft_vfprintf(STDOUT_FILENO, format, &arg);
	va_end(arg);
	return (written);
}

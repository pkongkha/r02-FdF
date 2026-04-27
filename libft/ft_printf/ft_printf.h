/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 01:32:02 by pkongkha          #+#    #+#             */
/*   Updated: 2026/01/11 18:09:30 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

struct	s_ft_printf_info
{
	int				precision;
	int				width;
	char			spec;
	unsigned int	alt:1;
	unsigned int	left:1;
	unsigned int	space:1;
	unsigned int	showsign:1;
	unsigned int	_pad:4;
	char			pad;
};

int	ft_vfprintf(int fd, const char *format, va_list ap[1]);
int	ft_printf(const char *format, ...);
#endif

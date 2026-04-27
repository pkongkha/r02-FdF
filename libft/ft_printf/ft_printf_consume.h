/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_consume.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 01:48:14 by pkongkha          #+#    #+#             */
/*   Updated: 2025/10/10 02:31:35 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_CONSUME_H
# define FT_PRINTF_CONSUME_H
# include "ft_printf.h"

void	ft_printf_try_consume_flag(struct s_ft_printf_info *ft_printf_info,
			const char **format);
void	ft_printf_try_consume_precision(struct s_ft_printf_info *ft_printf_info,
			const char **format);
void	ft_printf_try_consume_width(struct s_ft_printf_info *ft_printf_info,
			const char **format);
#endif

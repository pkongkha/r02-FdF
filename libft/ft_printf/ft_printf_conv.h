/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 00:47:50 by pkongkha          #+#    #+#             */
/*   Updated: 2026/01/11 18:09:26 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_CONV_H
# define FT_PRINTF_CONV_H
# include <stdbool.h>
# include "ft_printf.h"
# include "ft_printf_buffer.h"

size_t	ft_printf_conv_nbrbase(char *buf, int num, char *base);
size_t	ft_printf_conv_unbrbase(char *buf, unsigned int num, char *base);

bool	ft_printf_conv(struct s_ft_printf_info *pf_info, va_list ap[1],
			struct s_ft_printf_buffer *pf_buf);
void	ft_printf_conv_char(struct s_ft_printf_info *pf_info, char ch,
			struct s_ft_printf_buffer *pf_buf);
void	ft_printf_conv_deci(struct s_ft_printf_info *pf_info, int num,
			struct s_ft_printf_buffer *pf_buf);
void	ft_printf_conv_hex(struct s_ft_printf_info *pf_info, unsigned int num,
			struct s_ft_printf_buffer *pf_buf);
void	ft_printf_conv_ptr(struct s_ft_printf_info *pf_info, void *ptr,
			struct s_ft_printf_buffer *pf_buf);
void	ft_printf_conv_str(struct s_ft_printf_info *pf_info, char *str,
			struct s_ft_printf_buffer *pf_buf);
void	ft_printf_conv_udeci(struct s_ft_printf_info *pf_info, unsigned int num,
			struct s_ft_printf_buffer *pf_buf);
#endif

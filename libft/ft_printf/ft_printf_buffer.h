/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_buffer.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 01:31:20 by pkongkha          #+#    #+#             */
/*   Updated: 2025/10/10 02:31:17 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BUFFER_H
# define FT_PRINTF_BUFFER_H
# include <stdbool.h>
# include <stddef.h>
# include <sys/types.h>

# define BUF_SIZE 4096

struct	s_ft_printf_buffer
{
	char	write_base[BUF_SIZE];
	char	*write_ptr;
	char	*write_end;
	size_t	written;
	int		fd;
};

bool	ft_printf_buffer_flush(struct s_ft_printf_buffer *ft_printf_buffer);
void	ft_printf_buffer_init(struct s_ft_printf_buffer *ft_printf_buffer,
			int fd);
bool	ft_printf_buffer_pad(struct s_ft_printf_buffer *ft_printf_buffer,
			char ch, size_t count);
bool	ft_printf_buffer_putc(struct s_ft_printf_buffer *ft_printf_buffer,
			char ch);
bool	ft_printf_buffer_puts(struct s_ft_printf_buffer *ft_printf_buffer,
			const char *s);
bool	ft_printf_buffer_write(struct s_ft_printf_buffer *ft_printf_buffer,
			const char *s, size_t count);
#endif

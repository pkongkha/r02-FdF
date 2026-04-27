/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:49:22 by pkongkha          #+#    #+#             */
/*   Updated: 2025/12/16 21:40:54 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <libft.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>

/**
 * newline_len() - Length of string until newline
 * @buf: pointer to buffer
 * @len: maximum length to check
 */
static ssize_t	newline_len(char *buf, size_t len)
{
	const size_t	len_o = len;

	while (len)
	{
		--len;
		if (*buf == '\n')
			return (len_o - len);
		++buf;
	}
	return (-1);
}

/**
 * read_fd_append_list() - Append read buffer to list
 * @lst: pointer to list
 * @fd: file descriptor to read
 * Return: new buffer node
 */
static struct s_gnl_buf_list	*read_fd_append_list(
	struct s_gnl_buf_list **lst, int fd)
{
	struct s_gnl_buf_list *const	new = gnl_lstnew();

	if (!new)
		return (NULL);
	new->bytes_read = read(fd, new->buf, BUFFER_SIZE);
	if (new->bytes_read <= 0)
	{
		free(new);
		return (NULL);
	}
	if (*lst)
		(*lst)->next = new;
	*lst = new;
	return (new);
}

/**
 * read_fd_until_newline() - Read file descriptor until newline is found, and
 *                           append into list
 * @lst_info: list info
 * @fd: file descriptor
 * Return: length until newline
 */
static size_t	read_fd_until_newline(struct s_gnl_buf_list_info *lst_info,
	int fd)
{
	struct s_gnl_buf_list	*lst;
	size_t					bytes_curr;
	ssize_t					len;

	lst = lst_info->head;
	bytes_curr = lst_info->bytes_curr;
	while (true)
	{
		if (lst && lst->bytes_read)
		{
			len = newline_len(lst->buf + bytes_curr,
					lst->bytes_read - bytes_curr);
			if (len >= 0)
			{
				lst_info->bytes_eol += len;
				return (lst_info->bytes_eol);
			}
			lst_info->bytes_eol += lst->bytes_read - bytes_curr;
		}
		if (!read_fd_append_list(&lst, fd))
			return (0);
		if (!lst_info->head)
			lst_info->head = lst;
		bytes_curr = 0;
	}
}

/**
 * construct_string() - Construct a string from provided lst_info,
 *                      and delete completely traversed node
 * @lst_info: list info
 * Return: constructed string
 */
static char	*construct_string(struct s_gnl_buf_list_info *lst_info)
{
	ssize_t					to_write;
	char *const				buf = malloc(lst_info->bytes_eol + 1);
	ssize_t					written;

	if (!buf)
		return (NULL);
	buf[lst_info->bytes_eol] = '\0';
	written = 0;
	while (lst_info->head && written != lst_info->bytes_eol)
	{
		to_write = gnl_min(lst_info->head->bytes_read - lst_info->bytes_curr,
				lst_info->bytes_eol - written);
		ft_memcpy(buf + written, lst_info->head->buf + lst_info->bytes_curr,
			to_write);
		written += to_write;
		if (to_write == (lst_info->head->bytes_read - lst_info->bytes_curr))
		{
			gnl_delhead(&lst_info->head);
			lst_info->bytes_curr = 0;
		}
		else
			lst_info->bytes_curr += to_write;
	}
	lst_info->bytes_eol = 0;
	return (buf);
}

char	*get_next_line(int fd)
{
	static struct s_gnl_buf_list_info	*lst_info[MAX_FD];

	if (!lst_info[fd])
	{
		lst_info[fd] = malloc(sizeof(**lst_info));
		if (!lst_info[fd])
			return (NULL);
		*lst_info[fd] = (struct s_gnl_buf_list_info)
		{.head = NULL, .bytes_curr = 0, .bytes_eol = 0};
	}
	read_fd_until_newline(lst_info[fd], fd);
	if (!lst_info[fd]->bytes_eol)
	{
		free(lst_info[fd]);
		lst_info[fd] = NULL;
		return (NULL);
	}
	return (construct_string(lst_info[fd]));
}

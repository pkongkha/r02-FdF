/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:44:29 by pkongkha          #+#    #+#             */
/*   Updated: 2025/12/16 21:28:53 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif
# ifndef MAX_FD
#  define MAX_FD 1024
# endif

struct	s_gnl_buf_list
{
	char					buf[BUFFER_SIZE];
	ssize_t					bytes_read;
	struct s_gnl_buf_list	*next;
};

struct	s_gnl_buf_list_info
{
	struct s_gnl_buf_list	*head;
	ssize_t					bytes_curr;
	ssize_t					bytes_eol;
};

/**
 * get_next_line() - Get a line from file descriptor
 * @fd: file descriptor to read
 * Return: pointer to line string
 */
char					*get_next_line(int fd);
ssize_t					gnl_min(ssize_t a, ssize_t b);
struct s_gnl_buf_list	*gnl_lstnew(void);
struct s_gnl_buf_list	*gnl_lstadd_next(struct s_gnl_buf_list *lst,
							struct s_gnl_buf_list *next);
struct s_gnl_buf_list	*gnl_delhead(struct s_gnl_buf_list **head);
#endif

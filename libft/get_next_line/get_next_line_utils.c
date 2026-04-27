/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 01:11:14 by pkongkha          #+#    #+#             */
/*   Updated: 2025/12/16 21:41:46 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

ssize_t	gnl_min(ssize_t a, ssize_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

struct s_gnl_buf_list	*gnl_lstnew(void)
{
	struct s_gnl_buf_list	*lst;

	lst = malloc(sizeof(*lst));
	if (!lst)
		return (NULL);
	lst->bytes_read = 0;
	lst->next = NULL;
	return (lst);
}

struct s_gnl_buf_list	*gnl_lstadd_next(struct s_gnl_buf_list *lst,
	struct s_gnl_buf_list *next)
{
	if (lst)
		(lst)->next = next;
	lst = next;
	return (next);
}

struct s_gnl_buf_list	*gnl_delhead(struct s_gnl_buf_list **head)
{
	struct s_gnl_buf_list *const	next = (*head)->next;

	free(*head);
	*head = next;
	return (next);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 13:12:27 by pkongkha          #+#    #+#             */
/*   Updated: 2025/09/06 21:27:01 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list *const	new_lst = malloc(sizeof(*new_lst));

	if (!new_lst)
		return (NULL);
	new_lst->content = content;
	new_lst->next = NULL;
	return (new_lst);
}

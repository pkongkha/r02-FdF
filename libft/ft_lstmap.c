/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 14:31:01 by pkongkha          #+#    #+#             */
/*   Updated: 2025/09/06 21:26:36 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*lst_new_head;
	t_list	*lst_new_last;

	if (!lst)
		return (NULL);
	lst_new_head = ft_lstnew(f(lst->content));
	if (!lst_new_head)
		return (NULL);
	lst_new_last = lst_new_head;
	while (1)
	{
		lst = lst->next;
		if (!lst)
			break ;
		ft_lstadd_back(&lst_new_last, ft_lstnew(f(lst->content)));
		lst_new_last = lst_new_last->next;
		if (!lst_new_last)
		{
			ft_lstclear(&lst_new_head, del);
			return (NULL);
		}
	}
	return (lst_new_head);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 13:50:28 by pkongkha          #+#    #+#             */
/*   Updated: 2025/09/06 21:23:16 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*lst_prev;

	if (!lst)
		return ;
	while (*lst)
	{
		lst_prev = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(lst_prev, del);
	}
}

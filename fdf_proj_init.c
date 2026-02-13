/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_proj_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:16:39 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/11 16:56:25 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_proj.h"

#include <libft.h>

void	*fdf_proj_init(struct s_fdf_proj *p, int w, int h)
{
	*p = (struct s_fdf_proj){.mat = NULL, .w = 0, .h = 0};
	p->mat = ft_calloc(w * h, sizeof(*p->mat));
	if (!p->mat)
		return (NULL);
	p->w = w;
	p->h = h;
	return (p->mat);
}

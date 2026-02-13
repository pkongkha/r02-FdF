/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_windo.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 22:27:39 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/11 17:24:54 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_WINDO_H
# define FDF_WINDO_H

struct s_fdf_windo
{
	void	*disp;
	void	*win;
	int		w;
	int		h;
};

void	*fdf_windo_init(struct s_fdf_windo *win, char *title, int w, int h);
#endif

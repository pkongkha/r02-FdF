/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:15:57 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/13 12:18:53 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_HOOK_H
# define FDF_HOOK_H
# include "fdf_info.h"

int	fdf_hook_key_rot(int keycode, struct s_fdf_info *info);
int	fdf_hook_key_scale(int keycode, struct s_fdf_info *info);
int	fdf_hook_key_slide(int keycode, struct s_fdf_info *info);
int	fdf_hook_key(int keycode, struct s_fdf_info *info);
int	fdf_hook_loop(struct s_fdf_info *info);

#endif
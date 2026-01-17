/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 01:09:44 by pkongkha          #+#    #+#             */
/*   Updated: 2026/01/18 03:05:13 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H
# include <X11/keysym.h>
# ifndef __USE_MISC
#  define __USE_MISC
#  include <math.h>
#  undef __USE_MISC
# else
#  include <math.h>
# endif

# define WINDOW_HEIGHT 720
# define WINDOW_WIDTH 1280
# define WINDOW_TITLE "WTF?"

# define VIEW_SCALE_MIN  0.0
# define VIEW_SCALE_DEFAULT 30.0
# define VIEW_SCALE_STEP 1.0
# define VIEW_SCALE_MAX  100.0

# define DEG2RAD (M_PI/180.0)
# define RAD2DEG (180.0/M_PI)

# define VIEW_ROT_X_DEFAULT ((90.0-35.2643896827546541317133232951164245605468750) * DEG2RAD)
# define VIEW_ROT_X_STEP (1.0 * DEG2RAD)
# define VIEW_ROT_Y_DEFAULT (0)
# define VIEW_ROT_Y_STEP (1.0 * DEG2RAD)
# define VIEW_ROT_Z_DEFAULT (45.0 * DEG2RAD)
# define VIEW_ROT_Z_STEP (1.0 * DEG2RAD)
# define VIEW_SLIDE_X_DEFAULT (WINDOW_WIDTH / 2)
# define VIEW_SLIDE_Y_DEFAULT (WINDOW_HEIGHT / 2)
# define VIEW_SLIDE_STEP 20

# define DEFAULT_HIGH_COLOR 0x00FF91FF
# define DEFAULT_LOW_COLOR 0x00FFFFFF

# define KB_SCALE_UP XK_equal
# define KB_SCALE_DOWN XK_minus
# define KB_ROTATE_X_INC XK_Up
# define KB_ROTATE_X_DEC XK_Down
# define KB_ROTATE_Y_INC XK_c
# define KB_ROTATE_Y_DEC XK_z
# define KB_ROTATE_Z_INC XK_Left
# define KB_ROTATE_Z_DEC XK_Right
# define KB_VIEW_SLIDE_UP XK_w
# define KB_VIEW_SLIDE_DOWN XK_s
# define KB_VIEW_SLIDE_LEFT XK_a
# define KB_VIEW_SLIDE_RIGHT XK_d
#endif
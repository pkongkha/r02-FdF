/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_config.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 01:09:44 by pkongkha          #+#    #+#             */
/*   Updated: 2026/02/13 12:30:52 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_CONFIG_H
# define FDF_CONFIG_H
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

// M_PI/180
# define DEG2RAD 0.01745329251994329547437168059786927187815308570861816406250
// 180/M_PI
# define RAD2DEG 57.295779513082322864647721871733665466308593750

# define VIEW_ROT_X_DEFAULT\
	0.955316618124509298048963046312564983963966369628906250
# define VIEW_ROT_X_STEP\
	0.01745329251994329547437168059786927187815308570861816406250
# define VIEW_ROT_Y_DEFAULT 0
# define VIEW_ROT_Y_STEP\
	0.01745329251994329547437168059786927187815308570861816406250
# define VIEW_ROT_Z_DEFAULT\
	0.785398163397448278999490867136046290397644042968750
# define VIEW_ROT_Z_STEP\
	0.01745329251994329547437168059786927187815308570861816406250
# define VIEW_SLIDE_X_DEFAULT 640
# define VIEW_SLIDE_Y_DEFAULT 360
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

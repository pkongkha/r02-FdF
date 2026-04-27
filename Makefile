SRCS :=\
fdf.c\
fdf_color_from_aarrggbb.c\
fdf_colorize_auto.c\
fdf_hook_key.c\
fdf_hook_key_rot.c\
fdf_hook_key_scale.c\
fdf_hook_key_slide.c\
fdf_hook_loop.c\
fdf_img_draw_line.c\
fdf_img_get_pixelfmt.c\
fdf_img_init.c\
fdf_img_write_pixel.c\
fdf_info_cleanup.c\
fdf_info_init.c\
fdf_map_from_file.c\
fdf_map_get_alt_range.c\
fdf_map_init.c\
fdf_map_normalize.c\
fdf_map_parse_line.c\
fdf_proj.c\
fdf_proj_init.c\
fdf_proj_node.c\
fdf_view_init.c\
fdf_view_rot_x.c\
fdf_view_rot_y.c\
fdf_view_rot_z.c\
fdf_windo_init.c

OBJDIR ?= .obj
OBJS := $(SRCS:%.c=$(OBJDIR)/%.o)
DEPS := $(OBJS:.o=.d)

ORIG_CFLAGS := $(CFLAGS)
CFLAGS += -Wall -Wextra -Werror -pedantic -pedantic-errors -Wno-strict-prototypes
CFLAGS += -MMD -MP
CFLAGS += -Ilibft -Iminilibx
LDFLAGS += -Llibft -Lminilibx
LDLIBS := -lft -lm -lmlx -lX11 -lXext
unexport CFLAGS LDFLAGS

CC ?= cc

NAME := fdf

.PHONY: all libft
.NOTPARALLEL: re $(NAME)
all: $(NAME)
clean:
	$(MAKE) -C libft fclean
	$(MAKE) -C minilibx clean
	$(RM) $(OBJS) $(DEPS)
	rmdir --ignore-fail-on-nonempty -p $(OBJDIR) 2>/dev/null | true
fclean: clean
	$(RM) $(NAME)
re: fclean all
minilibx/libmlx.a:
	$(MAKE) -C minilibx all
libft/libft.a:
	CFLAGS='$(ORIG_CFLAGS)' $(MAKE) -C libft all

$(OBJDIR):
	@mkdir -p $@
$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) -c $(CFLAGS) -o $@ $<

$(NAME): $(OBJS) | libft/libft.a minilibx/libmlx.a
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

-include $(DEPS)
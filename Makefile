SRCS := $(wildcard *.c)
OBJDIR ?= .obj
OBJS := $(SRCS:%.c=$(OBJDIR)/%.o)
DEPS := $(OBJS:.o=.d)

ORIG_CFLAGS := $(CFLAGS)
CFLAGS += -Wall -Wextra -Werror
CFLAGS += -MMD -MP
CFLAGS += -Ilibft
LDFLAGS += -Llibft
LDLIBS := -lft -lm -lmlx -lX11 -lXext
unexport CFLAGS LDFLAGS

CC ?= cc

NAME := fdf

.PHONY: all libft
.NOTPARALLEL: re $(NAME)
all: $(NAME)
clean:
	$(MAKE) -C libft fclean
	$(RM) $(OBJS) $(DEPS)
	rmdir --ignore-fail-on-nonempty -p $(OBJDIR) 2>/dev/null | true
fclean: clean
	$(RM) $(NAME)
re: fclean all
libft/libft.a:
	CFLAGS='$(ORIG_CFLAGS)' $(MAKE) -C libft all

$(OBJDIR):
	@mkdir -p $@
$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) -c $(CFLAGS) -o $@ $<

$(NAME): $(OBJS) | libft/libft.a
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

-include $(DEPS)
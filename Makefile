NAME = cub3D

SRC = main.c \
		data_init.c \
		free_data.c \
		mlx_utils_init.c \

CHECK_ARG_SRC = check_arg.c \
				check_file_extension.c \
				check_file_invalid.c \
				err_msg.c \

SRCDIR = srcs
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
CHECK_ARG_SRCDIR = srcs/check_arg
SRCS += $(addprefix $(CHECK_ARG_SRCDIR)/, $(CHECK_ARG_SRC))

OBJDIR = objs
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
CHECK_ARG_OBJDIR = objs/check_arg
OBJS += $(addprefix $(CHECK_ARG_OBJDIR)/, $(CHECK_ARG_SRC:.c=.o))

LIBFT = libft/libft.a

RM = rm -f
CFLAGS = -Wall -Wextra -Werror -MP -MMD
INC = -I./includes/cub3d.h -I./includes/parser.h -I./includes/check_arg.h

ifeq ($(MAKECMDGOALS), debug)
	CFLAGS += -DDEBUG
endif

ifeq ($(MAKECMDGOALS), address)
	CFLAGS += -g3 -fsanitize=address
endif

all : $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(MAKE) -C ./mlx
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR) $(CHECK_ARG_OBJDIR)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean :
	$(MAKE) -C ./libft clean
	$(MAKE) -C ./mlx clean
	$(RM) $(OBJS)
	rm -rf $(OBJDIR)

fclean : clean
	$(MAKE) -C ./libft fclean
	$(MAKE) -C ./mlx clean
	$(RM) $(NAME)

re : fclean all

debug : re

norm :
	norminette $(SRCDIR) includes

.PHONY : all clean fclean re debug norm address
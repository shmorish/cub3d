NAME = cub3D

SRC = main.c \
		data_init.c \
		free_data.c \
		mlx_utils_init.c \

CHECK_ARG_SRC = check_arg.c \
				check_file_extension.c \
				check_file_invalid.c \
				err_msg.c \

PARSER_SRC = parser.c \
				check_color.c \
				check_texture_path.c \
				putcolor_ceiling.c \
				putcolor_floor.c \
				putcolor_to_parser.c \
				puttexture_to_parser.c \

SRCDIR = srcs
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
CHECK_ARG_SRCDIR = srcs/check_arg
SRCS += $(addprefix $(CHECK_ARG_SRCDIR)/, $(CHECK_ARG_SRC))
PARSER_SRCDIR = srcs/parser
SRCS += $(addprefix $(PARSER_SRCDIR)/, $(PARSER_SRC))

OBJDIR = objs
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
CHECK_ARG_OBJDIR = objs/check_arg
OBJS += $(addprefix $(CHECK_ARG_OBJDIR)/, $(CHECK_ARG_SRC:.c=.o))
PARSER_OBJDIR = objs/parser
OBJS += $(addprefix $(PARSER_OBJDIR)/, $(PARSER_SRC:.c=.o))

CFLAGS = -Wall -Wextra -Werror -MP -MMD
RM = rm -f

INC = -I./includes/cub3d.h \
		-I./includes/parser.h \
		-I./includes/check_arg.h \

LIBFT = libft/libft.a

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
	mkdir -p $(OBJDIR) $(CHECK_ARG_OBJDIR) $(PARSER_OBJDIR)
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

address : re

norm :
	norminette $(SRCDIR) includes

.PHONY : all clean fclean re debug norm address
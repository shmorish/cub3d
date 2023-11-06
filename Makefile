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
				arrange_map.c \
				check_color.c \
				check_map_closed.c \
				check_map.c \
				check_player.c \
				check_texture_path.c \
				color_bitshift.c \
				free_parser.c \
				get_map_data.c \
				get_start_point.c \
				is_player.c \
				map_parse.c \
				putcolor_ceiling.c \
				putcolor_floor.c \
				putcolor_to_parser.c \
				putmap_to_parser.c \
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
RM = rm -rf

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

CHECK		= \033[32m[✔]\033[0m
REMOVE		= \033[31m[✘]\033[0m
GENERATE	= \033[33m[➤]\033[0m
BLUE		= \033[1;34m
YELLOW		= \033[1;33m
RESET		= \033[0m

all : $(NAME)

$(NAME): $(OBJS)
	@ $(MAKE) -C ./libft
	@ $(MAKE) -C ./mlx
	@ $(CC) $(CFLAGS) -o $@ $^ $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit
	@ echo "$(CHECK) $(BLUE)Compiling cub3D...$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@ mkdir -p $(OBJDIR) $(CHECK_ARG_OBJDIR) $(PARSER_OBJDIR)
	@ $(CC) $(CFLAGS) $(INC) -o $@ -c $<
	@ printf "$(GENERATE) $(YELLOW)Generating $@... %-50.50s\n$(RESET)"

clean :
	@ $(MAKE) -C ./libft clean
	@ $(MAKE) -C ./mlx clean
	@ $(RM) $(OBJDIR)
	@ echo "$(REMOVE) $(BLUE)Remove cub3D object files. $(RESET)"

fclean :
	@ $(RM) $(OBJDIR) $(NAME)
	@ $(MAKE) -C ./libft fclean
	@ $(MAKE) -C ./mlx fclean
	@ $(RM) $(NAME)
	@ echo "$(REMOVE) $(BLUE)Remove cub3D object files and $(NAME). $(RESET)"

re : fclean all

debug : re

address : re

norm :
	norminette $(SRCDIR) includes

.PHONY : all clean fclean re debug norm address
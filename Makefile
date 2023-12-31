NAME = cub3D

SRC = main.c \
		data_init.c \
		free_data.c \

CHECK_ARG_SRC = check_arg.c \
				check_file_extension.c \
				check_file_invalid.c \
				err_msg.c \

PARSER_SRC = arrange_map.c \
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
				print_texture.c \
				putcolor_ceiling.c \
				putcolor_floor.c \
				putcolor_to_parser.c \
				putmap_to_parser.c \
				parser.c \
				puttexture_to_parser.c

DRAW_SRC = draw.c \
				draw_wall.c \
				draw_minimap.c \
				xpm_to_wall.c \

HANDLE_MLX_SRC = close.c \
				pixel_put.c \
				mlx_utils_init.c \

RAY_SRC = ray.c \
			update_ray_data.c \
			ray_x.c \
			ray_y.c \


PLAYER_SRC = move.c \
				wall_judge.c

SRCDIR = srcs
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
SRCS += $(addprefix $(SRCDIR)/check_arg/, $(CHECK_ARG_SRC))
SRCS += $(addprefix $(SRCDIR)/parser/, $(PARSER_SRC))
SRCS += $(addprefix $(SRCDIR)/draw/, $(DRAW_SRC))
SRCS += $(addprefix $(SRCDIR)/handle_mlx/, $(HANDLE_MLX_SRC))
SRCS += $(addprefix $(SRCDIR)/ray/, $(RAY_SRC))
SRCS += $(addprefix $(SRCDIR)/player/, $(PLAYER_SRC))
MAKE_DIR = check_arg parser draw handle_mlx ray player

OBJDIR = objs
OBJS = $(subst $(SRCDIR), $(OBJDIR), $(SRCS:.c=.o))
DEPS = $(OBJS:.o=.d)
MAKE_DIRS = $(addprefix $(OBJDIR)/, $(MAKE_DIR))

CFLAGS = -Wall -Wextra -Werror -MP -MMD -O3
RM = rm -rf

INC = -I./includes/ -I./libft/includes -I./mlx

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

TOTAL_FILES := $(shell echo $(words $(SRCS)))
CURRENT_FILE = 1

define progress
    @printf "$(GENERATE) $(YELLOW)Cub3d obj file gen Progress: %3d%% (%d/%d)$(RESET)\r" $$(($(CURRENT_FILE)*100/$(TOTAL_FILES))) $(CURRENT_FILE) $(TOTAL_FILES)
    @$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE)+1))))
    @if [ $(CURRENT_FILE) -gt $(TOTAL_FILES) ]; then \
        printf "$(GENERATE) $(YELLOW)Finish Generating CUB3D Object files !%-50.50s\n$(RESET)"; \
    fi
endef

all : $(NAME)

$(NAME): $(OBJS)
	@ $(MAKE) -C ./libft
	@ $(MAKE) -C ./mlx
	@ $(CC) $(CFLAGS) -o $@ $^ $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit
	@ printf "$(CHECK) $(BLUE)Compiling cub3D...%-50.50s\n$(RESET)"
	@ make banner

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@ mkdir -p $(MAKE_DIRS)
	@ $(CC) $(CFLAGS) $(INC) -o $@ -c $<
	$(call progress)

clean :
	@ $(MAKE) -C ./libft clean
	@ $(MAKE) -C ./mlx clean
	@ $(RM) $(OBJDIR)
	@ echo "$(REMOVE) $(BLUE)Remove cub3D object files. $(RESET)"

fclean :
	@ $(MAKE) -C ./libft fclean
	@ $(MAKE) -C ./mlx fclean
	@ $(RM) $(OBJDIR) $(NAME)
	@ echo "$(REMOVE) $(BLUE)Remove cub3D object files and $(NAME). $(RESET)"

re : fclean all

debug : re

address : re

tester :
	@ make re > /dev/null
	@ bash invalidmap_test.sh

norm :
	norminette srcs includes libft

banner :
	@ clear
	@ $(CC) -o banner banner.c
	@ ./banner
	@ $(RM) banner

.PHONY : all clean fclean re debug norm address tester

-include $(DEPS)

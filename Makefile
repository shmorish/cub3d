NAME = cub3D
SRC = main.c
SRCDIR = srcs
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJDIR = objs
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -MP -MMD
INC = -I./includes/cub3d.h -I./includes/parser.h

all : $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(MAKE) -C ./mlx
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
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

.PHONY : all clean fclean re debug
NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

INCLUDE = ./

SRCS = ft_printf.c \
		ft_format.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putptr.c \
		ft_putnbr.c \
		ft_putunbr.c \
		ft_puthex.c \
		ft_putbinary.c

OBJS = $(SRCS:.c=.o)

CHECK		= \033[32m[✔]\033[0m
REMOVE		= \033[31m[✘]\033[0m
GENERATE	= \033[33m[➤]\033[0m
BLUE		= \033[1;34m
YELLOW		= \033[1;33m
RESET		= \033[0m

TOTAL_FILES := $(shell echo $(words $(SRCS)))
CURRENT_FILE = 1

define progress
    @printf "$(GENERATE) $(YELLOW)Ft_printf obj file gen Progress: %3d%% (%d/%d)$(RESET)\r" $$(($(CURRENT_FILE)*100/$(TOTAL_FILES))) $(CURRENT_FILE) $(TOTAL_FILES)
    @$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE)+1))))
    @if [ $(CURRENT_FILE) -gt $(TOTAL_FILES) ]; then \
        printf "$(GENERATE) $(YELLOW)Finish Generating FT_PRINTF Object files !%-50.50s\n$(RESET)"; \
    fi
endef

all: $(NAME)

$(NAME): $(OBJS)
	@ ar rc $(NAME) $(OBJS)
	@ printf "$(CHECK) $(BLUE)Compiling ft_printf...%-50.50s\n$(RESET)"


# for Mac
.c.o: $(OBJS)
	@ $(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@
	$(call progress)

# for Ubuntu
# %.o: %.c $(INCLUDE)
# 	@ $(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

clean:
	@ $(RM) $(OBJS)
	@echo "$(REMOVE) $(BLUE)Remove ft_printf object files. $(RESET)"

fclean:
	@ $(RM) $(NAME) $(OBJS)
	@echo "$(REMOVE) $(BLUE)Remove ft_printf object files and $(NAME). $(RESET)"

re: fclean all

.PHONY: clean fclean re all

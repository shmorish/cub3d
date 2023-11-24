#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2 -w

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11

CHECK		= \033[32m[✔]\033[0m
REMOVE		= \033[31m[✘]\033[0m
GENERATE	= \033[33m[➤]\033[0m
BLUE		= \033[1;34m
YELLOW		= \033[1;33m
RESET		= \033[0m

TOTAL_FILES := $(shell echo $(words $(SRC)))
CURRENT_FILE = 1

define progress
    @printf "$(GENERATE) $(YELLOW)Minilibx obj file gen Progress: %3d%% (%d/%d)$(RESET)\r" $$(($(CURRENT_FILE)*100/$(TOTAL_FILES))) $(CURRENT_FILE) $(TOTAL_FILES)
    @$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE)+1))))
    @if [ $(CURRENT_FILE) -gt $(TOTAL_FILES) ]; then \
        printf "$(GENERATE) $(YELLOW)Finish Generating MLX Object files !%-50.50s\n$(RESET)"; \
    fi
endef

all: $(NOM)

$(NOM):	$(OBJ)
	@ ar rc $(NOM) $(OBJ)
	@ ranlib $(NOM)
	@ printf "$(CHECK) $(BLUE)Compiling minilbx...%-50.50s\n$(RESET)"

%.o: %.c
	@ cc -c $< -o $@ $(CFLAGS)
	$(call progress)

%.o: %.m
	@ cc -c $< -o $@ $(CFLAGS)
	$(call progress)

clean:
	@ rm -f $(NOM) $(OBJ) *~
	@ rm -f mlx_app
	@ echo "$(REMOVE) $(BLUE)Remove minilbx object files. $(RESET)"

fclean:
	@ rm -f $(NOM) $(OBJ) *~
	@ rm -f mlx_app
	@ echo "$(REMOVE) $(BLUE)Remove minilbx object files and $(NOM). $(RESET)"

re: fclean all

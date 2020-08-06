NAME = fractol

SRCS =  ./source/main.c\
		./source/draw_fractal.c\
		./source/complex.c\
		./source/fractals.c\
		./source/additional_fractals.c\
		./source/mouse.c\
		./source/keys.c\
		./source/legend.c\
		./source/colours.c


OB = $(SRCS:.c=.o)

FLAG = -Wall -Wextra -Werror

HEADER_DIR = ./includes/
HEADER_LIST = fractol.h
HEADER = $(addprefix $(HEADER_DIR), $(HEADER_LIST))

LIBFT = libft/libft.a
LIBFT_PATH = libft
MINILIBX = ./minilibx/ -lmlx -framework OpenGL -framework AppKit

.PHONY: all clean clean re

all: $(NAME)
$(NAME): $(LIBFT) $(OB) $(HEADER)
	gcc -I $(LIBFT_PATH) $(OB) -o $(NAME) -L $(LIBFT_PATH) -lft -L $(MINILIBX) -lpthread
$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

%.o: %.c $(HEADER)
	@gcc $(FLAG) -I $(HEADER) -c $< -o $@
clean:
	@/bin/rm -f $(OB)
	@$(MAKE) -C $(LIBFT_PATH) clean
fclean: clean
	@/bin/rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean
re: fclean all

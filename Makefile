NAME := fractol
SRC := Srcs/*.c
MLX = minilibx
INC = -I$(MLX) -Iincludes
LIB := -L$(MLX) -lmlx -framework OpenGL -framework AppKit
FLAGS = -Wall -Wextra -Werror $(INC) $(LIB)

all:
	make -C $(MLX)
	gcc $(INC) $(LIB) $(SRC) -o $(NAME)

clean:

fclean: clean
	make clean -C $(MLX)
	rm -rf $(NAME)

re: fclean all

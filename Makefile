NAME = so_long

FILES = main.c

SRCS = $(addprefix src/, $(FILES))

OBJ = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = cc

RM = rm -f

###__MLX__###
MLX_DIR = mlx 

MLX_PATH = $(MLXDIR)/libmlx.a

MLX = -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit mlx/libmlx.a

###__COMPILATION__###
$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(MLX) $(OBJ) -o $(NAME)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

###__RULES__###
all: $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re :	fclean $(NAME)

.PHONY: all clean fclean re


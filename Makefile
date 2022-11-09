#MAKEFILE FOR LINUX 
NAME = so_long

FILES = main.c parse_map.c

SRCS = $(addprefix src/, $(FILES))

OBJ = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = cc

RM = rm -f

###__MLX__###
MLX_DIR = mlx_linux 

MLX_PATH = $(MLXDIR)/libmlx.a

MLX = -Lmlx_linux -lmlx_Linux -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz

###__COMPILATION__###
$(NAME): $(OBJ)
		$(CC) -fsanitize=address -g $(CFLAGS) $(OBJ) $(MLX) get_next_line/gnl.a libft/libft.a -o $(NAME)
		
.c.o:
	$(CC) $(CFLAGS) -I/usr/include -I$(MLX_DIR) -O3 -c $< -o $(<:.c=.o)

###__RULES__###
all: $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re :	fclean $(NAME)

.PHONY: all clean fclean re

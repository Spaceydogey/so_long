#MAKEFILE FOR MACOS (INTEL)
NAME = so_long

FILES = main.c parse_map.c error.c utils.c

SRCS = $(addprefix src/, $(FILES))

OBJ = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

FFLAGS = -fsanitize=address -g

CC = cc

RM = rm -f
###__LIBFT__##
LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

###__GNL__##
GNL_DIR = get_next_line

GNL = $(GNL_DIR)/gnl.a

###__MLX__###
MLX_DIR = mlx 

MLX_PATH = $(MLXDIR)/libmlx.a

MLX = -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit mlx/libmlx.a

###__COMPILATION__###
$(NAME): $(OBJ)
		@make -C $(LIBFT_DIR)
		@make -C $(GNL_DIR)
		#@make -C $(MLX_DIR)
		$(CC) $(CFLAGS) -g $(LIBFT) $(GNL) $(OBJ) -o $(NAME)

.c.o:
		$(CC) $(CFLAGS) -g -c $< -o $(<:.c=.o)

###__RULES__###
all: $(NAME)

clean:
		@make clean -C $(LIBFT_DIR)
		@make clean -C $(GNL_DIR)
		$(RM) $(OBJ)

fclean: clean
		@make fclean -C $(LIBFT_DIR)
		@make fclean -C $(GNL_DIR)
		@make clean -C $(MLX_DIR)
		$(RM) $(NAME)

re :	fclean $(NAME)

.PHONY: all clean fclean re

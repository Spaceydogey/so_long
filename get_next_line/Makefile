NAME = gnl.a

SRCS = 	get_next_line.c\
		get_next_line_utils.c\

OBJ = $(SRCS:.c=.o)

AR = @ar -rcs

CFLAGS = -Wall -Wextra -Werror

CC = @cc

RM = @rm -f

$(NAME): $(OBJ)
		$(AR) $(NAME) $(OBJ)

.c.o:
		$(CC) $(CFLAGS) -g -c $< -o $(<:.c=.o)

all: $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re :	fclean all

.PHONY: all clean fclean re

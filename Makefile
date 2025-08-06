CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
NAME		= gnl
SRC			= get_next_line_utils.c get_next_line.c main.c
OBJ			= $(SRC:.c=.o)
BUFFER_SIZE	?= 42

all: $(NAME)

$(NAME): $(OBJ)
	@echo "🔨 Compiling get_next_line with BUFFER_SIZE=$(BUFFER_SIZE)"
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
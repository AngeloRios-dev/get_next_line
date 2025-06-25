CC              = gcc
AR              = ar rcs
CFLAGS  = -Wall -Wextra -Werror
NAME    = get_next_line
SRC             = get_next_line\
				get_next_line_utils.c\
				get_next_line.h \
				main.c
OBJ             = $(SRC:.c=.o)
BUFFER_SIZE ?= 42

all: $(NAME)

$(NAME): $(OBJ)
        @echo "Compiling with BUFFER_SIZE=$(BUFFER_SIZE)"
        @$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $(OBJ) -o $(NAME)

clean:
        @rm -f $(OBJ)

fclean:
        @rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
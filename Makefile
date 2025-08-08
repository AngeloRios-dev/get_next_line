# **************************************************************************** #
#                                   SETTINGS                                   #
# **************************************************************************** #

NAME        = gnl
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f

# Sources (en la raíz)
SRC         = get_next_line_utils.c get_next_line.c main.c
OBJ         = $(patsubst %.c,obj/%.o,$(SRC))

# BUFFER_SIZE opcional
BUFFER_SIZE ?= 42

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ)
	@echo "🔨 Linking $(NAME)"
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $(OBJ) -o $(NAME)

obj/%.o: %.c | obj
	@echo "⚙️  Compiling $<"
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -c $< -o $@

obj:
	@mkdir -p obj

clean:
	@echo "🗑️  Deleting object files..."
	@$(RM) -r obj

fclean: clean
	@echo "🗑️  Deleting $(NAME)..."
	@$(RM) $(NAME)

re: fclean all

# Norminette and testing
test: re
	@echo "📝 Checking Norminette..."
	@norminette -R CheckForbiddenSourceHeader -R CheckDefine $(SRC)
	@echo "✅ Norminette check finished"
	@echo "🧪 Testing with run_test.sh"
# 	./run_test.sh 10 test_files/one_line_no_nl.txt
	valgrind --leak-check=full ./gnl test_files/one_line_no_nl.txt

.PHONY: all clean fclean re

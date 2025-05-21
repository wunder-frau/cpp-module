NAME := iter
COMPILER := c++
FLAGS := -std=c++20 -Wall -Wextra -Werror

SRC := main.cpp
OBJ := $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "🔧 Linking $(NAME)..."
	$(COMPILER) $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	@echo "📦 Compiling $<..."
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	@echo "🧹 Cleaning..."
	rm -f $(OBJ)

fclean: clean
	@echo "🗑️ Removing executable..."
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

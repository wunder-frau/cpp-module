NAME := megaphone
COMPILER := g++
FLAGS := -std=c++20 -Wall -Wextra -Werror
SRC := megaphone.cpp
OBJ := $(SRC:.cpp=.o)

GREEN := \033[32m
BLUE := \033[34m
YELLOW := \033[33m
RED := \033[31m
RESET := \033[0m

all: $(NAME)
	@echo "$(GREEN)🎉 Build successful!$(RESET)"
	@echo "$(YELLOW)➡️ Usage: ./$(NAME) \"Hello, world\" \"Let's Code\"$(RESET)"

$(NAME): $(OBJ)
	@echo "$(BLUE)🔨 Linking $(NAME)...$(RESET)"
	$(COMPILER) $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	@echo "$(YELLOW)📦 Compiling $<...$(RESET)"
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	@echo "$(RED)🧹 Cleaning object files...$(RESET)"
	rm -f $(OBJ)

fclean: clean
	@echo "$(RED)🗑️ Removing $(NAME)...$(RESET)"
	rm -f $(NAME)

re: fclean all
	@echo "$(GREEN)🔄 Rebuild complete!$(RESET)"

.PHONY: all clean fclean re

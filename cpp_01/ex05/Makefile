NAME := harl

COMPILER := c++
FLAGS := -std=c++98 -Wall -Wextra -Werror

SRC := main.cpp Harl.cpp
OBJ := $(SRC:.cpp=.o)

GREEN := \033[32m
BLUE := \033[34m
YELLOW := \033[33m
RED := \033[31m
RESET := \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(BLUE)🔗 Linking $(NAME)... 🚀$(RESET)"
	$(COMPILER) $(FLAGS) -o $(NAME) $(OBJ)
	@echo "$(GREEN)✅ Build successful! Harl is ready! 🗣️$(RESET)"
	@echo "$(YELLOW)➡️ Usage: ./$(NAME) 🗣️$(RESET)"

%.o: %.cpp
	@echo "$(YELLOW)⚙️ Compiling $<... 🔄$(RESET)"
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	@echo "$(RED)🧹 Cleaning object files... 🗑️$(RESET)"
	rm -f $(OBJ)

fclean: clean
	@echo "$(RED)🔥 Removing $(NAME)... ❌$(RESET)"
	rm -f $(NAME)

re: fclean all
	@echo "$(GREEN)🔄 Rebuild complete! Harl is fresh and ready! 🛠️$(RESET)"

.PHONY: all clean fclean re

# Set variables with emojis and settings
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

# Default rule
all: $(NAME)

# Linking the object files to create the executable
$(NAME): $(OBJ)
	@echo "$(BLUE)🔗 Linking $(NAME)... 🚀$(RESET)"
	$(COMPILER) $(FLAGS) -o $(NAME) $(OBJ)
	@echo "$(GREEN)✅ Build successful! Harl is ready! 🗣️$(RESET)"
	@echo "$(YELLOW)➡️ Usage: ./$(NAME) <level> 🗣️$(RESET)"

# Rule for compiling each .cpp file to .o file
%.o: %.cpp
	@echo "$(YELLOW)⚙️ Compiling $<... 🔄$(RESET)"
	$(COMPILER) $(FLAGS) -c $< -o $@

# Clean rule to remove object files
clean:
	@echo "$(RED)🧹 Cleaning object files... 🗑️$(RESET)"
	rm -f $(OBJ)

# Full clean, also removes the executable
fclean: clean
	@echo "$(RED)🔥 Removing $(NAME)... ❌$(RESET)"
	rm -f $(NAME)

# Rebuild the project (clean and make all)
re: fclean all
	@echo "$(GREEN)🔄 Rebuild complete! Harl is fresh and ready! 🛠️$(RESET)"

# Declare these targets as not actual files
.PHONY: all clean fclean re

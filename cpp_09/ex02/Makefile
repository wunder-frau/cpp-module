NAME = PmergeMe

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++20

SRC = main.cpp PmergeMe.cpp
OBJ = $(SRC:.cpp=.o)
LOG = debug.log

all: $(NAME)

$(NAME): $(OBJ)
	@echo "🔗 Linking the mighty $(NAME)..."
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)
	@echo "✅ Build complete! Your binary is ready to merge! 🧩"

%.o: %.cpp PmergeMe.hpp
	@echo "🛠️ Compiling $<... Please wait, magic in progress! ✨"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "🧹 Cleaning up object files and logs... 👋"
	@rm -f $(OBJ) $(LOG)
	@echo "🗑️ Cleaned successfully!"

fclean: clean
	@echo "💣 Removing $(NAME)... Hope you said goodbye! 😢"
	@rm -f $(NAME)

re: fclean all
	@echo "🔄 Rebuilding from scratch... Let's goooo! 🚴‍♂️💨"

.PHONY: all clean fclean re

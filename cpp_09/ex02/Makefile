NAME = PmergeMe

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++20

SRC = main.cpp PmergeMe.cpp
OBJ = $(SRC:.cpp=.o)
LOG = debug.log

all: $(NAME)

$(NAME): $(OBJ)
	@echo "🔗 Linking PmergeMe executable..."
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp PmergeMe.hpp
	@echo "🛠️ Compiling $< into object file..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "🧹 Cleaning build artifacts and logs..."
	rm -f $(OBJ) $(LOG)

fclean: clean
	@echo "💣 Removing PmergeMe executable..."
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

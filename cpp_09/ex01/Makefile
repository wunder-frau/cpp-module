NAME     := RPN
CXX      := c++
CXXFLAGS := -std=c++20 -Wall -Wextra -Werror

SRC := main.cpp RPN.cpp
OBJ := $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "🔧 Linking: $(NAME)"
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp RPN.hpp
	@echo "📦 Compiling: $<"
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "🧹 Cleaning..."
	rm -f $(OBJ)

fclean: clean
	@echo "🗑️ Removing executable..."
	rm -f $(NAME)

re: fclean all
	@echo "🔄 Rebuild complete!"

.PHONY: all clean fclean re

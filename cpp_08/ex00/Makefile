# 📦 Project Configuration
NAME     := easyfind
CXX      := c++
CXXFLAGS := -std=c++20 -Wall -Wextra -Werror

SRC := main.cpp
OBJ := $(SRC:.cpp=.o)

# 🔨 Build Target
all: $(NAME)

$(NAME): $(OBJ)
	@echo "🔧 Linking: $(NAME)"
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)
	@echo "✅ Build successful!"

# 🧪 Object Compilation
%.o: %.cpp easyfind.hpp easyfind.tpp
	@echo "📦 Compiling: $<"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 🧹 Cleanup Object Files
clean:
	@echo "🧹 Cleaning object files..."
	rm -f $(OBJ)

# 🗑️ Full Clean
fclean: clean
	@echo "🗑️ Removing executable: $(NAME)"
	rm -f $(NAME)

# 🔄 Rebuild
re: fclean all
	@echo "🔄 Rebuild complete!"

.PHONY: all clean fclean re

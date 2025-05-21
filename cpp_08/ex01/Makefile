# 📦 Project Configuration
NAME     := span
CXX      := c++
CXXFLAGS := -std=c++20 -Wall -Wextra -Werror

SRC := main.cpp Span.cpp
OBJ := $(SRC:.cpp=.o)

# 🔨 Build Target
all: $(NAME)

$(NAME): $(OBJ)
	@echo "🔧 Linking: $(NAME)"
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)
	@echo "✅ Build successful!"

# 🧪 Object Compilation
%.o: %.cpp Span.hpp
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

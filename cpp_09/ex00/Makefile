NAME = btc

SRC = main.cpp BitcoinExchange.cpp
OBJ = $(SRC:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++20

all: $(NAME)

$(NAME): $(OBJ)
	@echo "🔧 Compiling your crypto brain... 💰"
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)
	@echo "✅ Done! Your executable '$(NAME)' is ready to crunch numbers 🚀"

clean:
	@echo "🧹 Sweeping away the object files... 🧼"
	@rm -f $(OBJ)
	@echo "🗑 Object files removed!"

fclean: clean
	@echo "💣 Nuking the executable... Goodbye, btc 😢"
	@rm -f $(NAME)
	@echo "✅ Everything cleaned!"

re: fclean all
	@echo "🔁 Rebuilding from scratch... 🧱"

.PHONY: all clean fclean re

SRCS = main.cpp PmergeMe.cpp
OBG = $(SRCS:.cpp=.o)
CPPFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3 -std=c++98
NAME = PmergeMe
CC = c++
all: $(NAME)

$(NAME): $(OBG)
	$(CC) $(CPPFLAGS) $(OBG) -o $(NAME)

clean:
	rm -rf $(OBG)

fclean: clean
	rm -rf $(NAME)
run:
	make
	clear
	./$(NAME)

re: fclean all

.PHONY: all clean fclean re
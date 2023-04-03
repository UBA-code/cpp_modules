SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp
OBG = $(SRCS:.cpp=.o)
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = ScavTrap
CC = c++
all: $(NAME)

$(NAME): $(OBG)
	$(CC) $(CFLAGS) $(OBG) -o $(NAME)

clean:
	rm -rf $(OBG)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
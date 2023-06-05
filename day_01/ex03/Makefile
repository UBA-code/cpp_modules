SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBG = $(SRCS:.cpp=.o)
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = attack
CC = c++
all: $(NAME)

$(NAME): $(OBG)
	$(CC) $(CPPFLAGS) $(OBG) -o $(NAME)

clean:
	rm -rf $(OBG)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
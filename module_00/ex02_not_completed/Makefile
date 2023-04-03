SRCS = test.cpp Account.cpp
OBG = $(SRCS:.cpp=.o)
CFLAGS = -Wall -Werror -Wextra -std=c++98
NAME = PhoneBook
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
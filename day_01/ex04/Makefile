# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/20 14:23:31 by ybel-hac          #+#    #+#              #
#    Updated: 2023/05/20 14:25:09 by ybel-hac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp
OBG = $(SRCS:.cpp=.o)
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = Sed
CC = c++
all: $(NAME)

$(NAME): $(OBG)
	$(CC) $(CPPFLAGS) $(OBG) -o $(NAME)

clean:
	rm -rf $(OBG)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean rema
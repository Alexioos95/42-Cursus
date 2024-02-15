# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apayen <apayen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 14:41:49 by apayen            #+#    #+#              #
#    Updated: 2023/10/19 10:45:01 by apayen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

SRC = megaphone.cpp
OBJ =		$(SRC:.cpp=.o)

CC =		c++
FLAGS =		-Wall -Wextra -Werror -std=c++98

RM =		rm -rf

all :		$(NAME)
$(NAME) : 	$(OBJ) $(HEADER)
			$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
			$(CC) $(FLAGS) -c -o $@ $^

clean :
			$(RM) $(OBJ) $(DEP)

fclean : 	clean
			$(RM) $(NAME)

re :		fclean
			make all


.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apayen <apayen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 14:41:49 by apayen            #+#    #+#              #
#    Updated: 2023/12/04 12:12:55 by apayen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe
DIR = build

SRC = 	$(addprefix $(DIR)/,	\
		main.cpp				\
		PmergeMe.cpp)

OBJ =		$(SRC:.cpp=.o)
DEP =		$(OBJ:.o=.d)

CC =		c++
FLAGS =		-MMD -Wall -Wextra -Werror -std=c++98 -g

RM =		rm -rf


all :		$(NAME)

debug :		FLAGS += -DDEBUG=true
debug :		$(NAME)

$(NAME) : 	$(OBJ)
			$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(DIR)/%.o : %.cpp
			@mkdir -p $(@D)
			$(CC) $(FLAGS) -c $< -o $@

clean :
			$(RM) $(DIR)

fclean : 	clean
			$(RM) $(NAME)

re :		fclean
			make all

-include $(DEP)

.PHONY: all clean fclean re debug

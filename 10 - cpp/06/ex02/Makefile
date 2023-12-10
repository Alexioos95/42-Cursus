# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apayen <apayen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 14:41:49 by apayen            #+#    #+#              #
#    Updated: 2023/11/20 10:15:39 by apayen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test
DIR = build

SRC = 	$(addprefix $(DIR)/,	\
		main.cpp				\
		Base.cpp)

OBJ =		$(SRC:.cpp=.o)
DEP =		$(OBJ:.o=.d)

CC =		c++
FLAGS =		-MMD -Wall -Wextra -Werror -std=c++98 -g

RM =		rm -rf

all :		$(NAME)

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

.PHONY: all clean fclean re

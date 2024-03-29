# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apayen <apayen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 14:41:49 by apayen            #+#    #+#              #
#    Updated: 2024/03/27 09:53:06 by apayen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = webserv
DIR = build

SRC = 	$(addprefix $(DIR)/,	\
		main.cpp				\
		Manager.cpp				\
		Parsing.cpp				\
		Server.cpp				\
		Client.cpp				\
		Request.cpp				\
		Request_reader.cpp		\
		Request_parsing.cpp		\
		Request_writer.cpp		\
		Request_processor.cpp	\
		Location.cpp			\
		Cgi.cpp					\
		utils.cpp)

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

bonus :		all

clean :
			$(RM) $(DIR)

fclean : 	clean
			$(RM) ./Servers/form/download
			$(RM) $(NAME)

re :		fclean
			make all

-include $(DEP)

.PHONY: all clean fclean re

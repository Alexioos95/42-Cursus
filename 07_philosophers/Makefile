# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apayen <apayen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 11:13:47 by apayen            #+#    #+#              #
#    Updated: 2023/05/16 09:46:52 by apayen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
HEADER = philo.h

SRC = philo.c	\
		init.c	\
		utils.c	\
		state.c
OBJ = $(SRC:.c=.o)

CC = clang
FLAGS = -Wall -Wextra -Werror
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
		$(CC) $(FLAGS) $(OBJ) -pthread -o $(NAME)

%.o : %.c
		$(CC) $(FLAGS) -c -o $@ $^

clean :
		$(RM) $(OBJ) $(BOBJ)

fclean : clean
		$(RM) $(NAME)

re : fclean
		make all

.PHONY: all clean fclean re

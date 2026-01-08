# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apayen <apayen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 11:25:06 by apayen            #+#    #+#              #
#    Updated: 2023/01/16 09:29:15 by apayen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
HEADER = push_swap.h

SRC = push_swap.c	\
		./parsing/parsing.c	\
		./parsing/checkerror.c	\
		./algorithm/sortsmallstack.c	\
		./algorithm/operations.c	\
		./algorithm/simplifytab.c	\
		./algorithm/radix.c
OBJ = $(SRC:.c=.o)

CC = clang
FLAGS = -Wall -Wextra -Werror
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
		$(CC) $(FLAGS) $(OBJ) -o push_swap

%.o : %.c
	$(CC) $(FLAGS) -c -o $@ $^

clean :
		$(RM) $(OBJ)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re

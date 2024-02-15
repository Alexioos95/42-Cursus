# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apayen <apayen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 11:13:47 by apayen            #+#    #+#              #
#    Updated: 2023/04/18 11:38:51 by apayen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
HEADER = pipex.h	\
		./bonus/pipex_bonus.h

SRC = pipex.c \
		childprocess.c \
		ft_split.c \
		command.c \
		utils.c
OBJ = $(SRC:.c=.o)

BONUS =	./bonus/pipex_bonus.c \
		./bonus/init.c	\
		./bonus/heredoc.c	\
		./bonus/get_next_line.c	\
		./bonus/get_next_line_utils.c	\
		./bonus/childprocess.c \
		./bonus/childsdup.c \
		./bonus/ft_split.c \
		./bonus/command.c \
		./bonus/utils.c
BOBJ = $(BONUS:.c=.o)

CC = scan-build-12 cc
FLAGS = -Wall -Wextra -Werror -Weverything -g3
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.c
		$(CC) $(FLAGS) -c -o $@ $^

bonus : $(BOBJ) $(HEADER)
		$(CC) $(FLAGS) $(BOBJ) -o $(NAME)

clean :
		$(RM) $(OBJ) $(BOBJ)

fclean : clean
		$(RM) $(NAME)

re : fclean
		make all

.PHONY: all clean fclean re bonus

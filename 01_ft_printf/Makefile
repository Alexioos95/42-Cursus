# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apayen <apayen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 11:13:47 by apayen            #+#    #+#              #
#    Updated: 2022/11/24 16:43:44 by apayen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = libftprintf.h

SRC = ft_printf.c	\
		ft_isformat.c	\
		ft_format.c	\
		ft_putchar.c	\
		ft_putstr.c	\
		ft_putnbr.c	\
		ft_putnbrui.c	\
		ft_hexa.c	\
		ft_ptr.c	\
		ft_strlen.c
OBJ = $(SRC:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
		ar -rcs $@ $^

%.o : %.c
		$(CC) $(FLAGS) -c -o $@ $^

clean :
		$(RM) $(OBJ)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apayen <apayen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 11:13:47 by apayen            #+#    #+#              #
#    Updated: 2023/04/12 14:29:02 by apayen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
HEADER = so_long.h	\
		./bonus/so_long_bonus.h

SRC = so_long.c	\
		./parsing/errors.c	\
		./parsing/ft_split.c	\
		./parsing/getmap_floodfill.c	\
		./parsing/parsing.c	\
		./graphic/graphic.c	\
		./graphic/move.c	\
		./graphic/ft_printf.c	\
		./frees.c
OBJ = $(SRC:.c=.o)

BONUS = ./bonus/so_long_bonus.c	\
		./bonus/parsing/errors.c	\
		./bonus/parsing/ft_split.c	\
		./bonus/parsing/getmap.c	\
		./bonus/parsing/floodfill.c	\
		./bonus/parsing/parsing.c	\
		./bonus/init/init.c	\
		./bonus/init/initenemy.c	\
		./bonus/init/initenemysprites.c	\
		./bonus/init/lists.c	\
		./bonus/graphic/graphic.c	\
		./bonus/graphic/move.c	\
		./bonus/graphic/ft_printf.c	\
		./bonus/graphic/player.c	\
		./bonus/graphic/teleporting.c	\
		./bonus/graphic/animplayer.c	\
		./bonus/graphic/score.c	\
		./bonus/graphic/enemy.c	\
		./bonus/graphic/animenemy.c	\
		./bonus/graphic/panic.c	\
		./bonus/algorithm/algorithm.c \
		./bonus/algorithm/target.c \
		./bonus/frees/frees.c \
		./bonus/frees/freeimages.c
BOBJ = $(BONUS:.c=.o)

CC = clang
FLAGS = -Wall -Wextra -Werror
RM = rm -f

all : lib
	make $(NAME)

lib :
	make -C mlx_linux/

$(NAME) : $(OBJ) $(HEADER)
		$(CC) $(FLAGS) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -o $(NAME)

%.o : %.c
		$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c -o $@ $^

clean :
		$(RM) $(OBJ) $(BOBJ)
		make clean -C mlx_linux/

fclean : clean
		$(RM) $(NAME)

bonus : lib
		make true

true : $(BOBJ)
	$(CC) $(FLAGS) $(BOBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -o $(NAME)

re : fclean
	make all

.PHONY: all clean fclean re bonus

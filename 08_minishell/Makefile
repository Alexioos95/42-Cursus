# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 11:13:47 by apayen            #+#    #+#              #
#    Updated: 2023/09/21 13:11:29 by eewu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		minishell

HEADER =	header.h

SRC = 		$(addprefix $(OBJDIR)/,				\
			program/minishell.c					\
			program/loop.c						\
			program/signals.c					\
			program/init.c						\
			program/init_env.c					\
			parsing/parsing.c					\
			parsing/checkorphans.c				\
			parsing/checkorphans2.c				\
			parsing/lst_lexer.c					\
			parsing/tokens.c					\
			parsing/heredoc.c					\
			parsing/heredoc_utils.c				\
			parsing/expand.c					\
			parsing/expand_dquote.c				\
			parsing/expand_utils.c				\
			builtins/builtins.c					\
			builtins/builtins_cd.c				\
			builtins/builtins_cd2.c				\
			builtins/builtins_echo.c			\
			builtins/builtins_exit.c			\
			builtins/builtins_export.c			\
			builtins/builtins_export2.c			\
			pipex/pipex.c						\
			pipex/pipex_test.c					\
			pipex/pipex_util.c					\
			pipex/pipex_util2.c					\
			pipex/pipex_parsing.c				\
			pipex/pipex_parsing2.c				\
			pipex/pipex_parsing3.c				\
			pipex/pipex_open.c					\
			pipex/pipex_close.c					\
			pipex/pipex_lst.c					\
			pipex/pipex_init.c					\
			utils/utils.c						\
			utils/utils_env.c					\
			utils/utils_env2.c					\
			utils/lst.c							\
			utils/minilib.c						\
			utils/ft_split.c					\
			utils/errors_1-5.c					\
			utils/frees.c)

OBJ =		$(SRC:.c=.o)

OBJDIR	=	obj

CC =		cc

FLAGS =		-Wall -Wextra -Werror -g3

RM =		rm -rf

all :		$(NAME)

$(NAME) : 	$(OBJ) $(HEADER)
			$(CC) $(FLAGS) $(OBJ) -lreadline -o $(NAME)

$(OBJDIR)/%.o : %.c
			@mkdir -p $(@D)
			$(CC) $(FLAGS) -c -o $@ $^

clean :
			$(RM) $(OBJ) $(BOBJ) $(OBJDIR)

fclean : 	clean
			$(RM) $(NAME)

re :		fclean
			make all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: su <su@student.42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 00:01:37 by ycha              #+#    #+#              #
#    Updated: 2021/10/11 05:16:23 by su               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

# FILE =================================================

FILE		=	\
				main.c \
				core/builtin/builtin_cd.c \
				core/builtin/builtin_pwd.c \
				core/execute/build_proc.c \
				core/execute/execute.c \
				core/execute/proc.c \
				core/execute/redir.c \
				core/env/env.c \
				core/parse/cmd.c \
				core/parse/lexer.c \
				core/parse/parse.c \
				core/parse/replace.c \
				core/parse/token.c \
				core/parse/tokenizer.c \
				core/input.c \
				utils/ft_close.c \
				utils/ft_exit.c \
				utils/ft_free.c \
				utils/ft_split_free.c \
				utils/ft_strjoins.c \
				utils/list.c \
				debug/debug_parse.c


# Options =================================================

CC			=	gcc
INCLUDE 	=	include
# CFLAGS		=	-Wall -Werror -Wextra -I$(INCLUDE) -g
CFLAGS		=	-I$(INCLUDE) -g
CLIB		=	-Lsrc/lib -lft -lreadline

SRC_DIR		=	./src
SRCS		=	$(addprefix $(SRC_DIR)/, $(FILE))

OBJ_DIR		=	./obj
OBJS		=	$(addprefix $(OBJ_DIR)/, $(patsubst %.c,%.o,$(FILE)))

export FILE

# =========================================================

all				: $(NAME)

$(OBJ_DIR)/%.o	: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME)			: $(OBJS)
	$(MAKE) -C ./src/lib
	ar rcs ./obj/libminishell.a $(OBJS)
	gcc $(CFLAGS) $(CLIB) -o $@ $^

norm			:
	@python3 -m norminette include/*
	@python3 -m norminette src/*

show			:
	@printf "SRCS : $(SRCS)"
	@printf "OBJS : $(OBJS)"

clean			:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C ./src/lib clean

fclean			: clean
	rm -f $(NAME)
	$(MAKE) -C ./src/lib fclean

re				: fclean all

.PHONY: clean fclean all re norm show
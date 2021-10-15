# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: su <su@student.42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 00:01:37 by ycha              #+#    #+#              #
#    Updated: 2021/10/13 20:20:20 by echung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

# FILE =================================================

FILE		=	\
				main.c \
				core/builtin/builtin_cd.c \
				core/builtin/builtin_echo.c \
				core/builtin/builtin_env.c \
				core/builtin/builtin_exit.c \
				core/builtin/builtin_export.c \
				core/builtin/builtin_pwd.c \
				core/builtin/builtin_unset.c \
				core/env/env.c \
				core/error/error_msg.c \
				core/error/error.c \
				core/execute/execute1.c \
				core/execute/execute2.c \
				core/execute/proc1.c \
				core/execute/proc2.c \
				core/execute/redir.c \
				core/parse/cmd.c \
				core/parse/lexer.c \
				core/parse/parse.c \
				core/parse/parser.c \
				core/parse/replace.c \
				core/parse/token.c \
				core/parse/tokenizer.c \
				debug/debug_parse.c \
				debug/debug_execute.c \
				debug/debug_utils.c \
				utils/ft_close.c \
				utils/ft_dup.c \
				utils/ft_exit.c \
				utils/ft_free.c \
				utils/ft_free_strings.c \
				utils/ft_strjoins.c \
				utils/list.c


# Options =================================================

# CC			=	clang --analyze
CC			=	gcc
INCLUDE 	=	include
# CFLAGS		=	-Wall -Werror -Wextra -I$(INCLUDE) -g
CFLAGS		=	-I$(INCLUDE) -g
CLIB		=	-Lsrc/lib -lft -lreadline

SRC_DIR		=	./src
SRCS		=	$(addprefix $(SRC_DIR)/, $(FILE))

OBJ_DIR		=	./obj
OBJS		=	$(addprefix $(OBJ_DIR)/, $(patsubst %.c,%.o,$(FILE)))

DEBUG		=	0

export FILE

# =========================================================

all				: $(NAME)

$(OBJ_DIR)/%.o	: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS)  -c $< -o $@ -DDEBUG=$(DEBUG) $(CLIB)

$(NAME)			: $(OBJS)
	@$(MAKE) -C ./src/lib >
	ar rcs ./obj/libminishell.a $(OBJS)
	gcc $(CFLAGS)  -o $@ $^ $(CLIB)

norm			:
	@python3 -m norminette include/*
	@python3 -m norminette src/*

debug			:
	@$(MAKE) re DEBUG=1

test			:
	@$(MAKE) -s -C ./test

show			:
	@printf "SRCS : $(SRCS)"
	@printf "OBJS : $(OBJS)"

clean			:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C ./src/lib clean

fclean			: clean
	rm -f $(NAME)
	$(MAKE) -C ./src/lib fclean
	@$(MAKE) -C ./test fclean

re				: fclean all

.PHONY: clean fclean all re norm show test

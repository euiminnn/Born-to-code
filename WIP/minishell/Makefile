# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycha <ycha@gmail.com>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 00:01:37 by ycha              #+#    #+#              #
#    Updated: 2021/12/13 19:39:24 by ycha             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

# FILE =================================================

FILE		=	\
				main.c \
				input.c \
				core/signal.c \
				core/builtin/builtin_cd.c \
				core/builtin/builtin_echo.c \
				core/builtin/builtin_env.c \
				core/builtin/builtin_exit.c \
				core/builtin/builtin_export.c \
				core/builtin/builtin_pwd.c \
				core/builtin/builtin_unset.c \
				core/env/env_data.c \
				core/env/env1.c \
				core/env/env2.c \
				core/error/error_msg1.c \
				core/error/error_msg2.c \
				core/error/error_msg3.c \
				core/error/error.c \
				core/execute/execute1.c \
				core/execute/execute2.c \
				core/execute/proc1.c \
				core/execute/proc2.c \
				core/execute/redir.c \
				core/parse/cmd.c \
				core/parse/heredoc.c \
				core/parse/lexer.c \
				core/parse/parse.c \
				core/parse/parser.c \
				core/parse/replace1.c \
				core/parse/replace2.c \
				core/parse/token.c \
				core/parse/tokenizer.c \
				debug/debug_env.c \
				debug/debug_parse.c \
				debug/debug_execute.c \
				debug/debug_utils.c \
				utils/ft_close.c \
				utils/ft_dup.c \
				utils/ft_exit.c \
				utils/ft_get_key_value.c \
				utils/ft_is_valid_key.c \
				utils/ft_free_strings.c \
				utils/ft_strjoins.c \
				utils/list1.c \
				utils/list2.c


# Options =================================================

CC			=	gcc

#cluster
#CFLAGS		=	-Iinclude -I/Users/$(USER)/.brew/opt/readline/include -Wall -Wextra -Werror -g
#CLIB		=	-Lsrc/lib -lft -lreadline -L/Users/$(USER)/.brew/opt/readline/lib
#home
CFLAGS		=	-Iinclude -I/opt/homebrew/opt/readline/include -Wall -Wextra -Werror -g
CLIB		=	-Lsrc/lib -lft -lreadline -L/opt/homebrew/opt/readline/lib

SRC_DIR		=	./src
SRCS		=	$(addprefix $(SRC_DIR)/, $(FILE))

OBJ_DIR		=	./obj
OBJS		=	$(addprefix $(OBJ_DIR)/, $(patsubst %.c,%.o,$(FILE)))

DEBUG		=	0

idx			=	0

BLACK		= 	"\033[0;30m"
GRAY		= 	"\033[1;30m"
GREEN		=	"\033[0;32m"

export FILE

# =========================================================

all				: $(NAME)

$(OBJ_DIR)/%.o	: $(SRC_DIR)/%.c
	$(eval t_idx_old = $(shell expr $(idx) / 10 + 1))
	$(eval idx = $(shell expr $(idx) + 1))
	$(eval t_idx = $(shell expr $(idx) / 10 + 1))
	@if [ $(idx) = 1 ]; then\
		printf $(GRAY)"Loading ..."$(BLACK);\
	fi
	@if [ $(t_idx_old) != $(t_idx) ]; then\
		printf $(GRAY)"..."$(BLACK);\
	fi
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ -DDEBUG=$(DEBUG)

$(NAME)			: $(OBJS)
	@$(MAKE) -s -C ./src/lib
	@ar rcs ./obj/libminishell.a $(OBJS)
	@gcc $(CFLAGS) -o $@ $^ $(CLIB)
	@printf $(GREEN)" done!"$(BLACK);

norm			:
	@python3 -m norminette include/*
	@python3 -m norminette src/*

debug			:
	@$(MAKE) re DEBUG=1

test			:
	@$(MAKE) -s -C ./test/unit 0> /dev/null
	@printf "Unit test done!"
	@sleep 3
	@cd ./test/minishell_tester && bash test.sh

show			:
	@printf "SRCS : $(SRCS)"
	@printf "OBJS : $(OBJS)"

clean			:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -s -C ./src/lib clean

fclean			: clean
	@rm -f $(NAME)
	@$(MAKE) -s -C ./src/lib fclean
	@$(MAKE) -s -C ./test/unit fclean
	@rm -f ./test/minishell_tester/minishell
	@rm -f ./test/minishell_tester/test
	@rm -f ./test/minishell_tester/tofix/tofix_tests.txt

re				: fclean all

.PHONY: clean fclean all re norm show test

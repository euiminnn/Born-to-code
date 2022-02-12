# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/15 22:13:22 by echung            #+#    #+#              #
#    Updated: 2022/02/13 03:46:21 by echung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I./include/
CLIB		= -Lsrcs/lib -lft

FILE		= main.c \
				time.c \
				eat.c \
				init_arguments.c \
				init_simulation.c \
				id.c \
				think.c \
				sleep.c \
				thread.c \
				print.c \
				monitor.c

SRCS_DIR	= ./srcs
SRCS		= $(addprefix $(SRCS_DIR)/, $(FILE))

OBJS_DIR 	= ./objs
OBJS		= $(addprefix $(OBJS_DIR)/, $(patsubst %.c,%.o,$(FILE)))

all: $(NAME)

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	make -s -C ./srcs/lib
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(CLIB)

norm:
	norminette srcs/*
	norminette include/*

clean:
	rm -rf $(OBJS_DIR)
	make -s -C ./srcs/lib clean

fclean: clean
	rm -f $(NAME)
	make -s -C ./srcs/lib fclean

re: fclean all

.PHONY: clean fclean all re

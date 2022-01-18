# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/15 22:13:22 by echung            #+#    #+#              #
#    Updated: 2022/01/18 21:41:19 by echung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

CFLAGS	= -Wall -Wextra -Werror -I./include/ -c
CC		= gcc

SRCS	= srcs/main.c

OBJS	= $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -s -C ./srcs/lib
	ar rcs ./srcs/lib/libft.a $(OBJS)
	gcc $(CFLAGS) -o $(NAME) $(OBJS)

norm:
	norminette srcs/*

clean:
	rm -f $(OBJS)
	make -s -C ./srcs/lib clean

fclean: clean
	rm -f $(NAME)
	make -s -C ./srcs/lib fclean

re: fclean all

.PHONY: clean fclean all re

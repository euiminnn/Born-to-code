# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/15 22:13:22 by echung            #+#    #+#              #
#    Updated: 2021/06/22 18:10:49 by echung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CFLAGS	= -Wall -Wextra -Werror -I.
SRCS	= push_swap.c \
			init.c \
			put.c \
			pop.c \
			rotate.c \
			swap.c \
			print_stack.c \
			sort_three.c \
			sort_five.c

OBJS	= $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re

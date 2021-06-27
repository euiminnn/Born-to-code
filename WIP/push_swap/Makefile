# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/15 22:13:22 by echung            #+#    #+#              #
#    Updated: 2021/06/27 17:32:18 by echung           ###   ########.fr        #
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
			get_pivot.c \
			make_chunk.c \
			quick_sort.c \
			sort_small.c \
			utils/ft_atoi.c \
			utils/ft_bzero.c \
			utils/ft_isdigit.c \
			utils/ft_memcpy.c \
			utils/ft_memset.c \
			utils/ft_split.c \
			utils/ft_strlen.c \
			utils/ft_substr.c

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

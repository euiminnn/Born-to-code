# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/15 22:13:22 by echung            #+#    #+#              #
#    Updated: 2021/06/29 03:16:42 by echung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CFLAGS	= -Wall -Wextra -Werror -I.
SRCS	= push_swap.c \
			operators/init.c \
			operators/pop.c \
			operators/push.c \
			operators/put.c \
			operators/rotate.c \
			operators/swap.c \
			algorithm/get_pivot.c \
			algorithm/sort_ab.c \
			algorithm/quick_sort.c \
			algorithm/sort_small.c \
			utils/ft_atoi.c \
			utils/ft_bzero.c \
			utils/ft_isdigit.c \
			utils/ft_memcpy.c \
			utils/ft_memset.c \
			utils/ft_split.c \
			utils/ft_strlen.c \
			utils/ft_substr.c \
			print/pinit.c \
			print/pput.c \
			print/print.c

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

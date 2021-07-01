# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/15 22:13:22 by echung            #+#    #+#              #
#    Updated: 2021/07/02 03:36:44 by echung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
BONUS_NAME = checker_min

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

BONUS_SRCS = checker.c \
			 bonus/get_next_line.c \
			 bonus/ft_strjoin_free.c \
			 bonus/ft_strdup.c \
			 utils/ft_memcpy.c \
			 utils/ft_substr.c \
			 utils/ft_strlen.c \
			 operators/init.c \
			 bonus/bonus_operators/pop.c \
			 bonus/bonus_operators/push.c \
			 bonus/bonus_operators/put.c \
			 bonus/bonus_operators/rotate.c \
			 bonus/bonus_operators/swap.c \

OBJS	= $(SRCS:%.c=%.o)
BONUS_OBJS = $(BONUS_SRCS:%.c=%.o)

all: $(NAME) $(BONUS_NAME)

$(NAME): $(OBJS)
	gcc $(CFLAGS) -o $(NAME) $(OBJS)
$(BONUS_NAME): $(BONUS_OBJS)
	gcc $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS)

clean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all

.PHONY: clean fclean all re

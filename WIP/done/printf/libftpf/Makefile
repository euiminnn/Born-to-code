# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/15 22:13:22 by echung            #+#    #+#              #
#    Updated: 2021/03/22 16:55:26 by echung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CFLAGS	= -Wall -Wextra -Werror -I. -c
SRCS	= utils.c \
		  libft.c \
		  ft_putchar_fd.c \
		  ft_putnbr_fd.c \
		  parse_flag.c \
		  parse_spec.c \
		  print_content.c \
		  ft_printf.c

OBJS	= $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(CFLAGS) $(SRCS)
	ar rcs $(NAME) $(OBJS)

#$(NAME): $(OBJS)
#	gcc -o $@ $^

#$(OBJS) : $(SRCS)
#	gcc -c $< -o $@
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re

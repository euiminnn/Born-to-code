# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/15 22:13:22 by echung            #+#    #+#              #
#    Updated: 2021/08/09 21:24:28 by echung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

CFLAGS	= -Wall -Wextra -Werror -I.
MLX     = -L../mlx -lmlx -framework OpenGL -framework AppKit
SRCS	= main.c \
		  readfile.c \
		  load_image.c \
		  map.c \
		  parse_map.c \
		  get_next_line.c \
		  lib.c \
		  libstr.c

OBJS	= $(SRCS:%.c=%.o)

all: $(NAME)
	./so_long

$(NAME): $(OBJS)
	gcc $(CFLAGS) $(MLX) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re

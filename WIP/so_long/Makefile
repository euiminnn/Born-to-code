# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/15 22:13:22 by echung            #+#    #+#              #
#    Updated: 2021/08/10 18:21:18 by echung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

CFLAGS	= -Wall -Wextra -Werror -I./include -g
MLX     = -L srcs/mlx -lmlx -framework OpenGL -framework AppKit
SRCS	= srcs/main.c \
		  srcs/readfile.c \
		  srcs/load_image.c \
		  srcs/map.c \
		  srcs/parse_map.c \
		  srcs/get_next_line.c \
		  srcs/lib.c \
		  srcs/libstr.c \
		  srcs/short_mlx.c

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

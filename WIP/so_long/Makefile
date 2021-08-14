# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/15 22:13:22 by echung            #+#    #+#              #
#    Updated: 2021/08/14 00:05:59 by echung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

CFLAGS	= -Wall -Wextra -Werror -I./include 
MLX     = -L mlx -lmlx -framework OpenGL -framework AppKit
SRCS	= srcs/main.c \
		  srcs/map/check_arg.c \
		  srcs/map/readfile.c \
		  srcs/map/load_image.c \
		  srcs/map/map.c \
		  srcs/map/parse_map.c \
		  srcs/utils/get_next_line.c \
		  srcs/utils/lib.c \
		  srcs/utils/libstr.c \
		  srcs/utils/short_mlx.c \
		  srcs/key/press.c

OBJS	= $(SRCS:%.c=%.o)

all: $(NAME)
	./so_long "map.ber"

$(NAME): $(OBJS)
	gcc $(CFLAGS) $(MLX) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re

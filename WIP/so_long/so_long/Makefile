# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/15 22:13:22 by echung            #+#    #+#              #
#    Updated: 2021/08/09 00:51:20 by echung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

CFLAGS	= -Wall -Wextra -Werror -I.
MLX =  -L../mlx -lmlx -framework OpenGL -framework AppKit
SRCS	= main.c \
		  file.c \
		  load_image.c \
		  map.c \
		  parse_map.c \
		  get_next_line.c \
		  libstr.c \
		  libmem.c

OBJS	= $(SRCS:%.c=%.o)

all: $(NAME)
	./so_long
#all:
#	gcc -L../mlx -lmlx -framework OpenGL -framework AppKit \
	main.c file.c load_image.c map.c parse_map.c get_next_line.c libstr.c libmem.c

$(NAME): $(OBJS)
	gcc $(CFLAGS) $(MLX) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re

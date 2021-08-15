# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/15 22:13:22 by echung            #+#    #+#              #
#    Updated: 2021/08/15 05:36:42 by echung           ###   ########.fr        #
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

.PHONY: all
all: $(NAME)
	./so_long "map.ber"

$(NAME): $(OBJS)
	gcc $(CFLAGS) $(MLX) -o $(NAME) $(OBJS)

.PHONY: clean
clean:
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

#.PHONY: all clean fclean re

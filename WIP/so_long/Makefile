# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/15 22:13:22 by echung            #+#    #+#              #
#    Updated: 2021/10/23 14:43:36 by echung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

CFLAGS	= -Wall -Wextra -Werror -I./include 
MLX     = -L mlx -lmlx -framework OpenGL -framework AppKit
SRCS	= srcs/main.c \
		  srcs/game/init.c \
		  srcs/game/end.c \
		  srcs/map/is_valid_file_type.c \
		  srcs/map/readfile.c \
		  srcs/map/load_image.c \
		  srcs/map/map.c \
		  srcs/map/parse_map.c \
		  srcs/utils/get_next_line.c \
		  srcs/utils/lib.c \
		  srcs/utils/libstr.c \
		  srcs/utils/libfree.c \
		  srcs/utils/short_mlx.c \
		  srcs/key/press.c

OBJS	= $(SRCS:%.c=%.o)

.PHONY: all
all: $(NAME)
#	./so_long "map.ber"

$(NAME): $(OBJS)
	make -C mlx	
	gcc $(CFLAGS) $(MLX) -o $(NAME) $(OBJS)

.PHONY: clean
clean:
	make -C mlx clean
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

#.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/15 22:13:22 by echung            #+#    #+#              #
#    Updated: 2021/10/28 14:38:45 by echung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

CFLAGS	= -Wall -Wextra -Werror -I./include 
MLX     = -L mlx -lmlx -framework OpenGL -framework AppKit
SRCS	= srcs/main.c \
		  srcs/game/init.c \
		  srcs/game/end.c \
		  srcs/map/validfiletype.c \
		  srcs/map/read.c \
		  srcs/map/load.c \
		  srcs/map/render.c \
		  srcs/map/validmap.c \
		  srcs/utils/get_next_line.c \
		  srcs/utils/lib.c \
		  srcs/utils/libstr.c \
		  srcs/utils/libfree.c \
		  srcs/utils/short_mlx.c \
		  srcs/key/press.c

OBJS	= $(SRCS:%.c=%.o)

.PHONY: all
all: $(NAME)
	./so_long "map.ber"

$(NAME): $(OBJS)
	make -C mlx	
	gcc $(CFLAGS) $(MLX) -o $(NAME) $(OBJS)

.PHONY: norm
norm:
	Norminette $(SRCS) ./include/*.h

.PHONY: nm
nm:
	nm -u $(OBJS)

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

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 19:49:59 by echung            #+#    #+#              #
#    Updated: 2022/02/17 19:50:01 by echung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= miniRT

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -I./include/
SRCS	= src/main.c \
			src/print/print.c \
			src/scene/canvas.c \
			src/scene/scene.c \
			src/scene/object_create.c \
			src/trace/hit/hit.c \
			src/trace/hit/hit_sphere.c \
			src/trace/hit/normal.c \
			src/trace/ray/ray.c \
			src/utils/vec3_utils.c \
			src/utils/object_utils.c

OBJS	= $(SRCS:%.c=%.o)

all: $(NAME)
	./miniRT > rgb.ppm
	open rgb.ppm

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f rgb.ppm

re: fclean all

.PHONY: clean fclean all re
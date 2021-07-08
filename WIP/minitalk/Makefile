# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/15 22:13:22 by echung            #+#    #+#              #
#    Updated: 2021/07/08 12:31:12 by echung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER	= server
NAME_CLIENT = client

CFLAGS	= -Wall -Wextra -Werror -I.

SRCS_SERVER	= server.c \
SRCS_CLIENT	= client.c \


OBJS_SERVER	= $(SRCS_SERVER:%.c=%.o)
OBJS_CLIENT = $(SRCS_CLIENT:%.c=%.o)

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER)
	gcc $(CFLAGS) -o $(NAME_SERVER) $(OBJS_SERVER)
$(NAME_CLIENT): $(OBJS_CLIENT)
	gcc $(CFLAGS) -o $(NAME_CLIENT) $(OBJS_CLIENT)

clean:
	rm -f $(OBJS_SERVER)
	rm -f $(OBJS_CLIENT)

fclean: clean
	rm -f $(NAME_SERVER)
	rm -f $(NAME_CLIENT)

re: fclean all

.PHONY: clean fclean all re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/15 22:13:22 by echung            #+#    #+#              #
#    Updated: 2021/10/04 20:23:23 by echung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER	= server
NAME_CLIENT = client

NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

CFLAGS	= -Wall -Wextra -Werror -I./include -I./bonus/include
CC = gcc

SRCS_SERVER	= srcs/server.c \
			  srcs/utils.c \
			  srcs/utils2.c
SRCS_CLIENT	= srcs/client.c \
			  srcs/utils.c \
			  srcs/utils2.c
SRCS_SERVER_BONUS = bonus/srcs/server_bonus.c \
					bonus/srcs/utils_bonus.c \
					bonus/srcs/utils2_bonus.c
SRCS_CLIENT_BONUS = bonus/srcs/client_bonus.c \
					bonus/srcs/utils_bonus.c \
					bonus/srcs/utils2_bonus.c

OBJS_SERVER	= $(SRCS_SERVER:%.c=%.o)
OBJS_CLIENT = $(SRCS_CLIENT:%.c=%.o)

OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:%.c=%.o)
OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:%.c=%.o)

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER)
	gcc $(CFLAGS) -o $(NAME_SERVER) $(OBJS_SERVER)
$(NAME_CLIENT): $(OBJS_CLIENT)
	gcc $(CFLAGS) -o $(NAME_CLIENT) $(OBJS_CLIENT)

bonus: $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

$(NAME_SERVER_BONUS): $(OBJS_SERVER_BONUS)
	gcc $(CFLAGS) -o $(NAME_SERVER_BONUS) $(OBJS_SERVER_BONUS)
$(NAME_CLIENT_BONUS): $(OBJS_CLIENT_BONUS)
	gcc $(CFLAGS) -o $(NAME_CLIENT_BONUS) $(OBJS_CLIENT_BONUS)

clean:
	rm -f $(OBJS_SERVER)
	rm -f $(OBJS_CLIENT)
	rm -f $(OBJS_SERVER_BONUS)
	rm -f $(OBJS_CLIENT_BONUS)

fclean: clean
	rm -f $(NAME_SERVER)
	rm -f $(NAME_CLIENT)
	rm -f $(NAME_SERVER_BONUS)
	rm -f $(NAME_CLIENT_BONUS)

re: fclean all

.PHONY: clean fclean all re

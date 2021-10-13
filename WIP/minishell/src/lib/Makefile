# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: su <su@student.42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/15 22:13:22 by echung            #+#    #+#              #
#    Updated: 2021/10/11 03:37:46 by su               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CFLAGS	= -Wall -Wextra -Werror -I../../include/lib/ -c
SRCS	= ft_atoi.c \
		  ft_isalnum.c \
		  ft_isalpha.c \
		  ft_isascii.c \
		  ft_isdigit.c \
		  ft_isprint.c \
		  ft_strlen.c \
		  ft_tolower.c \
		  ft_toupper.c \
		  ft_strlcpy.c \
		  ft_strncmp.c \
		  ft_strlcat.c \
		  ft_strchr.c \
		  ft_strrchr.c \
		  ft_strnstr.c \
		  ft_bzero.c \
		  ft_memset.c \
		  ft_memcpy.c \
		  ft_memccpy.c \
		  ft_memmove.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  ft_calloc.c \
		  ft_strdup.c \
		  ft_substr.c \
		  ft_strjoin.c \
		  ft_strtrim.c \
		  ft_split.c \
		  ft_itoa.c \
		  ft_strmapi.c

OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)


$(NAME): $(OBJS)
	gcc $(CFLAGS) $(SRCS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

bonus: $(NAME) $(OBJS_B)
	gcc $(CFLAGS) $(SRCS_B)
	ar rcs $(NAME) $(OBJS_B)

clean:
	rm -f $(OBJS) $(OBJS_B)

fclean: clean
	rm -f $(NAME) $(bonus)

re: fclean all

.PHONY: clean fclean all re

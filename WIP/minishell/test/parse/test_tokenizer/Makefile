# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: su <su@student.42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 00:01:37 by ycha              #+#    #+#              #
#    Updated: 2021/10/11 04:02:52 by su               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TEST_NAME	=	$(notdir $(shell pwd))

TEST_PATH	=	./parse/$(TEST_NAME)
TEST_FILE	=	$(TEST_NAME).c

all			:
	@$(MAKE) -C ../../ TEST_PATH=$(TEST_PATH) test

test		:
	@printf "[TEST] $(TEST_NAME)\n";
	@g++ $(TEST_FILE) -lminishell -L../../../obj
	@./a.out

fclean		:
	@rm -f ./a.out

re			: fclean all

.PHONY: fclean all re test


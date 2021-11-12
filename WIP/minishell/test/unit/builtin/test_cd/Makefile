# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycha <ycha@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 00:01:37 by ycha              #+#    #+#              #
#    Updated: 2021/10/11 04:02:52 by echung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TEST_FILE	=	$(notdir $(shell pwd))

TEST_NAME	=	./builtin/$(TEST_FILE)

all			:
	@$(MAKE) -C ../../ TEST_NAME=$(TEST_NAME) test

test		:
	@printf "[UNIT_TEST] $(TEST_NAME)";
	@gcc $(TEST_FILE).c -I../../../../include -lminishell -lft -L../../../../obj -L../../../../src/lib
	@../../unit_test.sh $(TEST_FILE).c

fclean		:
	@rm -f ./a.out
	@rm -f output

re			: fclean all

.PHONY: fclean all re test


# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycha <ycha@gmail.com>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 00:01:37 by ycha              #+#    #+#              #
#    Updated: 2021/11/26 01:57:14 by ycha             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TESTS		=	\
				parse/test_replace \
				parse/test_tokenizer \
				env/test_insert \
				env/test_remove \
				env/test_search \
				builtin/test_cd \
				builtin/test_echo \
				builtin/test_env \
				builtin/test_exit \
				builtin/test_export \
				builtin/test_unset
				
# =========================================================

all				:
	@$(MAKE) -C ../../
	@for DIRS in $(TESTS); do \
		$(MAKE) -C $$DIRS test; \
	done

test			:
	@$(MAKE) -C ../../
	@$(MAKE) -C $(TEST_NAME) test;

fclean			:
	@for DIRS in $(TESTS); do \
		$(MAKE) -C $$DIRS fclean; \
	done

re				: fclean all

.PHONY: fclean all re show

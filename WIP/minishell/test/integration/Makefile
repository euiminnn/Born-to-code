# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 00:01:37 by ycha              #+#    #+#              #
#    Updated: 2021/10/17 21:46:42 by ycha             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TESTS		=	
				
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 22:59:07 by echung            #+#    #+#             */
/*   Updated: 2021/06/22 22:16:55 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	int	sign;
	int	result;

	sign = 1;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
		if (*str == '-' || *str == '+')
			return (0);
	}
	result = 0;
	while ('0' <= *str && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}

int	main(int argc, char **argv)
{
	t_stack* a;
	t_stack* b;

    a = stack_init();
    b = stack_init();
	int	i;

//	printf("argc = %d\n\n", argc);

	i = argc - 1;
	while (i > 0)
	{
		put(a, ft_atoi(argv[i]));
		i--;
	}

	stack_to_array(a);

	//print_stack("a", a);
	//print_stack("b", b);
/*
	if (argc == 4)
	{
		sort_three(a, b);
	}

	else if (argc == 6)
	{
		sort_five(a, b);
	}
*/
//	print_stack("a", a);
//	print_stack("b", b);
	
}

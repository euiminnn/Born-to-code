/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 22:59:07 by echung            #+#    #+#             */
/*   Updated: 2021/07/02 11:03:01 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_unique(t_stack *stack, int dup)
{
	t_node	*node;

	node = stack->top;
	if (!node)
		return (1);
	while (node->prev)
	{
		if (dup == node->data)
			return (0);
		node = node->prev;
	}
	if (dup == node->data)
		return (0);
	return (1);
}

static int	check_input(t_stack *stack, char *num)
{
	long long	integer;

	integer = ft_atoi(num);
	if (!(ft_isdigit(num)))
		return (0);
	if (!(check_unique(stack, integer)))
		return (0);
	if (!(integer <= 2147483647 && integer >= -2147483648))
		return (0);
	return (1);
}

static void	free_split(char **splitted)
{
	char	**s;

	s = splitted;
	while (*s != 0)
		free(*s++);
	free(splitted);
}

static int	parse_input(int argc, char **argv, t_stack *a)
{
	int		i;
	char	**splitted;
	char	**s;
	int		j;

	i = argc - 1;
	while (i > 0)
	{
		splitted = ft_split(argv[i], ' ');
		s = splitted;
		j = -1;
		while (*s++ != 0)
			j++;
		if (j == -1)
			return (0);
		while (j >= 0)
		{
			if (!(check_input(a, splitted[j])))
				return (0);
			put(a, ft_atoi(slitted[j--]));
		}
		i--;
		free_split(splitted);
	}

	return (1);
}
#include <stdio.h>
int			main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_print	*p;

	a = stack_init();
	b = stack_init();
	p = print_init();

	if (parse_input(argc, argv, a))
	{
			//printf("size: %d\n", a->size);
			//printf("a: %d %d %d %d\n", a->top->data, a->top->prev->data, a->top->prev->prev->data, a->top->prev->prev->prev->data);
			if (is_sorted(&a))
				return (0);
			if (a->size == 3 || a->size == 4 || a->size == 5)
			{
				printf("here\n");
				sort_small(a, b, p);
	printf("??a: %d %d %d %d\n", a->top->data, a->top->prev->data, a->top->prev->prev->data, a->top->prev->prev->prev->data);
			}
			else
				a_to_b(a, b, a->size, p);
	}
	else
		write(2, "Error\n", 6);
	//printf("a: %d %d %d %d\n", a->top->data, a->top->prev->data, a->top->prev->prev->data, a->top->prev->prev->prev->data);

	print(p);
	return (0);
}

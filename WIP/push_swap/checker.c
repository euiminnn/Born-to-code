/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 00:13:56 by echung            #+#    #+#             */
/*   Updated: 2021/07/02 18:42:33 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	is_empty(t_stack *b)
{
	if (b->size == 0)
		return (1);
	else
		return (0);
}

static void	run_op_set_r(t_stack *a, t_stack *b, char *line)
{
	if (cmp_str(line, "ra", 2))
		rotate(a);
	else if (cmp_str(line, "rb", 2))
		rotate(b);
	else if (cmp_str(line, "rra", 3))
		rrotate(a);
	else if (cmp_str(line, "rrb", 3))
		rrotate(b);
	else if (cmp_str(line, "rrr", 3))
		rrrotate(a, b);
	else if (cmp_str(line, "rr", 2))
	{
		rotate(a);
		rotate(b);
	}
}

static void	run_op_set_s(t_stack *a, t_stack *b, char *line)
{
	if (cmp_str(line, "sa", 2))
		swap(a, b);
	else if (cmp_str(line, "sb", 2))
		swap(b, a);
	else if (cmp_str(line, "ss", 2))
	{
		swap(a, b);
		swap(b, a);
	}
}

static int	run_op(t_stack *a, t_stack *b)
{
	char	*line;
	int		check;

	while ((check = get_next_line(0, &line)) > 0)
	{
		if (cmp_str(line, "s", 1))
			run_op_set_s(a, b, line);
		else if (cmp_str(line, "r", 1))
			run_op_set_r(a, b, line);
		else if (cmp_str(line, "pa", 2))
			push(b, a);
		else if (cmp_str(line, "pb", 2))
			push(a, b);
		else
			return (0);
		free(line);
	}
	if (*line != 0)
		return (0);
	free(line);
	return (1);
}

int			main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = stack_init();
	b = stack_init();
	if (argc < 2)
		return (0);
	if (parse_input(argc, argv, a) && run_op(a, b))
	{
		if (is_sorted(a) && is_empty(b))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}

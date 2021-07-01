/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 00:13:56 by echung            #+#    #+#             */
/*   Updated: 2021/07/02 03:43:02 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

static int	cmp_str(char *s1, char *s2, int n)
{
	while (*s1 != '\0' && *s2 != '\0' && n > 0)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (1);
	else
		return (0);
}

static int	is_empty(t_stack *b)
{
	if (b->size == 0)
		return (1);
	else
		return (0);
}

static int	is_sorted(t_stack *a)
{
	t_node *node;

	node = a->top;
	while (node->prev)
	{
		if (!(node->data < node->prev->data))
			return (0);
		node = node->prev;
	}
	printf("great job\n");
	return (1);
}

static int	run_op(t_stack *a, t_stack *b)
{
	char *line;
	int	check;

    while ((check = get_next_line(0, &line)) > 0)
    {
		if (cmp_str(line, "sa", 2))
			swap(a, b, 'a');
		else if (cmp_str(line, "sb", 2))
			swap(b, a, 'b');
		else if (cmp_str(line, "ss", 2))
		{
			swap(a, b, 'a');
			swap(b, a, 'b');
		}
		else if (cmp_str(line, "ra", 2))
			rotate(a, 'a');
		else if (cmp_str(line, "rb", 2))
			rotate(b, 'b');
		else if (cmp_str(line, "rr", 2))
		{
			rotate(a, 'a');
			rotate(b, 'b');
		}
		else if (cmp_str(line, "rra", 3))
			rrotate(a, 'a');
		else if (cmp_str(line, "rrb", 3))
			rrotate(b, 'b');
		else if (cmp_str(line, "rrr", 3))
			rrrotate(a, b);
		else if (cmp_str(line, "pa", 2))
			push(b, a, 'a');
		else if (cmp_str(line, "pb", 2))
			push(a, b, 'b');
        free(line);
    }
	if (line)
		printf("%s\n", line);
    free(line);
	return (1);
}

int    main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	a = stack_init();
	b = stack_init();

	if (argc == 1)
		return (0);
	if (!argv[0])
		return (0);
	if (run_op(a, b) && is_sorted(a) && is_empty(b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);

    return (0);
}

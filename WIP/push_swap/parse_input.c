/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 11:29:41 by echung            #+#    #+#             */
/*   Updated: 2021/07/02 18:23:50 by echung           ###   ########.fr       */
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

int			parse_input(int argc, char **argv, t_stack *a)
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
			put(a, ft_atoi(splitted[j--]));
		}
		i--;
		free_split(splitted);
	}
	return (1);
}

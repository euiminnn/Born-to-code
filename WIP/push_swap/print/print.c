/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:09:15 by echung            #+#    #+#             */
/*   Updated: 2021/07/01 15:13:20 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	compare_op(t_pnode *pnode, char *s1, char *s2)
{
	if ((cmp_str(pnode->op, s1, 2) && cmp_str(pnode->next->op, s2, 2)) ||
		(cmp_str(pnode->op, s2, 2) && cmp_str(pnode->next->op, s1, 2)))
		return (1);
	else
		return (0);
}

static void	mywrite(char *str)
{
	if (cmp_str(str, "rrr", 3))
		write(1, "rrr\n", 4);
	else if (cmp_str(str, "rra", 3))
		write(1, "rra\n", 4);
	else if (cmp_str(str, "rrb", 3))
		write(1, "rrb\n", 4);
	else if (cmp_str(str, "pp", 2))
		return ;
	else
	{
		write(1, str, 2);
		write(1, "\n", 1);
	}
}

void		print(t_print *print)
{
	int		flag;
	t_pnode	*pnode;

	pnode = print->bottom;
	while (print->size > 1)
	{
		if ((flag = compare_op(pnode, "sa", "sb")))
			write(1, "ss\n", 3);
		else if ((flag = compare_op(pnode, "ra", "rb")))
			write(1, "rr\n", 3);
		else if ((flag = compare_op(pnode, "pa", "pb")))
			mywrite("pp");
		else
			mywrite(pnode->op);
		if (flag)
		{
			pnode = pnode->next;
			(print->size)--;
		}
		pnode = pnode->next;
		(print->size)--;
	}
	if (print->size)
		mywrite(pnode->op);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:09:15 by echung            #+#    #+#             */
/*   Updated: 2021/06/29 03:50:15 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 != '\0' && *s2 != '\0' && n > 0)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
		n--;
	}
	if (n == 0)		//correct
		return (1);
	else			//error
		return (0);
}

void	print(t_print *print)
{
	t_pnode	*pnode;

	pnode = print->bottom;
	if (!pnode)
	{
		//printf("\n");
		return ;
	}
	while (pnode->next)
	{
		/*
		printf("%s\n", pnode->op);
		*/
		//if (pnode->op == "sa" && pnode->next->op == "sb")
		if ((strncmp(pnode->op, "sa", 2) && strncmp(pnode->next->op, "sb", 2))
			|| (strncmp(pnode->op, "sb", 2) && strncmp(pnode->next->op, "sa", 2)))
		{
			printf("ss\n");
			pnode = pnode->next;
		}
		else if ((strncmp(pnode->op, "ra", 2) && strncmp(pnode->next->op, "rb", 2))
			|| (strncmp(pnode->op, "rb", 2) && strncmp(pnode->next->op, "ra", 2)))
		{
			printf("rr\n");
			pnode = pnode->next;
		}
		/*
		else if ((strncmp(pnode->op, "pa", 2) && strncmp(pnode->next->op, "pb", 2))
			|| (strncmp(pnode->op, "pb", 2) && strncmp(pnode->next->op, "pa", 2)))
		{
			pnode = pnode->next;
		}
		*/
		else
			printf("%s\n", pnode->op);
		pnode = pnode->next;
	}
	printf("%s\n", pnode->op);
}

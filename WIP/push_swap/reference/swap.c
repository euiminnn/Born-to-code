/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 19:17:57 by echung            #+#    #+#             */
/*   Updated: 2021/06/09 19:18:03 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

struct	s_list
{
	int				data;
	struct s_list	*next;
};

typedef struct s_list	t_list;

void	swap_nodes(t_list **head_ref, int x, int y)
{
	t_list	*prev_x;
	t_list	*curr_x;
	t_list	*prev_y;
	t_list	*curr_y;
	t_list	*temp;

	prev_x = NULL;
	curr_x = *head_ref;
	prev_y = NULL;
	curr_y = *head_ref;
	if (x == y)
		return ;
	while (curr_x && curr_x -> data != x)
	{
		prev_x = curr_x;
		curr_x = curr_x -> next;
	}
	while (curr_y && curr_y -> data != y)
	{
		prev_y = curr_y;
		curr_y = curr_y -> next;
	}
	if (curr_x == NULL || curr_y == NULL)
		return ;
	if (prev_x != NULL)
		prev_x -> next = curr_y;
	else
		*head_ref = curr_y;
	if (prev_y != NULL)
		prev_y -> next = curr_x;
	else
		*head_ref = curr_x;
	temp = curr_y -> next;
	curr_y -> next = curr_x -> next;
	curr_x -> next = temp;
}

void	push(t_list **head_ref, int new_data)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	new_node -> data = new_data;
	new_node -> next = (*head_ref);
	(*head_ref) = new_node;
}

void	print_list(t_list *node)
{
	while (node != NULL)
	{
		printf("%d ", node -> data);
		node = node -> next;
	}
}

int	main(void)
{
	t_list	*start;

	start = NULL;
	push(&start, 7);
	push(&start, 6);
	push(&start, 5);
	push(&start, 4);
	push(&start, 3);
	push(&start, 2);
	push(&start, 1);
	printf("\n LL before ");
	print_list(start);
	swap_nodes(&start, 4, 3);
	printf("\n LL after ");
	print_list(start);

	return (0);
}

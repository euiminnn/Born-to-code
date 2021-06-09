/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 22:59:07 by echung            #+#    #+#             */
/*   Updated: 2021/06/09 19:15:07 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


struct	s_list
{
	int				data;
	struct s_list	*prev;
	struct s_list	*next;
};

typedef struct s_list	t_list;

t_list*	get_new_node(char data)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	new_node -> data = data;
	new_node -> prev = NULL;
	new_node -> next = NULL;
	return new_node;
}

void	head_and_tail(t_list *node)
{
	t_list	*head;
	t_list	*tail;

	head = node;
	while (node -> next != NULL)
	{
		node = node -> next;
	}
	tail = node;

	printf("\n");
	printf("head = %c\n", head->data);
	printf("tail = %c\n", tail->data);
	head -> prev = tail;
	tail -> next = head;
}

void	push(t_list **head, char new_data)
{
	t_list	*new_node;

	new_node = get_new_node(new_data);

	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	(*head) -> prev = new_node;
	new_node -> next = (*head);
	(*head) = new_node;
}


void	print_list(t_list *node)
{
	while (node ->next != NULL)
	{
		printf("%c ", node -> data);
		node = node -> next;
	}
	/*
	printf("%c ", node -> data);
	printf("\nreverse = ");
	while (node != NULL)
	{
		//printf("%c ", node -> data);
		node = node -> prev;
	}
	*/
}

int	main(int argc, char **argv)
{
	t_list	*start;
	int	i;

	start = NULL;

	printf("argc = %d", argc);

	i = 1;
	while (i < argc)
	{
		push(&start, *argv[i]);
		i++;
	}
	head_and_tail(start);
	//printf("\nstart = ");
	//print_list(start);
}

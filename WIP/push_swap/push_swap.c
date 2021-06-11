/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 22:59:07 by echung            #+#    #+#             */
/*   Updated: 2021/06/11 21:27:32 by echung           ###   ########.fr       */
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

void	push_to_b(t_list **a, t_list **b, char *cmd) //pb: push a from b
{
	(*a) = (*a)->next;

	printf("%s\n", cmd);
}

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
	while (node != NULL)
	{
		printf("%c\n", node -> data);
		sleep(1);
		node = node -> next;
	}

	/*
	while (node ->next != NULL)
	{
		printf("%c\n", node -> data);
		node = node -> next;
	}
	printf("%c\n", node -> data);
	*/

	/*
	printf("\nreverse = ");
	while (node != NULL)
	{
		printf("%c ", node -> data);
		node = node -> prev;
	}
	*/
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int	i;

	a = NULL;
	b = NULL;

	printf("argc = %d\n", argc);

	i = 1;
	while (i < argc)
	{
		push(&a, *argv[i]);
		i++;
	}
	head_and_tail(a);
	head_and_tail(b);
	printf("before push\n");
	//print_list(a);
	printf("Stack A\n");
	printf("%c\n", a->data);
	printf("%c\n", a->next->data);
	//printf("%c\n", a->next->next->data);
	//printf("%c\n", a->next->next->next->data);

	printf("Stack B\n");
	printf("%c\n", b->data);
	printf("%c\n", b->next->data);
	printf("%c\n", b->next->next->data);
	printf("%c\n", b->next->next->next->data);

	printf("after push\n");
	printf("Stack A\n");
	push_to_b(&a, &b, "pb");
	printf("%c\n", a->data);
	printf("%c\n", a->next->data);
	//printf("%c\n", a->next->next->data);
	//printf("%c\n", a->next->next->next->data);

	printf("Stack B\n");
	printf("%c\n", b->data);
	printf("%c\n", b->next->data);
	printf("%c\n", b->next->next->data);
	printf("%c\n", b->next->next->next->data);

	//printf("prev a =%c", a->prev->data);
	//printf("now a =%c", a->data);
	//printf("next a =%c", a->next->data);
	//print_list(a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 22:59:07 by echung            #+#    #+#             */
/*   Updated: 2021/06/12 06:01:31 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


struct	s_node
{
	char			data;
	struct s_node	*prev;
	struct s_node	*next;
};

typedef struct s_node	t_node;

typedef struct s_stack
{
    int             size;
    t_node          *top;
}t_stack;

t_stack*    stack_init(void)
{
    t_stack *stack;
    stack = (t_stack*)malloc(sizeof(t_stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

t_node*	node_init(char data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node -> data = data;
	new_node -> prev = NULL;
	new_node -> next = NULL;
	return new_node;
}


char    pop(t_stack *stack)
{
    t_node *curr_top;
    t_node *new_top;

    curr_top = stack->top;

    if (curr_top == NULL)
        return ('e');
    else
    {
        new_top = curr_top->prev;
        new_top->next = NULL;
        stack->top = new_top;
    }
    stack->size--;
	return(curr_top->data);
    //free(curr_top->data);????????????????????
    //free(curr_top);???????????????????
}

void	put(t_stack *stack, char new_data)

{
	t_node	*new_node;
	t_node	*old_top;

	new_node = node_init(new_data);

	if (stack->top == NULL)
	{
		stack->top = new_node;
		return ;
	}
	else
	{
		old_top = stack->top;
		old_top->next= new_node;
		new_node->prev = old_top;
		stack->top = new_node;
	}
	stack->size++;
}

void    push(t_stack *from, t_stack *to)
{
	t_stack *temp;
	char popdata;

	popdata = pop(from);
	put(to, popdata);
}
int	main(int argc, char **argv)
{
	t_stack* a;
	t_stack* b;

    a = stack_init();
    b = stack_init();
	int	i;

	printf("argc = %d\n\n", argc);

	i = 1;
	while (i < argc)
	{
		put(a, *argv[i]);
		i++;
	}

	printf("Stack A:\n");
	printf("%c\n", a->top->data);
	printf("%c\n", a->top->prev->data);
	printf("%c\n", a->top->prev->prev->data);
	printf("%c\n", a->top->prev->prev->prev->data);
	printf("%c\n", a->top->prev->prev->prev->prev->data);
	printf("%c\n", a->top->prev->prev->prev->prev->prev->data);
	printf("%c\n", a->top->prev->prev->prev->prev->prev->prev->data);
	printf("Stack B:\n");
	printf("%s\n", b->top);
	/*
	printf("%c\n", b->top->prev->data);
	printf("%c\n", b->top->prev->prev->data);
	*/

	printf("\n<push A to B>\n");
	push(a, b);
	printf("Stack A:\n");
	printf("%c\n", a->top->data);
	printf("%c\n", a->top->prev->data);
	printf("%c\n", a->top->prev->prev->data);
	printf("%c\n", a->top->prev->prev->prev->data);
	printf("%c\n", a->top->prev->prev->prev->prev->data);
	printf("%c\n", a->top->prev->prev->prev->prev->prev->data);
	printf("%c\n", a->top->prev->prev->prev->prev->prev->prev);
	printf("Stack B:\n");
	printf("%c\n", b->top->data);
	//printf("%c\n", b->top->prev->data);
	//printf("%c\n", b->top->prev->prev->data);
}

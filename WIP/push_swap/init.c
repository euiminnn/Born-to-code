#include "push_swap.h"

t_stack*    stack_init(void)
{
    t_stack *stack;
    stack = (t_stack*)malloc(sizeof(t_stack));
    stack->top = NULL;
    stack->bottom = NULL;
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

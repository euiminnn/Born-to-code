#include "push_swap.h"
char    pop(t_stack *stack)
{
    t_node *curr_top;
    t_node *new_top;

    curr_top = stack->top;
	printf("node : %c %p %p\n", stack->top->data, stack->top->prev, stack->top->next);

    if (curr_top == NULL)
        return ('e');
    else
    {
        new_top = curr_top->prev;
		printf("new_top : %p\n", new_top);
        new_top->next = NULL;
        stack->top = new_top;
    }
	printf("yeah\n");
    stack->size--;
	return(curr_top->data);
    //free(curr_top->data);????????????????????
    //free(curr_top);???????????????????
}
char    pop_bottom(t_stack *stack)
{
    t_node *curr_bottom;
    t_node *new_bottom;

    curr_bottom = stack->bottom;

    if (curr_bottom == NULL)
        return ('e');
    else
    {
        new_bottom = curr_bottom->next;
        new_bottom->prev = NULL;
        stack->bottom = new_bottom;
    }
    stack->size--;
	return(curr_bottom->data);
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
		stack->bottom = new_node;
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

void	put_bottom(t_stack *stack, char new_data)

{
	t_node	*new_node;
	t_node	*old_bottom;

	new_node = node_init(new_data);

	old_bottom = stack->bottom;
	old_bottom->prev= new_node;
	new_node->next = old_bottom;
	stack->bottom = new_node;
	stack->size++;
}

void    push(t_stack *from, t_stack *to)
{
	char	popdata;

	printf("here before\n");
	popdata = pop(from);
	printf("here\n");
	put(to, popdata);
}

void	rotate(t_stack *stack)
{
	char	popped;

	popped = pop(stack);
	put_bottom(stack, popped);
}

void	rrotate(t_stack *stack)
{
	char	popped;
	
	popped = pop_bottom(stack);
	put(stack, popped);
}
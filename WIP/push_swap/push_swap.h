#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

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
    t_node          *bottom;
}t_stack;

t_stack*    stack_init(void);
t_node*	    node_init(char data);
char        pop(t_stack *stack);
char	    pop_bottom(t_stack *stack);
void	    put(t_stack *stack, char new_data);
void	    put_bottom(t_stack *stack, char new_data);
void        push(t_stack *from, t_stack *to);
void        swap(t_stack *main, t_stack *sub);
void	    rotate(t_stack *stack);
void	    rrotate(t_stack *stack);

#endif
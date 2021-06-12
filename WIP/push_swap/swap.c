#include "push_swap.h"

void    swap(t_stack *main, t_stack *sub)
{
    char    popped;

    push(main, sub);
    popped = pop(main);
    push(sub, main);
    put(main, popped);
}
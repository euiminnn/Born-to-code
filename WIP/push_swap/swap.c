#include "push_swap.h"

void    swap(t_stack *main, t_stack *sub)
{
    char    popped;

    push(main, sub);
    popped = pop(main);
    printf("asdf before:\n");
    push(sub, main);
    printf("asdf\n");
    put(main, popped);
}
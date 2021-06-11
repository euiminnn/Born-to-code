#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

typedef struct s_node
{
    char           *data;
    struct s_node  *prev;
    struct s_node  *next;
}t_node;

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

t_node*    node_init(char *str)
{
    t_node *newnode = (t_node*)malloc(sizeof(t_node));
    newnode->data = (char*)malloc(strlen(str)+1);
    strcpy(newnode->data, str);
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void    push(t_stack *list, char *str)
{
    t_node* newnode;
    t_node* oldtop;

    newnode = node_init(str);

    if (list->top == NULL)
    {
        list->top = newnode;
    }
    else
    {
        oldtop = list->top;
        oldtop->next = newnode;
        newnode->prev = oldtop;
        list->top = newnode;
    }
    list->size++;
}

void    pop(t_stack *list)
{
    t_node *currtop;
    t_node *newtop;

    currtop = list->top;

    if (currtop == NULL)
        return ;
    else
    {
        newtop = list->top->prev;
        newtop->next = NULL;
        list->top = newtop;
    }
    list->size--;
    free(currtop->data);
    free(currtop);
}

int main(void) {
    t_stack* stack;

    stack = stack_init();
    
    printf("<Push 1>\n");
    push(stack, "1");
    printf("top : %s\n\n", stack->top->data);
;
    
    printf("<Push 2, 3, 4>\n");
    push(stack, "2");
    push(stack, "3");
    push(stack, "4");
    printf("top : %s\n\n", stack->top->data);   
    printf("Stack A\n");
	printf("%s\n", stack->top->data);
	printf("%s\n", stack->top->prev->data);
	printf("%s\n", stack->top->prev->prev->data);
	printf("%s\n", stack->top->prev->prev->prev->data);
    printf("\n");

    printf("<Pop>\n");
    pop(stack);
    printf("top : %s\n\n", stack->top->data);
    printf("Stack A\n");
	printf("%s\n", stack->top->data);
	printf("%s\n", stack->top->prev->data);
	printf("%s\n", stack->top->prev->prev->data);
	printf("%s\n", stack->top->prev->prev->prev);

    printf("Pop two nodes\n");
    pop(stack);
    pop(stack);
    printf("top : %s\n\n", stack->top->data);
    
    return 0;
}
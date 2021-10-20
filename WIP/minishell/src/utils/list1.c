#include "utils/list.h"
#include "utils/utils.h"

static t_list	*create_node(void *data)
{
	t_list *output;

	output = malloc(sizeof(t_list));
	if (!output)
		exit(12);
	output->data = data;
	output->next = NULL;
	return (output);
}

t_list	*init_list()
{
	return (create_node(NULL));
}

void    push_list(t_list *list, void *data)
{
	t_list *push_position;
	t_list *new_node;

	push_position = list;
	new_node = create_node(data);
	while (push_position->next)
		push_position = push_position->next;
	push_position->next = new_node;
}

void    free_list(t_list *list, void (*del)(void *data))
{
	t_list *delete_position;
	t_list *ptr;

	ptr = list->next;
	while (ptr)
	{
		delete_position = ptr;
		ptr = ptr->next;
		if (del)
			del(delete_position->data);
		free(delete_position);
		delete_position = 0;
	}
	free(list);
}

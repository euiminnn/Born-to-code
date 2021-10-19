#include "utils/list.h"
#include "utils/utils.h"

int count_list(t_list *list)
{
	int		size;
	t_list	*node;

	node = list->next;
	size = 0;
	while (node)
	{
		++size;
		node = node->next;
	}
	return (size);
}

char    **to_string_list(t_list *list, char *(*to_string)(void *data))
{
	int		size;
	int		idx;
	char	**rt;
	t_list	*node;

	size = count_list(list);
    rt = (char **)malloc(sizeof(char *) * (size + 1));
	if (!rt)
        ft_exit(12);
	idx = 0;
	node = list->next;
	while (node)
	{
		rt[idx] = to_string(node->data);
		node = node->next;
		if (rt[idx])
			++idx;
	}
	rt[idx] = 0;
	return (rt);
}

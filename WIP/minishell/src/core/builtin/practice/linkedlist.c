#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char			*key;
	char 			*value;
	struct node*	next;
}	t_node;

void	builtin_export_only(t_node *node)
{
	while (node)
	{
		printf("declare -x ");
		printf("%s", node->key);
		printf("=");
		printf("\"");
		printf("%s", node->value);
		printf("\"\n");
		node = node->next;
	}
}

void	print_list(t_node *node)
{
	while (node)
	{
		printf("key = %s\n", node->key);
		printf("value = %s\n", node->value);
		node = node->next;
	}
}

int main()
{
	t_node* first = NULL;
	t_node* second = NULL;
	t_node* third = NULL;

	first = (t_node*)malloc(sizeof(t_node));
	second = (t_node*)malloc(sizeof(t_node));
	third = (t_node*)malloc(sizeof(t_node));

	first->key = "key1";
	first->value = "value1";
	first->next = second;

	second->key = "key2";
	second->value = "value2";
	second->next = third;

	third->key = "key3";
	third->value = "value3";
	third->next = NULL;

	//print_list(first);
	builtin_export_only(first);

	return (0);
}

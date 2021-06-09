#include <stdio.h>
#include <stdlib.h>

struct NODE
{
	struct NODE *next;
	int data;
};

int main()
{
	struct NODE *head = malloc(sizeof(struct NODE));
	//head 노드에는 data 저장 X

	struct NODE *node1 = malloc(sizeof(struct NODE));
	head->next = node1;
	node1->data = 10;

	struct NODE *node2 = malloc(sizeof(struct NODE));
	node1->next = node2;
	node2->data = 20;

	node2->next = NULL;

	struct NODE *curr = head->next;
	while (curr != NULL)
	{
		printf("%d\n", curr->data);
		curr = curr->next;
	}

	free(node2);
	free(node1);
	free(head);

	return (0);
}

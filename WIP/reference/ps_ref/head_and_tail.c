void	head_and_tail(t_node *node)
{
	t_node	*head;
	t_node	*tail;

	head = node;
	while (node -> next!= NULL)
	{
		node = node -> next;
	}
	tail = node;

	printf("\n");
	printf("head = %c\n", head->data);
	printf("tail = %c\n", tail->data);
	head -> prev = tail;
	tail -> next = head;
}
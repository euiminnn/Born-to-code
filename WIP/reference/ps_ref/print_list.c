void	print_list(t_node *node)
{
	while (node != NULL)
	{
		printf("%c\n", node -> data);
		sleep(1);
		node = node -> next;
	}
}
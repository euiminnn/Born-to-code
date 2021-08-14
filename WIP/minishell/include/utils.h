#ifndef UTILS_H
# define UTILS_H

/*
** util function
*/

# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	void	*data;
	t_list	*next;
	t_list	*prev;
}	t_list;

t_list	*create_list();
void	init_list(t_list *list);
int		push_list(t_list *list, void *data);
int		search_list(t_list *list, int search(void *));
int		pop_list(t_list *list, void **data, void del(void *)));
void	free_list(t_list *list, void del(void *));

void	sh_err(int errno);

#endif
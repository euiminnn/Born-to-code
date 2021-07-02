/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 21:34:37 by echung            #+#    #+#             */
/*   Updated: 2021/07/02 18:45:36 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

struct	s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
};

typedef struct s_node	t_node;

typedef struct s_stack
{
    int             size;
    t_node          *top;
    t_node          *bottom;
}t_stack;

typedef struct s_pnode
{
	char			*op;
	struct s_pnode	*prev;
	struct s_pnode	*next;
}t_pnode;

typedef struct s_print
{
	int				size;
	t_pnode			*top;
	t_pnode			*bottom;
}t_print;

void		get_pivot(t_stack *stack, int len, int *pivot);
void		stack_to_array(t_stack *stack, int *arr, int len);
void		quick_sort(int *data, int up, int down);
void		sort_small(t_stack *a, t_stack *b, t_print *p);
int			a_to_b(t_stack *a, t_stack *b, int len, t_print *p);
int			b_to_a(t_stack *a, t_stack *b, int len, t_print *p);

t_stack*    stack_init(void);
t_node*	    node_init(int data);

int	        pop(t_stack *stack);
int		    pop_bottom(t_stack *stack);
void	    put(t_stack *stack, int new_data);
void	    put_bottom(t_stack *stack, int new_data);
void        push(t_stack *from, t_stack *to, char ab, t_print *p);
void	    rotate(t_stack *stack, char ab, t_print *p);
void	    rrotate(t_stack *stack, char ab, t_print *p);
void	    rrrotate(t_stack *main, t_stack *sub, t_print *p);
void        swap(t_stack *main, t_stack *sub, char ab, t_print *p);

t_print		*print_init(void);
t_pnode		*pnode_init(char *op);
void		pput(t_print *print, char *op);
void		print(t_print *print);

long long	ft_atoi(char *str);
void		ft_bzero(void *s, int n);
int			ft_isdigit(char *c);
void		*ft_memcpy(void *dst, void *src, int n);
void		*ft_memset(void *b, int c, int len);
char		**ft_split(char *s, char c);
int			ft_strlen(char *str);
char		*ft_substr(char *s, int start, int len);


int			is_sorted(t_stack *a);
int			parse_input(int argc, char **argv, t_stack *a);
int			cmp_str(char *s1, char *s2, int n);

#endif

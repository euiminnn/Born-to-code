/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 21:34:37 by echung            #+#    #+#             */
/*   Updated: 2021/06/27 20:17:20 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
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


void		get_pivot(t_stack *stack, int len, int *pivot);
void		stack_to_array(t_stack *stack, int *arr, int len);

t_stack*    stack_init(void);
t_node*	    node_init(int data);

int			a_to_b(t_stack *a, t_stack *b, int len);
int			b_to_a(t_stack *a, t_stack *b, int len);

int	        pop(t_stack *stack);
int		    pop_bottom(t_stack *stack);

void		print_stack(char *prefix, t_stack *stack);

void	    put(t_stack *stack, int new_data);
void	    put_bottom(t_stack *stack, int new_data);

void		quick_sort(int *data, int up, int down);

void        push(t_stack *from, t_stack *to, char ab);

void	    rotate(t_stack *stack, char ab);
void	    rrotate(t_stack *stack, char ab);
void	    rrrotate(t_stack *main, t_stack *sub);

void		sort_three(t_stack *main, t_stack *sub);
void		sort_five(t_stack *main, t_stack *sub);

void        swap(t_stack *main, t_stack *sub, char ab);

long long	ft_atoi(char *str);
void		ft_bzero(void *s, size_t n);
int			ft_isdigit(char *c);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memset(void *b, int c, size_t len);
char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);

#endif

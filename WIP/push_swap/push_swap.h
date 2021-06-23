/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 21:34:37 by echung            #+#    #+#             */
/*   Updated: 2021/06/24 03:54:07 by echung           ###   ########.fr       */
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

t_stack*    stack_init(void);
t_node*	    node_init(int data);
int	        pop(t_stack *stack, char ab);
int		    pop_bottom(t_stack *stack);
void	    put(t_stack *stack, int new_data);
void	    put_bottom(t_stack *stack, int new_data);
void        push(t_stack *from, t_stack *to, char ab);
void        swap(t_stack *main, t_stack *sub, char ab);
void	    rotate(t_stack *stack, char ab);
void	    rrotate(t_stack *stack, char ab);
void		print_stack(char *prefix, t_stack *stack);

int*		stack_to_array(t_stack *stack);
int*		get_pivot(t_stack *stack);
int			ft_atoi(char *str);

#endif

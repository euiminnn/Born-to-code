/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 00:31:46 by echung            #+#    #+#             */
/*   Updated: 2021/07/02 11:32:37 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H

# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_node
{
	int			data;
	struct s_node	*prev;
	struct s_node	*next;
}t_node;

typedef struct s_stack
{
    int             size;
    t_node          *top;
    t_node          *bottom;
}t_stack;

int	get_next_line(int fd, char **line);
int	save_line(char **str, char **line, int index);
int	find_index(char *s, char c);

char	*ft_strjoin_free(char *s1, char *s2);
char		*ft_substr(char *s, int start, int len);
int			ft_strlen(char *str);
char	*ft_strdup(char *src);
void	*ft_memcpy(void *dst, void *src, int n);
t_stack*    stack_init(void);
t_node*	    node_init(int data);

int	        pop(t_stack *stack);
int		    pop_bottom(t_stack *stack);
void	    put(t_stack *stack, int new_data);
void	    put_bottom(t_stack *stack, int new_data);
void        push(t_stack *from, t_stack *to);
void	    rotate(t_stack *stack);
void	    rrotate(t_stack *stack);
void	    rrrotate(t_stack *main, t_stack *sub);
void        swap(t_stack *main, t_stack *sub);
int			is_sorted(t_stack *a);
int			parse_input(int argc, char **argv, t_stack *a);
char			**ft_split(char *s, char c);

#endif

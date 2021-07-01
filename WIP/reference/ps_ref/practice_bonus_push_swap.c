/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 22:59:07 by echung            #+#    #+#             */
/*   Updated: 2021/07/02 03:20:20 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define BUFFER_SIZE 1

static int	check_unique(t_stack *stack, int dup)
{
	t_node	*node;

	node = stack->top;
	if (!node)
		return (1);
	while (node->prev)
	{
		if (dup == node->data)
			return (0);
		node = node->prev;
	}
	if (dup == node->data)
		return (0);
	return (1);
}

static int	check_input(t_stack *stack, char *num)
{
	long long	integer;

	integer = ft_atoi(num);
	if (!(ft_isdigit(num)))
		return (0);
	if (!(check_unique(stack, integer)))
		return (0);
	if (!(integer <= 2147483647 && integer >= -2147483648))
		return (0);
	return (1);
}

static void	free_split(char **splitted)
{
	char	**s;

	s = splitted;
	while (*s != 0)
		free(*s++);
	free(splitted);
}

static int	parse_input(int argc, char **argv, t_stack *a)
{
	int		i;
	char	**splitted;
	char	**s;
	int		j;

	i = argc - 1;
	while (i > 0)
	{
		splitted = ft_split(argv[i], ' ');
		s = splitted;
		j = -1;
		while (*s++ != 0)
			j++;
		if (j == -1)
			return (0);
		while (j >= 0)
		{
			if (!(check_input(a, splitted[j])))
				return (0);
			put(a, ft_atoi(splitted[j--]));
		}
		i--;
		free_split(splitted);
	}
	return (1);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*s1plus2;
	size_t	len_s1;
	size_t	len_s2;

	if (!(s1))
		return (0);
	if (!(s2))
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s1plus2 = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!(s1plus2))
		return (0);
	ft_memcpy(s1plus2, s1, len_s1);
	ft_memcpy(s1plus2 + len_s1, s2, len_s2);
	s1plus2[len_s1 + len_s2] = '\0';
	free((void *)s1);
	s1 = NULL;
	return (s1plus2);
}

char	*ft_strdup(char *src)
{
	char	*new;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		size++;
	if (!(new = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int	find_index(char *s, char c)
{
	int	index;

	index = 0;
	while (*s != '\0')
	{
		if (*s == c)
			return (index);
		s++;
		index++;
	}
	return (-1);
}

int	save_line(char **str, char **line, int index)
{
	char	*temp;

	*line = ft_substr(*str, 0, index);
	temp = ft_substr(*str, index + 1, ft_strlen(*str) - index - 1);
	free(*str);
	*str = temp;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*str;
	int			ret;
	int			i_nl;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0)
		return (-1);
	if (str && ((i_nl = find_index(str, '\n')) != -1))
		return (save_line(&str, line, i_nl));
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		str = ft_strjoin_free(str ? str : ft_strdup(""), buff);
		if (((i_nl = find_index(str, '\n')) != -1))
			return (save_line(&str, line, i_nl));
	}
	if (str)
	{
		*line = ft_strdup(str);
		free(str);
		str = NULL;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

static int	cmp_str(char *s1, char *s2, int n)
{
	while (*s1 != '\0' && *s2 != '\0' && n > 0)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (1);
	else
		return (0);
}

#include <stdio.h>

void	wait_instruction_and_sort(t_stack *a, t_stack *b)
{
	char	*line;
	int		gnl_return;

	while ((gnl_return = get_next_line(0, &line)) > 0)
	{
		if (cmp_str(line, "sa", 2))
			swap(a, b, 'a', p);
		else if (cmp_str(line, "sb", 2))
			swap(b, a, 'b', p);
		else if (cmp_str(line, "ss", 2))
		{
			swap(a, b, 'a', p);
			swap(b, a, 'b', p);
		}
		else if (cmp_str(line, "ra", 2))
			rotate(a, 'a', p);
		else if (cmp_str(line, "rb", 2))
			rotate(b, 'b', p);
		else if (cmp_str(line, "rr", 2))
		{
			rotate(a, 'a', p);
			rotate(b, 'b', p);
		}
		else if (cmp_str(line, "rra", 3)) rrotate(a, 'a', p);
		else if (cmp_str(line, "rrb", 3))
			rrotate(b, 'b', p);
		else if (cmp_str(line, "rrr", 3))
			rrrotate(a, b, p);
		else if (cmp_str(line, "pa", 2))
			push(b, a, 'a', p);
		else if (cmp_str(line, "pb", 2))
			push(a, b, 'b', p);
		free(line);
		line = NULL;
		write(1, "\n", 1);
	}
	printf("a size = %d\n", a->size);
	printf("b size = %d\n", b->size);
}

int			main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_print	*p;

	a = stack_init();
	b = stack_init();
	p = print_init();
	if (parse_input(argc, argv, a))
	{
		if (a->size == 3 || a->size == 4 || a->size == 5)
			sort_small(a, b, p);
		else
			a_to_b(a, b, a->size, p);
	}
	else
		write(2, "Error\n", 6);
	wait_instruction_and_sort(a, b);
	print(p);
	return (0);
}

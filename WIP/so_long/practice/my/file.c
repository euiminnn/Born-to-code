/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 00:50:55 by echung            #+#    #+#             */
/*   Updated: 2021/08/07 22:47:32 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1

void	*ft_memset(void *b, int c, int len)
{
	unsigned char	*b_org;
	unsigned char	*b_mod;
	unsigned char	c_mod;

	b_org = b;
	b_mod = b;
	c_mod = c;
	while (len > 0)
	{
		*b_mod = c_mod;
		b_mod++;
		len--;
	}
	return (b_org);
}

void	ft_bzero(void *s, int n)
{
	ft_memset(s, 0, n);
}

int	ft_strlen(const char *str)
{
	int	num;

	num = 0;
	while (*str != '\0')
	{
		num++;
		str++;
	}
	return (num);
}

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char	*sub_of_s;
	int		len_org;

	sub_of_s = malloc(sizeof(char) * (len + 1));
	if (!(s))
		return (0);
	if (!(sub_of_s))
		return (0);
	len_org = ft_strlen(s);
	if (start < len_org)
		ft_memcpy(sub_of_s, s + start, len);
	sub_of_s[len] = '\0';
	return (sub_of_s);
}

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	char	*s1plus2;
	int		len_s1;
	int		len_s2;

	if (!(s1))
		return (ft_strdup(s2));
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

char	*ft_strdup(const char *src)
{
	char	*new;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		size++;
	new = malloc(sizeof(char) * (size + 1));
	if (!new)
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

void	*ft_memcpy(void *dst, const void *src, int n)
{
	unsigned char	*dst_org;
	unsigned char	*dst_mod;
	unsigned char	*src_mod;

	dst_org = dst;
	dst_mod = dst;
	src_mod = (unsigned char *)src;
	if (dst == 0 && src == 0)
		return (0);
	while (n > 0)
	{
		*dst_mod = *src_mod;
		dst_mod++;
		src_mod++;
		n--;
	}
	return (dst_org);
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

static int	save_line(char **str, char **line, int index)
{
	char	*temp;

	*line = ft_substr(*str, 0, index);
	temp = ft_substr(*str, index + 1, ft_strlen(*str) - index - 1);
	free(*str);
	*str = temp;
	return (1);
}

char	*ft_strjoin_free_sub(char *str, char *buff)
{
	char	*ret;

	if (str)
		ret = ft_strjoin_free(str, buff);
	else
		ret = ft_strjoin_free(ft_strdup(""), buff);
	return (ret);
}

int	get_next_line_sub(char **str, char **line)
{
	*line = ft_strdup(*str);
	free(*str);
	*str = NULL;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*str;
	int			ret;
	char		buff[BUFFER_SIZE + 1];
	int			i_nl;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0)
		return (-1);
	if (str)
		i_nl = find_index(str, '\n');
	if (str && (i_nl != -1))
		return (save_line(&str, line, i_nl));
	ret = read(fd, buff, BUFFER_SIZE);
	while (ret > 0)
	{
		buff[ret] = '\0';
		str = ft_strjoin_free_sub(str, buff);
		i_nl = find_index(str, '\n');
		if (i_nl != -1)
			return (save_line(&str, line, i_nl));
		ret = read(fd, buff, BUFFER_SIZE);
	}
	if (str)
		return (get_next_line_sub(&str, line));
	*line = ft_strdup("");
	return (0);
}

int	count_gnl(char *filename)
{
	int		fd;
	int		row;
	int		check;
	char	*line;

	fd = open(filename, O_RDONLY);
	row = 0;
	check = get_next_line(fd, &line);
	while (check > 0)
	{
		row++;
		free(line);
		check = get_next_line(fd, &line);
	}
	free(line);
	close(fd);
	return (row);
}

// input : file name
// output : array
char	**readfile(char *filename, int row)
{
	int		fd;
	char	*line;
	int		check;
	char	**arr;
	int		i;

	arr = malloc(sizeof(char *) * row);
	if (!arr)
		return (0);
	fd = open(filename, O_RDONLY);
	i = 0;
	check = get_next_line(fd, &line);
	while (check > 0)
	{
		arr[i] = line;
		i++;
		check = get_next_line(fd, &line);
	}
	free(line);
	if (check == -1)
		return (0);
	close(fd);
	return (arr);
}

int	is_instring(int c, char *s)
{
	if (c == '\0')
		return (0);
	while (*s != '\0')
	{
		if (c == *s)
			return (1);
		s++;
	}
	return (0);
}

int	check_element(char **arr, int row, int column)
{
	int	i;
	int	j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < column)
		{
			if (is_instring(arr[i][j], "01CEP"))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	is_surrounded(char **arr, int row, int column, t_iter it)
{
	it.i = 0;
	it.j = 0;
	while (it.j < column)
	{
		if (arr[0][it.j] == '1' && arr[row - 1][it.j] == '1')
			(it.j)++;
		else
		{
			printf("🚫 Error: column not surrounded\n");
			return (0);
		}
	}
	while (it.i < row)
	{
		if (arr[it.i][0] == '1' && arr[it.i][column - 1] == '1')
			it.i++;
		else
		{
			printf("🚫 Error: row not surrounded\n");
			return (0);
		}
	}
	return (1);
}

int	is_samecolnum(char **arr, int row, int column)
{
	int	i;

	i = 0;
	while (i < row)
	{
		if (ft_strlen(arr[i]) == column)
			i++;
		else
		{
			printf("🚫 Error: different column size\n");
			return (0);
		}
	}
	return (1);
}

#define E 0
#define C 1
#define P 2

int	essential_element(char **arr, int row, int column, t_iter it)
{
	int	element[3];

	ft_bzero(element, sizeof(element));
	it.i = 0;
	while (it.i < row)
	{
		it.j = 0;
		while (it.j < column)
		{
			if (arr[it.i][it.j] == 'E')
				element[E] = 1;
			else if (arr[it.i][it.j] == 'C')
				element[C] = 1;
			else if (arr[it.i][it.j] == 'P')
				element[P] = 1;
			it.j++;
		}
		it.i++;
	}
	if (element[E] * element[C] * element[P] == 1)
		return (1);
	else
		return (0);
}

#define MAX_SCORE 4
int	parse_map(char **arr, int row, int column)
{
	int		score;
	t_iter	iter;

	score = 0;
	if (is_samecolnum(arr, row, column))
		score++;
	else
		return (0);
	if (is_surrounded(arr, row, column, iter))
		score++;
	if (check_element(arr, row, column))
		score++;
	if (essential_element(arr, row, column, iter))
		score++;
	if (score == MAX_SCORE)
		return (1);
	else
		return (0);
}
/*
int			main(void)
{
	int	row;
	int	column;

	arr = readfile("map.ber");
	//printf("%s\n", arr[0]);
	row = count_gnl("map.ber");
	column = ft_strlen(arr[0]);
	if (parse_map(arr, row, column))
		printf("✅ Valid map\n");
	else
		printf("Error: invalid map\n");
	free(arr);
}
*/

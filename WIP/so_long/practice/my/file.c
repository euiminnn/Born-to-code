/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 00:50:55 by echung            #+#    #+#             */
/*   Updated: 2021/08/06 21:02:11 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>


//char	**arr;

#define BUFFER_SIZE 1

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
	int	len_org;

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
	int	len_s1;
	int	len_s2;

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

int			get_next_line(int fd, char **line)
{
	static char	*str;
	int			ret;
	int			i_nl;
	char		buff[BUFFER_SIZE + 1];

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

int		count_gnl(char *filename)
{
	int		fd;
	int		row;
	int		check;
	char	*line;

	fd = open(filename, O_RDONLY);
	row = 0;

	while ((check = get_next_line(fd, &line)) > 0)
	{
		row++;
		free(line);
	}
	free(line);
	close(fd);
	return (row);
}

// input : file name
// output : array
char	**readfile(char *filename)
{
    int    	fd;
	char	*line;
	int		check;
	int		row;
	char	**arr;
	int		i;

	row = count_gnl(filename);
	arr = malloc(sizeof(char*) * row);
	if (!arr)
		return (0);
    fd = open(filename, O_RDONLY);

	i = 0;
	while ((check = get_next_line(fd, &line)) > 0)
	{
		arr[i] = line;
		i++;
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
	int i;
	int j;

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

int	is_surrounded(char **arr, int row, int column)
{
	int i;
	int j;
	i = 0;
	j = 0;
	while (j < column)
	{
		if (arr[0][j] == '1' && arr[row-1][j] == '1')
			j++;
		else
		{
			printf("🚫 Error: column not surrounded\n");
			return (0);
		}
	}
	while (i < row)
	{
		if (arr[i][0] == '1' && arr[i][column-1] == '1')
			i++;
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
	int i;
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

int	essential_element(char **arr, int row, int column)
{
	int e;
	int c;
	int p;

	e = 0;
	c = 0;
	p = 0;

	int i;
	int j;
	
	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < column)
		{
			if (arr[i][j] == 'E')
				e++;
			else if (arr[i][j] == 'C')
				c++;
			else if (arr[i][j] == 'P')
				p++;
			j++;
		}
		i++;
	}
	if (e*c*p == 1)
		return (1);
	else
	{
		printf("🚫 Essential element is missing!\n");
		return (0);
	}
}

#define MAX 4
int	parse_map(char **arr, int row, int column)
{
	int score;

	score = 0;
	if (is_samecolnum(arr, row, column))
		score++;
	else
		return (0);
	if (is_surrounded(arr, row, column))
		score++;
	if (check_element(arr, row, column))
		score++;
	if (essential_element(arr, row, column))
		score++;
	if (score == MAX)
		return (1);
	else
		return (0);
}
/*
int main(void)
{
	arr = readfile("map.ber");
	//printf("%s\n", arr[0]);

	int row = count_gnl("map.ber");
	int column = ft_strlen(arr[0]);
	
	if (parse_map(arr, row, column))
		printf("✅ Valid map\n");
	else
		printf("Error: invalid map\n");
	free(arr);
}
*/

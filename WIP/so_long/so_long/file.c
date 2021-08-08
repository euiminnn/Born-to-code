/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 00:50:55 by echung            #+#    #+#             */
/*   Updated: 2021/08/08 22:52:52 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

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

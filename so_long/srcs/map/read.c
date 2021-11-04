/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 00:50:55 by echung            #+#    #+#             */
/*   Updated: 2021/10/28 14:31:54 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_row(char *map)
{
	int		fd;
	int		row;
	int		check;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (-1);
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

static int	_read_map(char **arr, int fd)
{
	char	*line;
	int		check;
	int		i;

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
	{
		free_all(arr, i);
		return (-1);
	}
	return (0);
}

char	**read_map(char *map, int row)
{
	int		fd;
	char	**arr;
	int		ret;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (0);
	arr = malloc(sizeof(char *) * row);
	if (!arr)
		return (0);
	ret = _read_map(arr, fd);
	if (ret == -1)
		return (0);
	close(fd);
	return (arr);
}

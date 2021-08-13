/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 00:50:55 by echung            #+#    #+#             */
/*   Updated: 2021/08/13 21:49:39 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_row(char *filename)
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

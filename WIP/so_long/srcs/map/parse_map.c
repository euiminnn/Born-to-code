/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 22:37:06 by echung            #+#    #+#             */
/*   Updated: 2021/08/18 18:51:29 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define E 0
#define C 1
#define P 2

static int	essential_element(char **arr, int row, int column, t_iter it)
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

static int	check_element(char **arr, int row, int column)
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

static int	is_surrounded(char **arr, int row, int column, t_iter it)
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

static int	is_samecolnum(char **arr, int row, int column)
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

#define MAX_SCORE 4
int	parse_map(char **arr, int row, int column)
{
	int		score;
	t_iter	iter;

	score = 0;
	ft_bzero(&iter, sizeof(t_iter));
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

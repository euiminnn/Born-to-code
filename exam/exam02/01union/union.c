/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 23:48:28 by echung            #+#    #+#             */
/*   Updated: 2021/10/19 01:56:24 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int length(char *str)
{
	int i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return i;
}

int duplicate(char *original, char chr, int i)
{
	while (i > 0)
	{
		if (*original == chr)
			return (1);
		i--;
		original++;
	}
	return (0);
}

void _union(char **argv)
{
	char* first;
	char* second;
	int i;
	int j;

	first = argv[1];
	i = 0;
	while (first[i])
	{
		if (!duplicate(argv[1], first[i], i))
			write(1, &first[i], 1);
		i++;
	}
	second = argv[2];
	j = 0;
	while (second[j])
	{
		if (!duplicate(argv[1], second[j], length(argv[1])))
		{
			if (!duplicate(argv[2], second[j], j))
				write(1, &second[j], 1);
		}
		j++;
	}
}

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	else if (argc == 3)
	{
		_union(argv);
		write(1, "\n", 1);
		return (0);
	}
}

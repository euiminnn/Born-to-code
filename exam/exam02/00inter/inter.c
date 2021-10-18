/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 23:48:28 by echung            #+#    #+#             */
/*   Updated: 2021/10/19 00:48:00 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void inter(char **argv)
{
	char* first;
	char* second;
	int i;

	first = argv[1];
	i = 0;
	while (first[i])
	{
		second = argv[2];
		while (*second)
		{
			if (first[i] == *second)
			{
				if (!duplicate(argv[1], first[i], i))
				{
					write(1, &first[i], 1);
					break ;
				}
			}
			second++;
		}
		i++;
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
		inter(argv);
		write(1, "\n", 1);
		return (0);
	}
}

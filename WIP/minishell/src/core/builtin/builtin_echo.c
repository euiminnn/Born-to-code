/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:20:19 by echung            #+#    #+#             */
/*   Updated: 2021/10/16 01:32:42 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/builtin.h"
#include "core/env.h"
#include <stdio.h>

int valid_n(char *n_option)
{
	char *ptr;

	ptr = n_option;
	if (*ptr == '-')
	{
		ptr++;
		if (!(*ptr))
			return (-1);
		while (*ptr)
		{
			if (*ptr != 'n')
				return (-1);
			ptr++;
		}
		return (0);
	}
	else
		return (-1);
}

int	string_start(int argc, char **argv)
{
	int i = 1;
	while (i < argc)
	{
		if (valid_n(argv[i]))
			return i;	// -n 뒤의 index 반환
		i++;
	}
	return i;
}

void	builtin_echo(int argc, char **argv, t_env *env)
{
	(void)env;

	int n_option;
	int s;

	n_option = 1;
	s = string_start(argc, argv);

	if (valid_n(argv[1]) != 0)	//without n option
		n_option = 0;
	while (s < argc)
	{
		if (s != argc - 1)
			printf("%s ", argv[s]);
		else
			printf("%s", argv[s]);
		s++;
	}
	if (!n_option)
		printf("\n");
}

/*
int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char*)s1 - *(unsigned char*)s2);
}
*/

/*
int main(int argc, char **argv)
{
	int n_option = 1;
	int s;

	s = string_start(argc, argv);

	if (valid_n(argv[1]) != 0)	//without n option
		n_option = 0;
	while (s < argc)
	{
		if (s != argc - 1)
			printf("%s ", argv[s]);
		else
			printf("%s", argv[s]);
		s++;
	}
	if (!n_option)
		printf("\n");
}
*/

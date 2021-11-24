/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 22:21:29 by ycha              #+#    #+#             */
/*   Updated: 2021/11/24 19:20:32 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug/debug_utils.h"

void	print_space(int depth)
{
	int	c;

	c = depth * 4;
	while (c--)
		printf(" ");
}

int	print_strings(char **arr, int depth)
{
	int	idx;

	if (!arr)
		return (OK);
	idx = -1;
	print_space(depth);
	printf("[\n");
	while (arr[++idx])
	{
		print_space(depth + 1);
		printf("`%s`\n", arr[idx]);
	}
	print_space(depth);
	printf("]\n");
	return (OK);
}

int	print_error_type(int errtype)
{
	if (errtype == ERR_PARSE_SYNTAX)
		printf("ERR_PARSE_SYNTAX\n");
	return (OK);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 00:33:45 by echung            #+#    #+#             */
/*   Updated: 2021/08/13 01:56:24 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_arg(char *arg)
{
	int	i;

	i = ft_strlen(arg);
	if (check_char(arg[i - 4], '.') && check_char(arg[i - 3], 'b') \
		&& check_char(arg[i - 2], 'e') && check_char(arg[i - 1], 'r'))
		return (1);
	else
		printf("Usage: ./so_long map.ber\n");
	return (0);
}

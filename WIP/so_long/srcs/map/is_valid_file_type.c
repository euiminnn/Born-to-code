/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_file_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 00:33:45 by echung            #+#    #+#             */
/*   Updated: 2021/10/19 18:42:17 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_file_type(char *arg, char *type)
{
	int	i;

	i = ft_strlen(arg);
	if (check_char(arg[i - 4], type[0]) && check_char(arg[i - 3], type[1]) \
		&& check_char(arg[i - 2], type[2]) && check_char(arg[i - 1], type[3]))
		return (1);
	else
		printf("Usage: ./so_long map.ber\n");
	return (0);
}

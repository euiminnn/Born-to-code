/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 23:37:39 by echung            #+#    #+#             */
/*   Updated: 2021/11/18 23:37:41 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"

void	ft_free_strings(char **arr)
{
	int	idx;

	idx = -1;
	while (arr[++idx])
	{
		free(arr[idx]);
		arr[idx] = 0;
	}
	free(arr);
	arr = 0;
}

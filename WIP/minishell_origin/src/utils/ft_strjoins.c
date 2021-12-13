/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 23:37:48 by echung            #+#    #+#             */
/*   Updated: 2021/11/18 23:37:49 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"

char	*ft_strjoins(char **strs, int n)
{
	char	*temp;
	char	*output;
	int		idx;

	idx = 0;
	output = ft_strdup(strs[idx]);
	while (++idx < n)
	{
		temp = ft_strdup(output);
		free(output);
		output = ft_strjoin(temp, strs[idx]);
		free(temp);
	}
	return (output);
}

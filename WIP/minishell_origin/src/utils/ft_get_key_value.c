/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_key_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 23:36:57 by echung            #+#    #+#             */
/*   Updated: 2021/11/24 19:06:55 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"

void	ft_get_key_and_value(char *line, char **key, char **value)
{
	char	*equal;

	equal = line;
	while (*equal && *equal != '=')
		equal++;
	if (*equal)
	{
		*equal = '\0';
		*key = ft_strdup(line);
		*value = ft_strdup(equal + 1);
		*equal = '=';
	}
	else
	{
		*key = ft_strdup(line);
		*value = NULL;
	}
}

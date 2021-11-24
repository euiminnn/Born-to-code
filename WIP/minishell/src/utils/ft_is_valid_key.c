/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_key.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 23:36:57 by echung            #+#    #+#             */
/*   Updated: 2021/11/24 19:55:25 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include "define.h"

int	ft_is_valid_key(char *key)
{
	if (!key || key[0] == '\0')
		return (0);
	if ('0' <= key[0] && key[0] <= '9')
		return (0);
	while (*key)
	{
		if (!(('a' <= *key && *key <= 'z') || ('A' <= *key && *key <= 'Z')
				|| ('0' <= *key && *key <= '9') || (*key == '_')))
			return (0);
		key++;
	}
	return (1);
}

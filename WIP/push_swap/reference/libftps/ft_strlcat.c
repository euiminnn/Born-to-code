/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:23:25 by echung            #+#    #+#             */
/*   Updated: 2021/01/27 17:10:42 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	index_d;
	size_t	index_s;

	index_d = 0;
	while (*(dst + index_d) != '\0')
		index_d++;
	if (index_d >= dstsize)
		return (dstsize + ft_strlen(src));
	index_s = 0;
	while (*(src + index_s) != '\0' && dstsize - index_d - 1 > index_s)
	{
		*(dst + index_d + index_s) = *(src + index_s);
		index_s++;
	}
	*(dst + index_d + index_s) = '\0';
	return (index_d + ft_strlen(src));
}

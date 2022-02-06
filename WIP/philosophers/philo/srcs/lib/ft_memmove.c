/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 14:00:19 by echung            #+#    #+#             */
/*   Updated: 2021/01/22 15:29:48 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_org;
	unsigned char	*dst_mod;
	unsigned char	*src_mod;
	size_t			index;

	dst_org = dst;
	dst_mod = dst;
	src_mod = (unsigned char *)src;
	index = 0;
	if (dst == 0 && src == 0)
		return (0);
	if (dst > src)
	{
		while (++index <= len)
			dst_mod[len - index] = src_mod[len - index];
		return (dst_org);
	}
	while (len > 0)
	{
		*(dst_mod++) = *(src_mod++);
		len--;
	}
	return (dst_org);
}

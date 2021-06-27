/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 13:13:34 by echung            #+#    #+#             */
/*   Updated: 2021/06/27 17:31:08 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_org;
	unsigned char	*dst_mod;
	unsigned char	*src_mod;

	dst_org = dst;
	dst_mod = dst;
	src_mod = (unsigned char *)src;
	if (dst == 0 && src == 0)
		return (0);
	while (n > 0)
	{
		*dst_mod = *src_mod;
		dst_mod++;
		src_mod++;
		n--;
	}
	return (dst_org);
}

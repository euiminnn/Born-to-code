/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 22:51:29 by echung            #+#    #+#             */
/*   Updated: 2021/08/08 22:51:54 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memset(void *b, int c, int len)
{
	unsigned char	*b_org;
	unsigned char	*b_mod;
	unsigned char	c_mod;

	b_org = b;
	b_mod = b;
	c_mod = c;
	while (len > 0)
	{
		*b_mod = c_mod;
		b_mod++;
		len--;
	}
	return (b_org);
}

void	ft_bzero(void *s, int n)
{
	ft_memset(s, 0, n);
}

void	*ft_memcpy(void *dst, const void *src, int n)
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

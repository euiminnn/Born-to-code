/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 13:28:47 by echung            #+#    #+#             */
/*   Updated: 2021/01/22 13:58:51 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst_mod;
	unsigned char	*src_mod;
	unsigned char	c_mod;

	c_mod = c;
	dst_mod = dst;
	src_mod = (unsigned char *)src;
	while (n > 0)
	{
		if (*src_mod == c_mod)
		{
			*dst_mod = *src_mod;
			return (dst_mod + 1);
		}
		*dst_mod = *src_mod;
		dst_mod++;
		src_mod++;
		n--;
	}
	return (0);
}

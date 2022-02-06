/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:14:17 by echung            #+#    #+#             */
/*   Updated: 2021/01/27 16:44:26 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_mod;
	unsigned char	*s2_mod;

	s1_mod = (unsigned char *)s1;
	s2_mod = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (*s1_mod == *s2_mod && n - 1 > 0)
	{
		s1_mod++;
		s2_mod++;
		n--;
	}
	return (*s1_mod - *s2_mod);
}

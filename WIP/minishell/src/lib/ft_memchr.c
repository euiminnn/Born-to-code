/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:42:09 by echung            #+#    #+#             */
/*   Updated: 2021/01/28 19:28:21 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	c_mod;
	char	*s_mod;

	c_mod = c;
	s_mod = (char *)s;
	while (n > 0)
	{
		if (*s_mod == c_mod)
			return (s_mod);
		s_mod++;
		n--;
	}
	return (0);
}

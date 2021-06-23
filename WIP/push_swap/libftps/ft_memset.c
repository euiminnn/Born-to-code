/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 20:23:02 by echung            #+#    #+#             */
/*   Updated: 2021/01/21 20:45:57 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
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

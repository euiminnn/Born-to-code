/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:25:39 by echung            #+#    #+#             */
/*   Updated: 2021/01/22 15:34:12 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	real_c;

	real_c = c;
	while (*s != '\0')
	{
		if (real_c == *s)
			return ((char *)s);
		s++;
	}
	if (real_c == '\0')
		return ((char *)s);
	else
		return (0);
}

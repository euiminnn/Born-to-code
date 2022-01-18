/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:25:39 by echung            #+#    #+#             */
/*   Updated: 2021/01/22 15:35:54 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*orig_s;

	orig_s = s;
	while (*s != '\0')
		s++;
	if (c == '\0')
		return ((char *)s);
	while (s != orig_s)
	{
		s--;
		if (c == *s)
			return ((char *)s);
	}
	return (0);
}

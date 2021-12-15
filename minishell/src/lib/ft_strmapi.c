/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:30:53 by echung            #+#    #+#             */
/*   Updated: 2021/01/26 19:54:32 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*s_mod;
	char	*applied;
	size_t	index;

	if (!(s))
		return (0);
	s_mod = (char *)s;
	len = ft_strlen(s_mod);
	applied = malloc(sizeof(char) * (len + 1));
	if (!(applied))
		return (0);
	index = 0;
	while (index < len)
	{
		applied[index] = f(index, s_mod[index]);
		index++;
	}
	applied[len] = '\0';
	return (applied);
}

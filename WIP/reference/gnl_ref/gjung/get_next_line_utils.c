/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjung <gjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 13:39:31 by gjung             #+#    #+#             */
/*   Updated: 2021/02/02 12:49:57 by gjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *str)
{
	size_t	strlen;
	size_t	i;
	char	*dest;

	i = 0;
	strlen = ft_strlen(str);
	dest = (char *)malloc(sizeof(char) * (strlen + 1));
	if (!dest)
		return (0);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;
	char	*str;

	s1_len = s1 == 0 ? 0 : ft_strlen(s1);
	s2_len = s2 == 0 ? 0 : ft_strlen(s2);
	str = (char *)malloc(sizeof(char *) * (s1_len + s2_len + 1));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	if (s1 != 0)
	{
		while (s1[j])
			str[i++] = s1[j++];
	}
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = 0;
	return (str);
}

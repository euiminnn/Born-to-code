/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:01:52 by echung            #+#    #+#             */
/*   Updated: 2021/06/27 05:57:09 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_countwords(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != c && *s != '\0')
			count = count + 1;
		while (*s != c && *s != '\0')
			s++;
	}
	return (count);
}

static size_t	ft_wordslen(char const *s, char c, size_t index)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = -1;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != c && *s != '\0')
		{
			i = i + 1;
			if (i == index)
			{
				while (*s != c && *s != '\0')
				{
					len++;
					s++;
				}
			}
		}
		while (*s != c && *s != '\0')
			s++;
	}
	return (len);
}

static size_t	ft_startidx(char const *s, char c, size_t index)
{
	size_t	start;
	size_t	i;

	start = 0;
	i = -1;
	while (*s != '\0')
	{
		while (*s == c)
		{
			s++;
			start++;
		}
		if (*s != c && *s != '\0')
		{
			i = i + 1;
			if (i == index)
				return (start);
		}
		while (*s != c && *s != '\0')
		{
			s++;
			start++;
		}
	}
	return (0);
}

static char		**ft_freeall(char **s, size_t index)
{
	while (index >= 0)
	{
		index--;
		free(s[index]);
	}
	free(s);
	return (0);
}

char			**ft_split(char const *s, char c)
{
	char	**splitted;
	size_t	start;
	size_t	len;
	size_t	index;

	if (!(s))
		return (0);
	splitted = (char **)malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!(splitted))
		return (0);
	index = 0;
	while (index < ft_countwords(s, c))
	{
		start = ft_startidx(s, c, index);
		len = ft_wordslen(s, c, index);
		splitted[index] = ft_substr(s, start, len);
		if (splitted[index] == 0)
			return (ft_freeall(splitted, index));
		index++;
	}
	splitted[index] = 0;
	return (splitted);
}

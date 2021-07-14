/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:01:52 by echung            #+#    #+#             */
/*   Updated: 2021/07/02 18:27:58 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_countwords(char *s, char c)
{
	int	count;

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

static int	ft_wordslen(char *s, char c, int index)
{
	int	len;
	int	i;

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

static int	ft_startidx(char *s, char c, int index)
{
	int	start;
	int	i;

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

static char	**ft_freeall(char **s, int index)
{
	while (index >= 0)
	{
		index--;
		free(s[index]);
	}
	free(s);
	return (0);
}

char		**ft_split(char *s, char c)
{
	char	**splitted;
	int		start;
	int		len;
	int		index;

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

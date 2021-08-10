/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 22:48:26 by echung            #+#    #+#             */
/*   Updated: 2021/08/10 18:22:42 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	num;

	num = 0;
	while (*str != '\0')
	{
		num++;
		str++;
	}
	return (num);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*sub_of_s;
	int		len_org;

	sub_of_s = malloc(sizeof(char) * (len + 1));
	if (!(s))
		return (0);
	if (!(sub_of_s))
		return (0);
	len_org = ft_strlen(s);
	if (start < len_org)
		ft_memcpy(sub_of_s, s + start, len);
	sub_of_s[len] = '\0';
	return (sub_of_s);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*s1plus2;
	int		len_s1;
	int		len_s2;

	if (!(s1))
		return (ft_strdup(s2));
	if (!(s2))
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s1plus2 = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!(s1plus2))
		return (0);
	ft_memcpy(s1plus2, s1, len_s1);
	ft_memcpy(s1plus2 + len_s1, s2, len_s2);
	s1plus2[len_s1 + len_s2] = '\0';
	free((void *)s1);
	s1 = NULL;
	return (s1plus2);
}

char	*ft_strjoin_free_sub(char *str, char *buff)
{
	char	*ret;

	if (str)
		ret = ft_strjoin_free(str, buff);
	else
		ret = ft_strjoin_free(ft_strdup(""), buff);
	return (ret);
}

char	*ft_strdup(char *src)
{
	char	*new;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		size++;
	new = malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

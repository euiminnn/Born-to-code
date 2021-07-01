/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 00:29:23 by echung            #+#    #+#             */
/*   Updated: 2021/07/02 00:55:38 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*s1plus2;
	int	len_s1;
	int	len_s2;

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

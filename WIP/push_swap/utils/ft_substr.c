/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:33:01 by echung            #+#    #+#             */
/*   Updated: 2021/06/27 17:30:54 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_of_s;
	size_t	len_org;

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

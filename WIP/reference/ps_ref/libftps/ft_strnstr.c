/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 18:44:04 by echung            #+#    #+#             */
/*   Updated: 2021/01/21 19:22:13 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*haystack_nth;
	char	*needle_org;
	size_t	len_org;

	len_org = len;
	haystack_nth = (char *)haystack;
	needle_org = (char *)needle;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack_nth != '\0' && (len = len_org) > 0)
	{
		while (*needle != '\0' && len-- > 0)
		{
			if (*haystack != *needle)
				break ;
			haystack++;
			needle++;
		}
		if (*needle == '\0')
			return (haystack_nth);
		len_org--;
		haystack = ++haystack_nth;
		needle = needle_org;
	}
	return (0);
}

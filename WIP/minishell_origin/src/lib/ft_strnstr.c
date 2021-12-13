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
	size_t		temp_n;
	const char	*temp;
	const char	*ptr;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len)
	{
		temp_n = len;
		temp = haystack;
		ptr = needle;
		while (*ptr && temp_n)
		{
			if (*temp != *ptr)
				break ;
			++temp;
			++ptr;
			--temp_n;
		}
		if (*ptr == 0)
			return ((char *)haystack);
		++haystack;
		--len;
	}
	return (0);
}

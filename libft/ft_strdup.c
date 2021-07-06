/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:52:09 by echung            #+#    #+#             */
/*   Updated: 2021/01/23 18:17:22 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copied;
	size_t	len;

	len = ft_strlen(s1);
	copied = ft_calloc(len + 1, sizeof(char));
	if (!(copied))
		return (0);
	ft_memcpy(copied, s1, len);
	copied[len] = '\0';
	return (copied);
}

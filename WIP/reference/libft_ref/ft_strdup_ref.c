/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_ref.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:06:56 by echung            #+#    #+#             */
/*   Updated: 2021/01/23 18:12:07 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_ref(const char *s1)
{
	char	*copied;

	copied = ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (!(copied))
		return (0);
	ft_memcpy(copied, s1, ft_strlen(s1));
	copied[ft_strlen(s1)] = '\0';
	return (copied);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:01:52 by echung            #+#    #+#             */
/*   Updated: 2021/01/26 20:43:31 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	char		**splitted;
	char		**splitted_org;
	char 		*set;

	splitted_org = splitted;
	set = &c;
	if (!(s))
		return (0);
	while (*s != '\0')
	{
		splitted = ft_strtrim(s, set);
		s++;
	}
	return(splitted_org);
}

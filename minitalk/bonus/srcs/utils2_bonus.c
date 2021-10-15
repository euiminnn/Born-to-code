/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:54:52 by echung            #+#    #+#             */
/*   Updated: 2021/10/04 20:15:34 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_isinteger(char *c)
{
	if (*c == '\0')
		return (0);
	while (*c != '\0')
	{
		if ('0' <= *c && *c <= '9')
			c++;
		else
			return (0);
	}
	return (1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 20:18:34 by echung            #+#    #+#             */
/*   Updated: 2021/03/20 20:55:17 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_len(unsigned long value, int base)
{
	int	len;

	len = 1;
	while ((value /= base) > 0)
		len++;
	return (len);
}

void	my_write(int fildes, const void *buf, size_t nbyte)
{
	while (nbyte > 0)
	{
		write(fildes, buf, 1);
		g_ret++;
		buf++;
		nbyte--;
	}
}

int		max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

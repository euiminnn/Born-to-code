/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_lx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 16:13:00 by echung            #+#    #+#             */
/*   Updated: 2021/03/14 01:55:33 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd_lx(unsigned int n, int fd)
{
	char *base;

	base = "0123456789ABCDEF";
	if (n > 15)
		ft_putnbr_fd_lx(n / 16, fd);
	ft_putchar_fd(base[n % 16], fd);
}

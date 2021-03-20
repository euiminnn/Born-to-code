/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_sx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 16:13:00 by echung            #+#    #+#             */
/*   Updated: 2021/03/14 01:56:01 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd_sx(unsigned int n, int fd)
{
	char *base;

	base = "0123456789abcdef";
	if (n > 15)
		ft_putnbr_fd_sx(n / 16, fd);
	ft_putchar_fd(base[n % 16], fd);
}

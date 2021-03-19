/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 16:13:00 by echung            #+#    #+#             */
/*   Updated: 2021/03/19 11:39:34 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd('8', fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else
	{
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd('0' + n % 10, fd);
	}
}

void	ft_putnbr_fd_u(unsigned int n, int fd)
{
	if (n > 9)
		ft_putnbr_fd_u(n / 10, fd);
	ft_putchar_fd('0' + n % 10, fd);
}

void	ft_putnbr_fd_p(unsigned int n, int fd)
{
	char	*base;
	int		len;

	base = "0123456789abcdef";
	len = intlen(n, 16);	//16진법으로 바꾼 후의 길이
/*	if (len == 8)
		ft_putchar_fd('1', fd);
	else if (len == 7)		//왜 len 8, also len 7 ?
	{
		ft_putchar_fd('1', fd);
		ft_putchar_fd('0', fd);
	}
*/
	if (n > 15)
		ft_putnbr_fd_p(n / 16, fd);
	ft_putchar_fd(base[n % 16], fd);
}

void	ft_putnbr_fd_sx(unsigned int n, int fd)
{
	char	*base;

	base = "0123456789abcdef";
	if (n > 15)
		ft_putnbr_fd_sx(n / 16, fd);
	ft_putchar_fd(base[n % 16], fd);
}

void	ft_putnbr_fd_lx(unsigned int n, int fd)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (n > 15)
		ft_putnbr_fd_lx(n / 16, fd);
	ft_putchar_fd(base[n % 16], fd);
}

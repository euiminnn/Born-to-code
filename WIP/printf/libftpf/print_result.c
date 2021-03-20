/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 20:10:05 by echung            #+#    #+#             */
/*   Updated: 2021/03/20 20:10:34 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_value(t_content *content, char type)
{
	if (type == 'c' || type == '%')
		my_write(1, (char *)(content->value), 1);
	else if (type == 's')
		my_write(1, (char *)(content->value), content->intlen);
	else if (type == 'p')
		ft_putnbr_fd_p(*(unsigned long *)content->value, 1);
	else if (type == 'd' || type == 'i' || type == 'u')
		ft_putnbr_fd_u(*(unsigned int *)content->value, 1);
	else if (type == 'x')
		ft_putnbr_fd_sx(*(unsigned int *)content->value, 1);
	else if (type == 'X')
		ft_putnbr_fd_lx(*(unsigned int *)content->value, 1);
}

void	print_else(t_content *content, char type)
{
	while (content->front_margin)
	{
		ft_putchar_fd(' ', 1);
		content->front_margin--;
	}
	if (content->sign)
		ft_putchar_fd('-', 1);
	if (content->prefix)
		my_write(1, "0x", 2);
	while (content->zero)
	{
		ft_putchar_fd('0', 1);
		content->zero--;
	}
	print_value(content, type);
	while (content->back_margin)
	{
		ft_putchar_fd(' ', 1);
		content->back_margin--;
	}
}

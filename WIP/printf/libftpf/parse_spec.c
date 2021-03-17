/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:35:37 by echung            #+#    #+#             */
/*   Updated: 2021/03/18 02:39:49 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void parse_spec_pc(void)
{
	ft_putchar_fd('%', 1);
}

void parse_spec_c(va_list ap)
{
	int chr;
	chr = va_arg(ap, int);
	ft_putchar_fd(chr, 1);
}

void parse_spec_s(va_list ap)
{
	char *str;
	str = va_arg(ap, char*);
	while (*str)
	{
		my_write(1, str, 1);
		str++;
	}
}
void parse_spec_p(va_list ap, t_flag *flag, t_content *content)
{
	unsigned int digit;
	unsigned int pointer;
	pointer = (unsigned int)va_arg(ap, void *);
	digit = pointer;
	set_content(flag, content, digit);
}

void parse_spec_d(va_list ap, t_flag *flag, t_content *content)
{
	long digit;
	digit = va_arg(ap, int);
	if (digit < 0)
	{
		content->sign = 1;
		digit = digit * -1;
	}
	if (flag->dot == 1 && flag->precision == 0 && digit == 0)
	{
		flag->type = 'e';
		flag->width++;
	}
	content->intlen = intlen(digit, 10);
	set_content(flag, content, digit);
}

void parse_spec_u(va_list ap, t_flag *flag, t_content *content)
{
	unsigned int digit;
	digit = va_arg(ap, unsigned int);
	if (flag->dot == 1 && flag->precision == 0 && digit == 0)
	{
		flag->type = 'e';
		flag->width++;
	}
	if (flag->type == 'u')
		content->intlen = intlen(digit, 10);
	else
		content->intlen = intlen(digit, 16);
	set_content(flag, content, digit);
}

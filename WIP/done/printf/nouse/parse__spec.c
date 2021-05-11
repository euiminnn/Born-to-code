/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:35:37 by echung            #+#    #+#             */
/*   Updated: 2021/03/20 19:56:04 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void parse_spec_c(va_list *ap, t_flag *flag, t_content *content)
{
	char arg;
	if (flag->type == '%')
		arg = '%';
	else
		arg = va_arg(*ap, int);
	flag->dot = 0;
	content->intlen = 1;
//	set_content(flag, content, &arg);
}

void parse_spec_s(va_list *ap, t_flag *flag, t_content *content)
{
	char *str;
	char arg;
	str = va_arg(*ap, char*);
	if (str == 0)
		str = "(null)";
	content->intlen = ft_strlen(str);
	if (flag->dot && flag->precision < content->intlen)
		content->intlen = flag->precision;
	if (flag->dot && flag)
	flag->dot = 0;
	&arg = str;
//	set_content(flag, content, &arg);
}
void parse_spec_p(va_list *ap, t_flag *flag, t_content *content)
{
	unsigned long arg;
	arg = (unsigned long)va_arg(*ap, void *);
	content->prefix = 2;
	if (flag->dot == 1 && flag->precision == 0 && arg == 0)
	{
		flag->type = 'e';
		flag->width++;
		content->prefix = 2;
	}
	content->intlen = get_len(arg, 16);
//	set_content(flag, content, &arg);
}

void parse_spec_d(va_list *ap, t_flag *flag, t_content *content)
{
	long arg;
	arg = va_arg(*ap, int);
	if (digit < 0)
	{
		content->sign = 1;
		digit = digit * -1;
	}
	if (flag->dot == 1 && flag->precision == 0 && arg == 0)
	{
		flag->type = 'e';
		flag->width++;
	}
	content->intlen = get_len(arg, 10);
//	set_content(flag, content, &arg);
}

void parse_spec_u(va_list *ap, t_flag *flag, t_content *content)
{
	unsigned int arg;
	arg = va_arg(*ap, unsigned int);
	if (flag->dot == 1 && flag->precision == 0 && arg == 0)
	{
		flag->type = 'e';
		flag->width++;
	}
	if (flag->type == 'u')
		content->intlen = get_len(arg, 10);
	else
		content->intlen = get_len(arg, 16);
//	set_content(flag, content, &arg);
}

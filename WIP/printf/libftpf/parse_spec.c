/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:35:37 by echung            #+#    #+#             */
/*   Updated: 2021/03/27 16:51:03 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_spec_c(va_list *ap, t_flag *flag, t_content *content)
{
	char	chr;

	if (flag->type == '%')
		chr = '%';
	else
		chr = va_arg(*ap, int);
	flag->dot = 0;
	content->value_len = 1;
	content->value = chr;
}

void	parse_spec_s(va_list *ap, t_flag *flag, t_content *content)
{
	char	*str;

	str = va_arg(*ap, char *);
	if (str == 0)
		str = "(null)";
	content->value_len = ft_strlen(str);
	if (flag->dot && flag->precision < content->value_len)
		content->value_len = flag->precision;
	flag->dot = 0;
	content->value = (long)str;
}

void	parse_spec_p(va_list *ap, t_flag *flag, t_content *content)
{
	unsigned long	pointer;

	pointer = (unsigned long)va_arg(*ap, void *);
	content->prefix = 2;
	if (flag->dot == 1 && flag->precision == 0 && pointer == 0)
	{
		flag->type = 'e';
		flag->width++;
	}
	content->value_len = get_len(pointer, 16);
	content->value = pointer;
}

void	parse_spec_d(va_list *ap, t_flag *flag, t_content *content)
{
	long	digit;

	digit = va_arg(*ap, int);
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
	content->value_len = get_len(digit, 10);
	content->value = digit;
}

void	parse_spec_u(va_list *ap, t_flag *flag, t_content *content)
{
	unsigned int	digit;

	digit = va_arg(*ap, unsigned int);
	if (flag->dot == 1 && flag->precision == 0 && digit == 0)
	{
		flag->type = 'e';
		flag->width++;
	}
	if (flag->type == 'u')
		content->value_len = get_len(digit, 10);
	else
		content->value_len = get_len(digit, 16);
	content->value = digit;
}

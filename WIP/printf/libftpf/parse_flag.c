/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:07:10 by echung            #+#    #+#             */
/*   Updated: 2021/03/18 20:24:48 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flag_zero(const char **format, t_flag *flag)
{
	flag->zero = 1;
	(*format)++;
}

void	parse_flag_minus(const char **format, t_flag *flag)
{
	flag->minus = 1;
	(*format)++;
}

void	parse_flag_width(const char **format, t_flag *flag)
{
	flag->width = ft_atoi(*format);
	*format = *format + intlen(flag->width, 10);
}

void	parse_flag_asterisk(const char **format, t_flag *flag, va_list *ap)
{
	int	ast_value;

	ast_value = va_arg(*ap, int);
//	printf("{{{%d}}}", ast_value);
	if (ast_value < 0)
	{
		ast_value = ast_value * -1;
		flag->minus = 1;
	}
	flag->width = ast_value;
	(*format)++;
}

void	parse_flag_precision(const char **format, t_flag *flag, va_list *ap)
{
	int	ast_value;

	flag->dot = 1;
	(*format)++;
	if ('1' <= **format && **format <= '9')
	{
		flag->precision = ft_atoi(*format);
		*format = *format + intlen(flag->precision, 10);
	}
	else if (**format == '*')
	{
		ast_value = va_arg(*ap, int);
		if (ast_value < 0)
			flag->dot = 0;
		flag->precision = ast_value;
		(*format)++;
	}
}

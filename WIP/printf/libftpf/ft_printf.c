/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 19:17:53 by echung            #+#    #+#             */
/*   Updated: 2021/03/24 03:17:35 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_content(t_flag *flag, t_content *content)
{
	if (flag->dot)
		content->zero = max(flag->precision - content->value_len, 0);
	else if (flag->zero && !(flag->minus))
		content->zero = max(flag->width - content->value_len
				- content->sign, 0);
	if (flag->minus)
		content->back_margin = max(flag->width - content->zero
				- content->value_len - content->sign - content->prefix, 0);
	else
		content->front_margin = max(flag->width - content->zero
				- content->value_len - content->sign - content->prefix, 0);
	print_content_frame(content, flag->type);
}

static void	parse_specifier(va_list *ap, t_flag flag)
{
	t_content	content;

	ft_memset(&content, 0, sizeof(content));
	if (flag.type == '%')
		parse_spec_c(ap, &flag, &content);
	else if (flag.type == 'c')
		parse_spec_c(ap, &flag, &content);
	else if (flag.type == 's')
		parse_spec_s(ap, &flag, &content);
	else if (flag.type == 'p')
		parse_spec_p(ap, &flag, &content);
	else if (flag.type == 'd' || flag.type == 'i')
		parse_spec_d(ap, &flag, &content);
	else if (flag.type == 'u' || flag.type == 'x' || flag.type == 'X')
		parse_spec_u(ap, &flag, &content);
	set_content(&flag, &content);
}

static void	parse(const char **format, va_list *ap)
{
	t_flag	flag;

	ft_memset(&flag, 0, sizeof(flag));
	(*format)++;
	while (**format)
	{
		if (**format == '0')
			parse_flag_zero(format, &flag);
		else if (**format == '-')
			parse_flag_minus(format, &flag);
		else if ('1' <= **format && **format <= '9')
			parse_flag_width(format, &flag);
		else if (**format == '*')
			parse_flag_asterisk(format, &flag, ap);
		else if (**format == '.')
			parse_flag_precision(format, &flag, ap);
		else
			break ;
	}
	if (ft_strchr("%cspdiuxX", **format) && (flag.type = **format))
	{
		parse_specifier(ap, flag);
		(*format)++;
	}
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	g_ret = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			parse(&format, &ap);
		else
		{
			my_write(1, format, 1);
			format++;
		}
	}
	va_end(ap);
	return (g_ret);
}
/*
#include <stdio.h>
int		main(void)
{
	char			c;
	char			*s;
	char			*p;
	int				d;
	int				i;
	unsigned int	u;
	unsigned int	x;
	unsigned int	X;
	int				ret;
	int				myret;

	c = 'a';
	s = "this is string";
	d = 123;
	i = -20;
	u = 4294967296;
	x = 0xfF1;
	X = 0xfF1;

	ret = printf("org 7.5d: %7.5d\n", 3, 1);
	printf("\n{ret: %d}\n", ret);
	myret = ft_printf("_my 7.5d: %7.5d\n", 3, 1);
	printf("\n{myret: %d}\n", myret);
	printf("\n");
	ret = printf("org 5.*d: %5.*d\n", 3, 1);
	printf("{ret: %d}\n", ret);
	myret = ft_printf("_my 5.*d: %5.*d\n", 3, 1);
	printf("{myret: %d}\n", myret);
	printf("\n");
	ret = printf("org 55s: %55s\n", s);
	printf("{ret: %d}\n", ret);
	myret = ft_printf("_my 55s: %55s\n", s);
	printf("{myret: %d}\n", myret);
	printf("\n");
	ret = printf("org p: %p\n", s);
	printf("{ret: %d}\n", ret);
	myret = ft_printf("_my p: %p\n", s);
	printf("{myret: %d}\n", myret);
	printf("\n");
	ret = printf("org .5p: %.5p\n", s);
	printf("{ret: %d}\n", ret);
	myret = ft_printf("_my .5p: %.5p\n", s);
	printf("{myret: %d}\n", myret);
	printf("\n");
	ret = printf("org p: %p %p %p %p\n", &c, s, &d, &i);
	printf("{ret: %d}\n", ret);
	myret = ft_printf("_my p: %p %p %p %p\n", &c, s, &d, &i);
	printf("{myret: %d}\n", myret);
	printf("\n");
	ret = printf("org *.*d: %*.*d\n", 7, 5, 12345);
	printf("{ret: %d}\n", ret);
	myret = ft_printf("_my *.*d: %*.*d\n", 7, 5, 12345);
	printf("{myret: %d}\n", myret);
	printf("\n");
	ret = printf("org i: %i\n", i);
	printf("{ret: %d}\n", ret);
	myret = ft_printf("_my i: %i\n", i);
	printf("{myret: %d}\n", myret);
	printf("\n");
	ret = printf("org u: %u\n", u);
	printf("{ret: %d}\n", ret);
	myret = ft_printf("_my u: %u\n", u);
	printf("{myret: %d}\n", myret);
	printf("\n");
	ret = printf("org x: %x\n", x);
	printf("{ret: %d}\n", ret);
	myret = ft_printf("_my x: %x\n", x);
	printf("{myret: %d}\n", myret);
	printf("\n");
	ret = printf("org X: %X\n", X);
	printf("{ret: %d}\n", ret);
	myret = ft_printf("_my X: %X\n", X);
	printf("{myret: %d}\n", myret);
	printf("\n");
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 19:17:53 by echung            #+#    #+#             */
/*   Updated: 2021/03/17 20:36:42 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//int retlen;

int	intlen(unsigned int num, int base)
{
	int len;
	len = 1;
	while ((num /= base) > 0)
		len++;
	return (len);
}

void my_write(int fildes, const void *buf, size_t nbyte)
{
	while (nbyte > 0)
	{
		write(fildes, buf, 1);
		retlen++;
		buf++;
		nbyte--;
	}
}

void print_result(t_content content, char type)
{
	while (content.front_margin)
	{
		ft_putchar_fd(' ', 1);
		content.front_margin--;
	}
	if (content.sign)
		ft_putchar_fd('-', 1);
	while (content.zero)
	{
		ft_putchar_fd('0', 1);
		content.zero--;
	}
	if (type == 'p')
		ft_putnbr_fd_p(content.value, 1);
	else if (type == 'd' || type == 'i' || type == 'u')
		ft_putnbr_fd_u(content.value, 1);
	else if (type == 'x')
		ft_putnbr_fd_sx(content.value, 1);
	else if (type == 'X')
		ft_putnbr_fd_lx(content.value, 1);
	while (content.back_margin)
	{
		ft_putchar_fd(' ', 1);
		content.back_margin--;
	}
}

int max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
void ycha(t_flag *flag, t_content content, unsigned int digit)
{
	if (flag->dot) //zero 계산
		content.zero = max(flag->precision - content.intlen, 0);
	else if (flag->zero && !(flag->minus))
		content.zero = max(flag->width - content.intlen - content.sign, 0);
	if (flag->minus) //margin 계산
		content.back_margin = max(flag->width - content.zero - content.intlen - content.sign, 0);
	else
		content.front_margin = max(flag->width - content.zero - content.intlen - content.sign, 0);
	content.value = (unsigned int)digit;
	print_result(content, flag->type);
}

void parse_specifier(va_list ap, t_flag flag)
{
	t_content	content;
	ft_memset(&content, 0, sizeof(content));

	if (flag.type == '%')
		parse_spec_pc();
	else if (flag.type == 'c')
		parse_spec_c(ap);
	else if (flag.type == 's')
		parse_spec_s(ap);
	else if (flag.type == 'p')
		parse_spec_p(ap, &flag, &content);
	else if (flag.type == 'd' || flag.type == 'i')
	{
		parse_spec_d(ap, &flag, &content);
	}
	else if (flag.type == 'u' || flag.type == 'x' || flag.type == 'X')
	{
		parse_spec_u(ap, &flag, &content);
	}
	else
		printf("specifier: others\n");
}
void parse(const char **format, va_list ap)
{
	t_flag	flag;
	char charset[10];

	ft_memset(&flag, 0, sizeof(flag));
	ft_memcpy(charset, "%cspdiuxX", 10);
	(*format)++; // %뒤부터 읽어야 함
	while (!ft_strchr(charset, **format))
	{
		if (**format == '\0')
			break ;
		else if (**format == '0')
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
			(*format)++;
	}
	if (ft_strchr(charset, **format))
	{
		flag.type = **format;
		parse_specifier(ap, flag);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	retlen = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			parse(&format, ap);
		else
			my_write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (retlen);
}

int main(void)
{
	char c;
	char *s;
	char *p;
	int d;
	int i;
	unsigned int u;
	unsigned int x;
	unsigned int X;

	int ret;
	int myret;

	c = 'a';
	s = "this is string";
	d = 123;
	i = -20;
	u = 4294967296;
	x = 0xfF1;
	X = 0xfF1;

/*
	ret = printf("org percent: %%\n");
	printf("{ret: %d}\n", ret);
	myret = ft_printf("_my percent: %%\n");
	printf("{myret: %d}\n", myret);
	printf("\n");
	
	ret = printf("org c: %c\n", c);
	printf("{ret: %d}\n", ret);
	myret = ft_printf("_my c: %c\n", c);
	printf("{myret: %d}\n", myret);
	printf("\n");
	
	ret = printf("org s: %s\n", s);
	printf("{ret: %d}\n", ret);
	myret = ft_printf("_my s: %s\n", s);
	printf("{myret: %d}\n", myret);
	printf("\n");
	
	ret = printf("org p: %p\n", p);
	printf("{ret: %d}\n", ret);
	myret = ft_printf("_my p: %p\n", p);
	printf("{myret: %d}\n", myret);
	printf("\n");
*/	

	ret = printf("org 5.0d: %5.0d\n", 0);
	printf("{ret: %d}\n", ret);
	myret = ft_printf("_my 5.0d: %5.0d\n", 0);
	printf("{myret: %d}\n", myret);
	printf("\n");

	ret = printf("org .*d: %.*3d\n", 2, 1);
	printf("{ret: %d}\n", ret);
	myret = ft_printf("_my .*d: %.*3d\n", 2, 1);
	printf("{myret: %d}\n", myret);
	printf("\n");

	ret = printf("org *.*d: %*.*d\n", 7, 5, 12345);
	printf("{ret: %d}\n", ret);
	myret = ft_printf("_my *.*d: %*.*d\n", 7, 5, 12345);
	printf("{myret: %d}\n", myret);
	printf("\n");

/*
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
*/

	return (0);
}

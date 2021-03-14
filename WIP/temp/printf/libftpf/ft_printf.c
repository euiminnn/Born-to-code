/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 19:17:53 by echung            #+#    #+#             */
/*   Updated: 2021/03/06 22:13:12 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <strings.h>
#include <stdarg.h>
#include "libft.h"

typedef struct	s_flag
{
	int zero;
	int minus;
	int dot;
	int width;
	int precision;
} 				t_flag;

void parse_specifier(char c, va_list ap)
{
	if (c == 'c')
	{
		int chr;
		chr = va_arg(ap, int); //char 말고 int로 처리
		write(1, &chr, 1); 
	}
	else
		printf("specifier: others\n");
}

int	intlen(int num)
{
	int len;
	len = 0;
	while (num)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

void parse(const char **format, va_list ap)
{
	t_flag	flag;
	char charset[10];

	ft_bzero(&flag, sizeof(flag));
	ft_memcpy(charset, "%cspdiuxX", 10);
	(*format)++;
	while (!ft_strchr(charset, **format))
	{
		if (**format == '\0')
			break ;
		else if (**format == '0')
		{
			flag.zero = 1;
			(*format)++;
			continue ;
		}
		else if (**format == '-')
		{
			flag.minus = 1;
			(*format)++;
			continue ;
		}
		else if (**format == '.')
		{
			flag.dot = 1;
			(*format)++;
			if ('1' <= **format && **format <= '9')
			{
				flag.precision = ft_atoi(*format);
				*format = *format + intlen(flag.precision);
				continue ;
			}
		}
		else if ('1' <= **format && **format <= '9')
		{
			flag.width = ft_atoi(*format);
			*format = *format + intlen(flag.width);
			continue ;
		}
		else
			(*format)++;
	}
	//printf("zero: %d\n", flag.zero);
	//printf("minus: %d\n", flag.minus);
	//printf("dot: %d\n", flag.dot);
	//printf("width: %d\n", flag.width);
	//printf("precision: %d\n", flag.precision);
	if (ft_strchr(charset, **format))
		parse_specifier(**format, ap);
}

int	ft_printf(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			parse(&format, ap);
		}
		else
			write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (0);
}

int main(void)
{
	ft_printf("Hello %corld!\n", 'W');
	return (0);
}

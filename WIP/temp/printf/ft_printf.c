/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 19:17:53 by echung            #+#    #+#             */
/*   Updated: 2021/03/05 22:16:46 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <strings.h>

typedef struct	s_flag
{
	int zero;
	int minus;
	int dot;
	int width;
	int precision;
} 				t_flag;

void parse_specifier(char c)
{
	if (c == 'c')
		printf("specifier: c\n");
	else
		printf("specifier: others\n");
}

void parse(const char **format)
{
	t_flag	flag;
	bzero(&flag, sizeof(flag));
	char *charset;

	memcpy(charset, "%cspdiuxX");
	while (!ft_shrchr(charset, **format))
	{
		if (**format == '\0')
			break ;
		if (**format == '0')
		{
			flag.zero = 1;
			(*format)++;
			continue ;
		}
		if (**format == '-')
			flag.minus = 1;
		if (**format == '.')
		{
			flag.dot = 1;
			if ('1' <= **format && **format <= '9')
			{
				flag.width = atoi(*format);
				*format = *format + intlen(flag.width);
				continue ;
			}
		}
		if ('1' <= **format && **format <= '9')
		{
			flag.width = atoi(*format);
			continue ;
		}
	}
	printf("zero: %d\n", flag.zero);
	printf("minus: %d\n", flag.minus);
	printf("dot: %d\n", flag.dot);
	if (**format == 'c' || **format == 's' || **format == 'p'
		|| **format == 'd' || **format == 'i' || **format == 'u'
		|| **format == 'x' || **format == 'X' || **format == '%')
		parse_specifier(**format);
}

int	ft_printf(const char *format, ...)
{
	while (*format != '\0')
	{
		if (*format == '%')
			parse(&format);
		else
			write(1, format, 1);
		format++;
	}
	return (0);
}

int main(void)
{
	ft_printf("Hello World!\n%d");
	return (0);
}

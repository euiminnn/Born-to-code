/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 02:06:34 by echung            #+#    #+#             */
/*   Updated: 2021/03/14 02:06:36 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

	ret = printf("org 7.5d: %7.5d\n", 123);
	printf("{ret: %d}\n", ret);
	myret = ft_printf("_my 7.5d: %7.5d\n", 123);
	printf("{myret: %d}\n", myret);
	printf("\n");

	ret = printf("org 05d: %05d\n", -123);
	printf("{ret: %d}\n", ret);
	myret = ft_printf("_my 05d: %05d\n", -123);
	printf("{myret: %d}\n", myret);
	printf("\n");

	ret = printf("org -05.3d: %-05.3d\n", -123);
	printf("{ret: %d}\n", ret);
	myret = ft_printf("_my -05.3d: %-05.3d\n", -123);
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

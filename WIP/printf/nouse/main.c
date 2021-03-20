/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 20:21:19 by echung            #+#    #+#             */
/*   Updated: 2021/03/20 20:21:56 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	ret = printf("org percent: %");
	printf("\n{ret: %d}\n", ret);
	myret = ft_printf("_my percent: %");
	printf("\n{myret: %d}\n", myret);
	printf("\n");
	ret = printf("org c: %c\n", c);
	printf("{ret: %d}\n", ret);
	myret = ft_printf("_my c: %c\n", c);
	printf("{myret: %d}\n", myret);
	printf("\n");
	ret = printf("org .05s: %.05s\n", s);
	printf("{ret: %d}\n", ret);
	myret = ft_printf("_my .05s: %.05s\n", s);
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

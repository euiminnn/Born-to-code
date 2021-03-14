/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:29:00 by echung            #+#    #+#             */
/*   Updated: 2021/01/25 19:48:01 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
int		ft_intlen(int n)
{
	int	len;
	int	n_temp;

	len = 0;
	n_temp = n;
	if (n == -2147483648)
		return (10);
	if (n_temp < 0)
		n_temp = -1 * n_temp;
	while (n_temp > 0)
	{
		n_temp = n_temp / 10;
		len++;
	}
	return (len);
}

int		ft_power(int n)
{
	int	result;

	result = 1;
	while (n > 0)
	{
		result = result * 10;
		n--;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char	*ascii;
	char	*ascii_org;
	int		len;
	int		n_org;

	n_org = n;
	len = ft_intlen(n);
//		printf("len : %d\n", len);
	if (len == 0)
		return (0);
//	if (n == -2147483648)
//	{
//		ascii = malloc(sizeof(char) * 11);
///		ascii = ascii_org;
//		if (!(ascii))
		
//	}
	if (n_org < 0)
	{
		len = len + 1;
	}
//	printf("len :k%d\n", len);
	ascii = malloc(sizeof(char) * (len + 1));
	ascii_org = ascii;
	if (!(ascii))
		return (0);
	if (n == -2147483648) {
		ft_memcpy(ascii, "-2147483648", 12);
		return (ascii);
	}
	ascii[len] = '\0';
	if (n_org < 0)
	{
		ascii[0] = '-';
		ascii++;
		n = -1 * n;
		len = len - 1;
	}
	while (len > 0)
	{
		*ascii = n / ft_power(len - 1) + '0';
		//		printf("n : %d\n", n);
		n = n - ((*ascii - '0') * ft_power(len - 1));
		len--;
		ascii++;
	}
	return (ascii_org);
}

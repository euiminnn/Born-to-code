/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 20:02:57 by echung            #+#    #+#             */
/*   Updated: 2021/03/20 20:07:14 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	num;

	num = 0;
	while (*str != '\0')
	{
		num++;
		str++;
	}
	return (num);
}

char	*ft_strchr(const char *s, int c)
{
	char	real_c;

	real_c = c;
	while (*s != '\0')
	{
		if (real_c == *s)
			return ((char *)s);
		s++;
	}
	if (real_c == '\0')
		return ((char *)s);
	else
		return (0);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b_org;
	unsigned char	*b_mod;
	unsigned char	c_mod;

	b_org = b;
	b_mod = b;
	c_mod = c;
	while (len > 0)
	{
		*b_mod = c_mod;
		b_mod++;
		len--;
	}
	return (b_org);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_org;
	unsigned char	*dst_mod;
	unsigned char	*src_mod;

	dst_org = dst;
	dst_mod = dst;
	src_mod = (unsigned char *)src;
	if (dst == 0 && src == 0)
		return (0);
	while (n > 0)
	{
		*dst_mod = *src_mod;
		dst_mod++;
		src_mod++;
		n--;
	}
	return (dst_org);
}

int		ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
		if (*str == '-' || *str == '+')
			return (0);
	}
	result = 0;
	while ('0' <= *str && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}

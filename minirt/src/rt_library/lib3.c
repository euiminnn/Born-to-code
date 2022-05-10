/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 01:21:35 by ycha              #+#    #+#             */
/*   Updated: 2022/03/07 01:21:36 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_atoi(char *line)
{
	int	num;
	int	sign;

	sign = 1;
	num = 0;
	if (*line == '-')
	{
		sign = -1;
		++(line);
	}
	while (ft_isdigit(*line))
	{
		num = num * 10 + (*line - '0');
		++(line);
	}
	return (num * sign);
}

int	ft_atod(double *f, char *line)
{
	double	num;
	int		sign;
	char	*pos;

	if (!ft_isnum(line))
		return (ERROR);
	sign = 1;
	pos = 0;
	num = 0;
	if (*line == '-')
	{
		sign = -1;
		++(line);
	}
	while (ft_isdigit(*line) || *line == '.')
	{
		if (*line == '.')
			pos = line++ + 1;
		else
			num = num * 10 + (*line++ - '0');
	}
	*f = num * sign;
	if (pos)
		*f = num * sign / pow(10, line - pos);
	return (OK);
}

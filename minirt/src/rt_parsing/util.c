/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:34:57 by echung            #+#    #+#             */
/*   Updated: 2022/04/25 19:48:01 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_split(t_vec *input, char *line)
{
	char	**tmp;

	tmp = ft_split(line, ",");
	if (ft_arrsize(tmp) != 3
		|| !ft_atod(&input->x, tmp[0])
		|| !ft_atod(&input->y, tmp[1])
		|| !ft_atod(&input->z, tmp[2]))
		return (ERROR);
	ft_free_split(tmp, ft_arrsize(tmp));
	return (OK);
}

int	free_line(char **line, char **words)
{
	ft_free_split(words, ft_arrsize(words));
	ft_free_split(line, ft_arrsize(line));
	return (ERROR);
}

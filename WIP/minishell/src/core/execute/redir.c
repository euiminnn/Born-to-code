/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:34:41 by echung            #+#    #+#             */
/*   Updated: 2021/11/17 22:34:42 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/execute/redir.h"
#include "lib/libft.h"

int	left_redir(char *file)
{
	return (open(file, O_RDONLY));
}

int	left_double_redir(char *fd)
{
	return (ft_atoi(fd));
}

int	right_redir(char *file)
{
	return (open(file, O_WRONLY | O_TRUNC | O_CREAT, 0644));
}

int	right_double_redir(char *file)
{
	return (open(file, O_WRONLY | O_APPEND | O_CREAT, 0644));
}

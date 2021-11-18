/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 23:36:40 by echung            #+#    #+#             */
/*   Updated: 2021/11/18 23:36:41 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"

void	ft_close(int fd)
{
	if (fd == STDIN_FILENO)
		return ;
	if (fd == STDOUT_FILENO)
		return ;
	if (fd == STDERR_FILENO)
		return ;
	close(fd);
}

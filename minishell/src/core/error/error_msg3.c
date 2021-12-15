/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:32:03 by echung            #+#    #+#             */
/*   Updated: 2021/11/26 20:34:53 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/error.h"
#include "lib/libft.h"
#include "core/builtin.h"

void	error_message_for_cd_not_exist(char *argv)
{
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(argv, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
}

void	error_message_for_cd_is_file(char *argv)
{
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(argv, 2);
	ft_putstr_fd(": Not a directory\n", 2);
}

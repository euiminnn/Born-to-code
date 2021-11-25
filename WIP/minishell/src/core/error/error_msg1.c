/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:30:30 by echung            #+#    #+#             */
/*   Updated: 2021/11/25 21:03:12 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/error.h"
#include "lib/libft.h"

void	ft_error_msg_syntax(void)
{
	ft_putstr_fd("minishell: syntax error\n", 2);
}

void	ft_error_msg_no_file(char *file)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
}

void	ft_error_msg_command_not_found(char *command)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(command, 2);
	ft_putstr_fd(": command not found\n", 2);
}

void	ft_error_msg_command_is_directory(char *command)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(command, 2);
	ft_putstr_fd(": is a directory\n", 2);
}

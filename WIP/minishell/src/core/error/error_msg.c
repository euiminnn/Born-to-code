/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:30:30 by echung            #+#    #+#             */
/*   Updated: 2021/11/17 22:31:47 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/error.h"
#include "lib/libft.h"

void	ft_error_msg_multi_line(void)
{
	ft_putstr_fd("minishell: multi line not allowed\n", 2);
}

void	ft_error_msg_syntax(void)
{
	ft_putstr_fd("minishell: syntax error\n", 2);
}

void	ft_error_msg_no_file(char *file)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd("No such file or directory\n", 2);
}

void	ft_error_msg_not_command(char *command)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(command, 2);
	ft_putstr_fd(": command not found\n", 2);
}

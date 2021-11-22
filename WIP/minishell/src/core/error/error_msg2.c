/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:32:03 by echung            #+#    #+#             */
/*   Updated: 2021/11/22 21:36:13 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libft.h"
#include "core/builtin.h"

void	error_message_for_env(char *key)
{
	ft_putstr_fd("env: ", 2);
	ft_putstr_fd(key, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
}

void	error_message_for_unset(char *key, char *value)
{
	ft_putstr_fd("minishell: unset: `", 2);
	ft_putstr_fd(key, 2);
	ft_putstr_fd("=", 2);
	ft_putstr_fd(value, 2);
	ft_putstr_fd("\': not a valid identifier\n", 2);
}

void	error_message_for_export(char *argv)
{
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(argv, 2);
	ft_putstr_fd("\': not a valid identifier\n", 2);
}

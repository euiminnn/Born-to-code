/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:30:16 by echung            #+#    #+#             */
/*   Updated: 2021/11/25 21:12:07 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/error.h"

int	ft_error(int type, char *data)
{
	g_exit_code = type;
	if (type == ERR_EXECTUE_COMMAND_NO_FILE)
		g_exit_code -= 1;
	if (type == ERR_PARSE_SYNTAX)
		ft_error_msg_syntax();
	if (type == ERR_EXECUTE_REDIR_NO_FILE \
		|| type == ERR_EXECTUE_COMMAND_NO_FILE)
		ft_error_msg_no_file(data);
	if (type == ERR_EXECTUE_COMMAND_NOT_FOUND)
		ft_error_msg_command_not_found(data);
	if (type == ERR_EXECTUE_COMMAND_IS_DIRECTORY)
		ft_error_msg_command_is_directory(data);
	return (ERROR);
}

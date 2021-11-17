/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:30:16 by echung            #+#    #+#             */
/*   Updated: 2021/11/17 22:31:08 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/error.h"

int	ft_error(int type, char *data)
{
	g_exit_code = type;
	if (type == ERR_PARSE_SYNTAX)
		ft_error_msg_syntax();
	if (type == ERR_PARSE_MULTI_LINE)
		ft_error_msg_multi_line();
	if (type == ERR_EXECUTE_NO_FILE)
		ft_error_msg_no_file(data);
	if (type == ERR_EXECTUE_NOT_COMMAND)
		ft_error_msg_not_command(data);
	return (ERROR);
}

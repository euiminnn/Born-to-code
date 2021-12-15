/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:34:35 by echung            #+#    #+#             */
/*   Updated: 2021/11/17 22:34:36 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/execute/proc.h"
#include "utils/utils.h"
#include <unistd.h>

#define STRING_MAX 420000

int	get_proc_type(t_proc *proc)
{
	char	*builtin_name[10];
	int		i;

	if (proc->argc == 0)
		return (P_EXTERN);
	builtin_name[P_BUILTIN_CD] = "cd";
	builtin_name[P_BUILTIN_ECHO] = "echo";
	builtin_name[P_BUILTIN_ENV] = "env";
	builtin_name[P_BUILTIN_EXIT] = "exit";
	builtin_name[P_BUILTIN_EXPORT] = "export";
	builtin_name[P_BUILTIN_PWD] = "pwd";
	builtin_name[P_BUILTIN_UNSET] = "unset";
	i = 0;
	while (++i < BUILTIN_NUM + 1)
		if (ft_strncmp(proc->argv[0], builtin_name[i], STRING_MAX) == 0)
			return (i);
	return (P_EXTERN);
}

void	free_proc(t_proc *proc)
{
	ft_free_strings(proc->argv);
	ft_close(proc->fd_in);
	ft_close(proc->fd_out);
	free(proc);
}

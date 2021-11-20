/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 22:21:21 by ycha              #+#    #+#             */
/*   Updated: 2021/11/20 22:21:22 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug/debug_execute.h"
#include "debug/debug_utils.h"

int	print_proc(t_proc *proc, int depth)
{
	print_space(depth);
	printf("{\n");
	print_space(depth + 1);
	printf("argv : \n");
	print_strings(proc->argv, depth + 2);
	print_space(depth + 1);
	printf("argc : %d\n", proc->argc);
	print_space(depth + 1);
	printf("env : %p\n", proc->env);
	print_space(depth + 1);
	printf("fd_in : %d\n", proc->fd_in);
	print_space(depth + 1);
	printf("fd_out : %d\n", proc->fd_out);
	print_space(depth);
	printf("}\n");
	return (OK);
}

int	print_proc_type(int type)
{
	if (type == P_BUILTIN_CD)
		printf("P_BUILTIN_CD\n");
	if (type == P_BUILTIN_ECHO)
		printf("P_BUILTIN_ECHO\n");
	if (type == P_BUILTIN_ENV)
		printf("P_BUILTIN_ENV\n");
	if (type == P_BUILTIN_EXIT)
		printf("P_BUILTIN_EXIT\n");
	if (type == P_BUILTIN_EXPORT)
		printf("P_BUILTIN_EXPORT\n");
	if (type == P_BUILTIN_PWD)
		printf("P_BUILTIN_PWD\n");
	if (type == P_BUILTIN_UNSET)
		printf("P_BUILTIN_UNSET\n");
}

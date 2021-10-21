/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_execute.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:18:09 by echung            #+#    #+#             */
/*   Updated: 2021/10/21 17:18:13 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_EXECUTE_H
# define DEBUG_EXECUTE_H

# include "core/execute/proc.h"

/**
 * 프로세스 출력
 * 
 * @param proc 프로세스
 * @param depth 출력 깊이
 */
int	print_proc(t_proc *proc, int depth);

/**
 * 프로세스 종류 이름을 출력합니다.
 *
 * @param type 프로세스 종류
 */
int	print_proc_type(int type);

#endif

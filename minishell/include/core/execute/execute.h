/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:08:05 by echung            #+#    #+#             */
/*   Updated: 2021/10/21 17:11:17 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# define IN 0
# define OUT 1

# include <sys/wait.h>
# include <termios.h>

# include "core/env/env.h"
# include "core/execute/proc.h"
# include "core/parse/cmd.h"
# include "utils/list.h"

/**
 * 커맨드들을 실행합니다.
 *
 * @param cmds 커맨드 연결 리스트
 * @param env 환경 변수 구조체
 */
void	execute(t_list *cmds, t_env *env);

/**
 * 파이프에 연결된 fd 를 찾아 커맨드들을 실행 및 연결합니다.
 *
 * @param cmds 커맨드 연결 리스트
 * @param env 환경 변수 구조체
 * @param fd_in 기본 입력 fd (stdin 으로 시작)
 * @param last_pid 이전 프로세스 id (-1 로 시작)
 */
int		execute_cmds(t_list *node, t_env *env, int fd_in, int last_pid);

/**
 * fd 에 따라서 커맨드를 실행시킵니다.
 *
 * @param cmd 커맨드 구조체
 * @param env 환경변수 구조체
 * @param fd_in 기본 입력 fd
 * @param fd_out 기본 출력 fd
 */
int		execute_cmd(t_cmd *cmd, t_env *env, int fd_in, int fd_out);

/**
 * 빌트인 프로세스를 실행시킵니다.
 *
 * @param proc 프로세스 구조체
 *
 * @throw 프로세스 종료 코드를 errno 에 담습니다.
 */
void	execute_builtin_proc(t_proc *proc);

/**
 * 외부 프로세스를 실행시킵니다.
 *
 * @param proc 프로세스 구조체
 *
 * @throw 프로세스 종료 코드를 errno 에 담습니다.
 */
void	execute_extern_proc(t_proc *proc);

#endif

#ifndef EXECUTE_H
# define EXECUTE_H

# define IN 0
# define OUT 1

#include <sys/wait.h>

#include "core/env.h"
#include "core/execute/proc.h"
#include "core/parse/cmd.h"
#include "utils/list.h"

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
 * @param fd_in 기본 입력 fd
 */
void	execute_cmds(t_list *cmds, t_env *env, int fd_in);

/**
 * fd 에 따라서 커맨드를 실행시킵니다.
 *
 * @param cmd 커맨드 구조체
 * @param env 환경변수 구조체
 * @param fd_in 기본 입력 fd
 * @param fd_out 기본 출력 fd
 */
void	execute_cmd(t_cmd *cmd, t_env *env, int fd_in, int fd_out);

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
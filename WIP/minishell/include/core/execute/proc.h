#ifndef PROC_H
# define PROC_H

# include "core/env.h"
# include "core/parse/cmd.h"
# include "utils/list.h"
# include "utils/utils.h"
# include "define.h"

# define BUILTIN_NUM 7

# define P_EXTERN 0
# define P_BUILTIN_CD 1
# define P_BUILTIN_ECHO 2
# define P_BUILTIN_ENV 3
# define P_BUILTIN_EXIT 4
# define P_BUILTIN_EXPORT 5
# define P_BUILTIN_PWD 6
# define P_BUILTIN_UNSET 7

/**
 * @brief 한 프로세스에 대한 구조체
 *
 * @p argv 인자 문자열 배열 (free 필요)
 * @p argc 인자 갯수
 * @p env 환경변수 구조체
 * @p fd_in 입력 fd (close 필요)
 * @p fd_out 출력 fd (close 필요)
 *
 * @example {
 *   argv : ['hello', ]
 *   argc : 1
 *   env : pointer
 *   fd_in : 0
 *   fd_out : 1
 */
typedef struct s_proc
{
    char    **argv;
    int     argc;
    t_env   *env;
    int     fd_in;
    int     fd_out;
}   t_proc;

/**
 * 커맨드 구조체로 프로세스 구조체를 만듭니다.
 *
 * @param cmd 커맨드 구조체
 * @param envp 환경변수 문자열 배열
 * @param fd_in 입력 fd 초기값
 * @param fd_out 출력 fd 초기값
 * @return 성공시 프로세스 구조체 (free 필요), 실패시 NULL
 */
t_proc  *build_proc(t_cmd *cmd, t_env *env, int fd_in, int fd_out);

/**
 * 프로세스 종류를 파악합니다.
 *
 * @param proc 프로세스 구조체
 * @return 빌트인 프로세스라면 P_BUILTIN_* 을, 외부 프로세스라면 P_EXTERN
 */
int get_proc_type(t_proc *proc);

/**
 * 프로세스 구조체 메모리를 해제합니다.
 *
 * @param proc 프로세스 구조체
 */
void    free_proc(t_proc *proc);

#endif

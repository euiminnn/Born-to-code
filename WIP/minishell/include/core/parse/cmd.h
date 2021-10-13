#ifndef CMD_H
# define CMD_H

# include "utils/list.h"

/**
 * @brief 한 명령어 대한 구조체
 *
 * @p args 명령어 + 인자 token 배열
 * @p rd_in 리다이렉션이 저장되는 token 배열
 *
 * @example {
 *   args : [{type: T_ARG, value: 'echo'}, {type: T_ARG, value: 'hello'}]
 *   rd : [{type: T_RIGHT_REDIR, value: 'abc'}]
 * }
 */
typedef struct s_cmd
{
    t_list  *args;
    t_list  *rd;
}   t_cmd;

/**
 * 커맨드 구조체를 초기화합니다.
 *
 * @return 초기화된 커맨드 구조체 (free 필요)
 */
t_cmd    *init_cmd();

/**
 *
 * 커맨드 구조체 메모리를 해제합니다.
 *
 * @param cmd 커맨드 구조체
 */
void    free_cmd(void *cmd);

#endif

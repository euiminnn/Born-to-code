#ifndef EXECUTE_H
# define EXECUTE_H

# define IN 0
# define OUT 1

# include "utils/list.h"
# include "core/env.h"
# include "core/parse/cmd.h"

/**
 * 프로세스를 실행합니다.
 *
 * @param cmds 커맨드 연결 리스트
 * @param env 환경 변수 구조체
 * @return 잘 실행하면 OK, 실패하면 ERR 번호
 */
int execute(t_list *cmds, t_env *env);


int execute_cmd(t_cmd *cmd, t_env *env, int fd_in, int fd_out);

int execute_cmds(t_list *node, t_env *env, int fd_in);

int	wait_cmd();

#endif

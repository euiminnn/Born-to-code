#ifndef PARSE_H
# define PARSE_H

# include "define.h"
# include "lib/libft.h"
# include "utils/list.h"
# include "core/env.h"
# include "core/parse/cmd.h"
# include "core/parse/token.h"
# include "core/execute/execute.h"

# define T_ARG 1
# define T_LEFT_REDIR 2
# define T_RIGHT_REDIR 3
# define T_LEFT_DOUBLE_REDIR 4
# define T_RIGHT_DOUBLE_REDIR 5
# define T_PIPE 6

/**
 * 입력받은 한줄을 파싱하여, 환경변수를 적용하여, 커맨드들을 구합니다.
 *
 * @param line 입력받은 한줄
 * @param end 환경변수 구조체
 * @param cmds 반환할 커맨드들
 * @return 입력받은 한줄에 오류가 없으면 OK, 오류가 있으면 ERROR
 */
int parse(char *line, t_env *env, t_list *cmds);

/**
 * 입력받은 한줄을 토큰 단위로 잘라, 문자열로 쪼갭니다.
 *
 * @param line 입력받은 한줄
 * @param strings 반환 받을 문자열들
 * @return 성공하면 OK, 실패하면 ERR 번호
 */
int tokenizer(char *line, char ***strings);

/**
 * 문자열들을 받아서, 타입을 결정하고, 토큰 리스트에 추가합니다.
 *
 * @param strings split 된 문자열
 * @param tokens 토큰을 추가할 연결 리스트
 * @return 성공하면 OK, 실패하면 ERR
 */
int lexer(char **strings, t_list *tokens);

/**
 * 토큰에서 환경변수를 문자열 치환하고, 따옴표를 뺍니다.
 *
 * @param token 토큰 구조체
 * @param env 환경 변수 구조체
 * @return 환경변수 적용에 오류가 있으면 EROOR 없으면 OK
 */
int replace_env_in_token(t_token *token, t_env *env);

/**
 * 토큰을 분석하여, 커맨드 리스트를 만듭니다.
 *
 * @param token 토큰 리스트
 * @param cmds 반환할 커멘드들
 * @return 성공하면 OK, 실패하면 ERR 번호
 */
int parser(t_list *tokens, t_list *cmds);

#endif

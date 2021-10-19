#ifndef TOKEN_H
# define TOKEN_H

# include "core/env/env.h"

/**
 * t_token 토큰 구초제
 *
 * @p type 종류
 * @p value 값 (free 필요)
 *
 * @example {
 *   type: T_ARG
 *   value: 'echo'
 * }
 */
typedef struct s_token
{
    int     type;
    char    *value;
}   t_token;

/**
 * 토큰을 초기화합니다.
 *
 * @param type 종류
 * @param value 값
 * @return 토큰을 반환 합니다. (free 필요)
 */
t_token *init_token(int type, char *value);

/**
 * 토큰을 복사합니다.
 *
 * @param token 복사할 토큰
 * @return 복사된 토큰을 반환 합니다. (free 필요)
 */
t_token *dup_token(t_token *token);

/**
 * 토큰 메모리를 해제합니다.
 *
 * @param token 토큰
 */
void    free_token(void *token);

/**
 * 토큰을 문자열로 변환합니다.
 *
 * @param token 토큰
 */
char    *to_string_token(void *token); 

#endif

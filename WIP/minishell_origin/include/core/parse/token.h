/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:16:37 by echung            #+#    #+#             */
/*   Updated: 2021/10/21 17:40:27 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "core/env/env.h"

/**
 * t_token 토큰 구초제
 *
 * @p type 종류
 * @p value 값 (free 필요) (close 필요)
 * 
 * @warning type 이 T_LEFT_DOUBLE_REDIR 인경우, value 는 fd 값이 들어감
 * @warning 이때, fd 는 꼭 close 해줘야함
 *
 * @example {
 *   type: T_ARG
 *   value: 'echo'
 * }
 */
typedef struct s_token
{
	int		type;
	char	*value;
}	t_token;

/**
 * 토큰을 초기화합니다.
 *
 * @param type 종류
 * @param value 값
 * @return 토큰을 반환 합니다. (free 필요)
 */
t_token	*init_token(int type, char *value);

/**
 * 토큰을 복사합니다.
 *
 * @param token 복사할 토큰
 * @return 복사된 토큰을 반환 합니다. (free 필요)
 */
t_token	*dup_token(t_token *token);

/**
 * 토큰 메모리를 해제합니다.
 *
 * @param token 토큰
 */
void	free_token(void *token);

/**
 * 토큰 메모리를 해제합니다. 
 * 
 * @details 이때, fd 는 close 하지 않고
 * @details 문자열만 free 합니다!
 *
 * @param token 토큰
 */
void	free_token_without_close(void *token);

/**
 * 토큰을 문자열로 변환합니다.
 *
 * @param token 토큰
 */
char	*to_string_token(void *token);

#endif

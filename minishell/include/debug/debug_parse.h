/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_parse.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:18:50 by echung            #+#    #+#             */
/*   Updated: 2021/10/21 17:18:56 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_PARSE_H
# define DEBUG_PARSE_H

# include "core/parse/cmd.h"
# include "core/parse/token.h"
# include "core/parse/parse.h"

/**
 * 토큰 출력
 * 
 * @param token 토큰
 * @param depth 출력 깊이
 */
int	print_token(t_token *token, int depth);

/**
 * 토큰 연결 리스트 출력
 * 
 * @param tokens 토큰 연결 리스트
 * @param depth 출력 깊이
 */
int	print_token_list(t_list *tokens, int depth);

/**
 * 커맨드 출력
 * 
 * @param cmd 커맨드
 * @param depth 출력 깊이
 */
int	print_cmd(t_cmd *cmd, int depth);

/**
 * 커맨드 연결 리스트 출력
 * 
 * @param cmds 커맨드 연결 리스트
 * @param depth 출력 깊이
 */
int	print_cmd_list(t_list *cmds, int depth);

#endif

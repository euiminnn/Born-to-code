/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:15:40 by echung            #+#    #+#             */
/*   Updated: 2021/10/21 17:15:42 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "define.h"
# include "lib/libft.h"
# include "utils/list.h"
# include "utils/utils.h"
# include "core/env/env.h"
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
 * @param cmds 반환할 커맨드 리스트 (init_list 필요)
 * @return 성공하면 OK, 오류가 있으면 ERROR
 *
 * @p ERR_PARSE_MULTI_LINE
 * @p ERR_PARSE_SYNTAX
 */
int		parse(char *line, t_env *env, t_list *cmds);

/**
 * 입력받은 한줄을 토큰 단위로 잘라, 문자열로 쪼갭니다.
 *
 * @param line 입력받은 한줄
 * @param strings 반환 받을 문자열들
 * @return 성공하면 OK, 실패하면 ERROR
 *
 * @p ERR_PARSE_MULTI_LINE 따움표가 쌍이 맞지 않는 경우
 * @p ERR_PARSE_SYNTAX 허락되지 않은 문자가 있는 경우
 *
 * @example line : echo hello > abc | cat << abc
 * @example strings : ['echo', 'hello', '>', 'abc', '|', 'cat', '<<' ,'abc']
 *
 * @test parse/test_tokenizer
 */
int		tokenizer(char *line, char ***strings);

/**
 * 문자열들의 타입을 결정하고, 토큰 리스트에 추가합니다.
 *
 * @param strings split 된 문자열
 * @param tokens 토큰을 추가할 리스트 (init_list 필요)
 * @return 성공하면 OK, 실패하면 ERROR
 *
 * @p ERR_PARSE_SYNTAX redirection 다음에 문자열이 없는 경우
 *
 * @example strings : ['echo', 'hello', '>', 'abc', '|', 'cat', '<<' ,'abc']
 * @example tokens : [
 *  {type: T_ARG, value: 'echo'},
 *  {type: T_ARG, value: 'hello'},
 *  {type: T_RIGHT_REDIR, value: 'abc'},
 *  {type: T_PIPE, value: null},
 *  {type: T_CMD, value: 'cat'},
 *  {type: T_LEFT_DOUBLE_REDIR, value: 'abc'},
 * ]
 */
int		lexer(char **strings, t_list *tokens);

/**
 * 토큰에서 환경변수를 문자열 치환하고, 따옴표를 뺍니다.
 *
 * @param token 토큰 구조체
 * @param env 환경 변수 구조체
 *
 * @example abc"hello$USER asdf"abc -> abchelloycha asdfabc
 *
 * @test parse/test_replace
 */
void	replace_env_in_token(t_token *token, t_env *env);

/**
 * << 에 대해서 heredoc 을 처리하고, 해당 fd 를 문자열로 저장합니다.
 *
 * @param tokens 토큰 리스트
 *
 * @example {type: T_LEFT_DOUBLD_REDIR, value: "3"},
 */
void	heredoc(t_list *tokens);

/**
 * 토큰을 타입에 따라서, 커맨드 리스트를 만듭니다.
 *
 * @param token 토큰 리스트
 * @param cmds 반환할 커멘드 리스트
 *
 * @example tokens : [
 *  {type: T_ARG, value: 'echo'},
 *  {type: T_ARG, value: 'hello'},
 *  {type: T_RIGHT_REDIR, value: 'abc'},
 *  {type: T_PIPE, value: null},
 *  {type: T_CMD, value: 'cat'},
 *  {type: T_LEFT_REDIR, value: 'abc'},
 * ]
 * @example cmds : [
 *  {
 *    args: [{type: T_ARG, value: 'echo'}, {type: T_ARG, value: 'hello'}]
 *    rd : [{type: T_RIGHT_REDIR, value: 'abc'}]
 *  },
 *  {
 *    args: [{type: T_CMD, value: 'cat'}]
 *    rd: [{type: T_LEFT_REDIR, value: 'abc'}]
 *  }
 * ]
 */
void	parser(t_list *tokens, t_list *cmds);

#endif

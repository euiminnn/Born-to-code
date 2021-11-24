/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:43:34 by echung            #+#    #+#             */
/*   Updated: 2021/11/24 19:24:52 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include "core/env/env.h"
#include "core/parse/parse.h"
#include "debug/debug_parse.h"
#include "debug/debug_utils.h"

static void	replace(t_list *tokens, t_env *env);

/**
 * 파싱 과정
 *
 * 토큰나이저 : 문자열을 토큰으로 자름
 * 렉서 : 토큰의 타입을 정함
 * env 적용 : 환경변수를 적용함
 * heredoc 처리 : << 리다이렉션 입력 받기
 * 파서 : 최종 커맨드 구조체를 만듬
 */

int	parse(char *line, t_env *env, t_list *cmds)
{
	t_list	*tokens;
	char	**strings;

	tokens = init_list();
	tokenizer(line, &strings);
	DEBUG && printf("-------tokenizer-------\n");
	DEBUG && print_strings(strings, 0);
	if (!lexer(strings, tokens))
		return (ERROR);
	DEBUG && printf("---------lexer---------\n");
	DEBUG && print_token_list(tokens, 0);
	replace(tokens, env);
	DEBUG && printf("--------replace--------\n");
	DEBUG && print_token_list(tokens, 0);
	if (!heredoc(tokens))
		return (ERROR);
	DEBUG && printf("--------heredoc--------\n");
	DEBUG && print_token_list(tokens, 0);
	parser(tokens, cmds);
	DEBUG && printf("--------parser---------\n");
	DEBUG && print_cmd_list(cmds, 0);
	ft_free_strings(strings);
	free_list(tokens, free_token_without_close);
	return (OK);
}

static void	replace(t_list *tokens, t_env *env)
{
	t_list	*node;
	t_token	*token;

	node = tokens->next;
	while (node)
	{
		token = node->data;
		node = node->next;
		if (token->type == T_PIPE)
			continue ;
		replace_env_in_token(token, env);
	}
}

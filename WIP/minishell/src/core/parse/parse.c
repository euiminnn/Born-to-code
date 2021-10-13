#include "utils/utils.h"
#include "core/env.h"
#include "core/parse/parse.h"
#include "debug/debug_parse.h"
#include "debug/debug_utils.h"

static int  replace(t_list *tokens, t_env *env);

/**
 * 파싱 과정
 * 
 * 토큰나이저 : 문자열을 토큰으로 자름
 * 렉서 : 토큰의 타입을 정함
 * env 적용 : 환경변수를 적용함
 * 파서 : 최종 커맨드 구조체를 만듬
 * 
 */
int parse(char *line, t_env *env, t_list *cmds)
{
    t_list  *tokens;
    char    **strings;

    tokens = init_list();
    if (!tokenizer(line, &strings))
        return (ERROR);
    DEBUG && printf("-------tokenizer-------\n");
    DEBUG && print_strings(strings, 0);
    lexer(strings, tokens);
    DEBUG && printf("---------lexer---------\n");
    DEBUG && print_token_list(tokens, 0);
    replace(tokens, env);
    DEBUG && printf("--------replace--------\n");
    DEBUG && print_token_list(tokens, 0);
    parser(tokens, cmds);
    DEBUG && printf("--------parser---------\n");
    DEBUG && print_cmd_list(cmds, 0);
    ft_free_strings(strings);
    free_list(tokens, free_token);
    return (OK);
}

/**
 * cmd 객체를 만든다
 * T_ARG 면, args 에 넣고,
 * T_LEFT_REDIR 면, rd_in 에 넣고,
 * T_RIGHT_REDIR 면, rd_out 에 넣는다.
 * T_PIPE 나오면 cmd 객체 새로 만들고 반복..
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
int parser(t_list *tokens, t_list *cmds)
{
    t_list  *node;
    t_cmd   *cmd;
    t_token *token;

    node = tokens->next;
    while (node)
    {
        cmd = init_cmd();
        while (node && ((t_token *)node->data)->type != T_PIPE)
        {
            token = dup_token((t_token *)node->data);
            if (token->type == T_ARG)
                push_list(cmd->args, (void *)token);
            else
                push_list(cmd->rd, (void *)token);
            node = node->next;
        }
        push_list(cmds, (void *)cmd);
        if (node)
            node = node->next;
    }
    return (OK);
}

static int  replace(t_list *tokens, t_env *env)
{
    t_list  *node;
    t_token *token;

    node = tokens->next;
    while (node)
    {
        token = node->data;
        node = node->next;
        if (token->type == T_PIPE)
            continue;
        if (!replace_env_in_token(token, env))
            return (ERROR);
    }
    return (OK);
}

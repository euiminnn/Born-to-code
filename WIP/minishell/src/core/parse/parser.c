#include "core/env.h"
#include "core/parse/parse.h"
#include "utils/utils.h"

/**
 * cmd 객체를 만든다
 * T_ARG 면, args 에 넣고,
 * T_LEFT_REDIR... 면, rd 에 넣고,
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

void parser(t_list *tokens, t_list *cmds) {
    t_list *node;
    t_cmd *cmd;
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
        if (node) node = node->next;
    }
}

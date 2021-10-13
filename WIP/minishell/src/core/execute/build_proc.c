#include "core/execute/proc.h"
#include "core/execute/redir.h"
#include "core/parse/parse.h"
#include "core/parse/token.h"

// TODO: export_env 랑 코드가 중복됨.... 고쳐볼지 생각해볼것....
static char **export_tokens_to_arr(t_list *tokens)
{
    char    **rt;
    int     size;
    int     idx;
    t_list  *node;

    size = count_list(tokens);
    rt = (char **)malloc(sizeof(char *) * size);
    if (!rt)
        ft_exit(12);
    idx = 0;
    node = tokens->next;
    while (node)
    {
        rt[idx] = ft_strdup(((t_token *)node->data)->value);
        node = node->next;
        ++idx;
    }
    rt[idx] = 0;
    return (rt);
}

static int  find_fd_in(t_list *tokens, int default_fd)
{
    int     fd;
    t_token *token;
    t_list  *node;

    fd = default_fd;
    node = tokens->next;
    while (node)
    {
        ft_close(fd);
        token = node->data;
        if (token->type == T_LEFT_REDIR)
            fd = left_redir(token->value);
        else
            fd = left_double_redir(token->value);
        node = node->next;
    }
    return (fd);
}

static int find_fd_out(t_list *tokens, int default_fd)
{
    int     fd;
    t_token *token;
    t_list  *node;

    fd = default_fd;
    node = tokens->next;
    while (node)
    {
        ft_close(fd);
        token = node->data;
        if (token->type == T_RIGHT_REDIR)
            fd = right_redir(token->value);
        else
            fd = right_double_redir(token->value);
        node = node->next;
    }
    return (fd);
}

/**
 * cmd 에서 args 로 argv 를 만든다.
 * 환경변수를 그대로 적용하고,
 * 리다이렉션에 따라서 fd_in 최종값과, fd_out 최종값을 구한다.
 * 
 * @example cmd : {
 *   args: [{type: T_ARG, value: 'echo'}, {type: T_ARG, value: 'hello'}]
 *   rd_in: []
 *   rd_out: [{type: T_RIGHT_REDIR, value: 'abc'}]
 * }
 * @example proc : {
 *   argv : ['hello', ]
 *   argc : 1
 *   env : pointer
 *   fd_in : 0
 *   fd_out : 1
 * }
 */
t_proc  *build_proc(t_cmd *cmd, t_env *env, int fd_in, int fd_out)
{
    t_proc  *proc;

    proc = (t_proc *)malloc(sizeof(t_proc));
    if (!proc)
        ft_exit(12);
    proc->argv = export_tokens_to_arr(cmd->args);
    proc->argc = count_list(cmd->args);
    proc->env = env;
    proc->fd_in = find_fd_in(cmd->rd_in, fd_in);
    proc->fd_out = find_fd_out(cmd->rd_out, fd_out);
    return (proc);
}
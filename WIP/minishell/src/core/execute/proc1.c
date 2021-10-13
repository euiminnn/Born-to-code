#include "core/execute/proc.h"
#include "core/execute/redir.h"
#include "core/parse/parse.h"
#include "core/parse/token.h"

#define FD_IN 0
#define FD_OUT 1

// TODO: export_env 랑 코드가 중복됨.... 고쳐볼지 생각해볼것....
static char **export_tokens_to_arr(t_list *tokens)
{
    char    **rt;
    int     size;
    int     idx;
    t_list  *node;

    size = count_list(tokens);
    rt = (char **)malloc(sizeof(char *) * (size + 1));
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

static int  get_fd_type(int type)
{
    if (type == T_LEFT_REDIR || type == T_LEFT_DOUBLE_REDIR)
        return (FD_IN);
    return (FD_OUT);
}

static int  get_redir_fd(t_list *tokens, int fds[2])
{
    int     fd_type;
    t_token *token;
    t_list  *node;

    node = tokens->next;
    while (node)
    {
        token = node->data;
        fd_type = get_fd_type(token->type);
        ft_close(fds[fd_type]);
        if (token->type == T_LEFT_REDIR)
            fds[fd_type] = left_redir(token->value);
        else if (token->type == T_LEFT_DOUBLE_REDIR)
            fds[fd_type] = left_double_redir(token->value);
        else if (token->type == T_RIGHT_REDIR)
            fds[fd_type] = right_redir(token->value);
        else if (token->type == T_RIGHT_DOUBLE_REDIR)
            fds[fd_type] = right_double_redir(token->value);
        if (fds[fd_type] == -1)
            return (ERROR);
        node = node->next;
    }
    return (OK);
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
    int     fds[2];
    t_proc  *proc;

    proc = (t_proc *)malloc(sizeof(t_proc));
    if (!proc)
        ft_exit(12);
    proc->argv = export_tokens_to_arr(cmd->args);
    proc->argc = count_list(cmd->args);
    proc->env = env;
    fds[FD_IN] = fd_in;
    fds[FD_OUT] = fd_out;
    get_redir_fd(cmd->rd, fds);
    proc->fd_in = fds[FD_IN];
    proc->fd_out = fds[FD_OUT];
    return (proc);
}
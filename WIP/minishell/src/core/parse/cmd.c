#include "core/parse/cmd.h"
#include "core/parse/token.h"

t_cmd    *init_cmd()
{
    t_cmd   *cmd;

    cmd = malloc(sizeof(t_cmd));
    if (!cmd)
        exit(12);
    cmd->args = init_list();
    cmd->rd_in = init_list();
    cmd->rd_out = init_list();
    return (cmd);
}

void    free_cmd(void *data)
{
    t_cmd   *cmd;

    cmd = (t_cmd *)data;
    free_list(cmd->args, free_token);
    free_list(cmd->rd_in, free_token);
    free_list(cmd->rd_out, free_token);
    free(cmd);
}

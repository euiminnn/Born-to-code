#include "debug/debug_parse.h"

static void print_space(int depth)
{
    int c;

    c = depth * 4;
    while (c--)
        printf(" ");
}

void    print_cmd(t_cmd *cmd, int depth)
{
    print_space(depth);
    printf("{\n");
    print_space(depth + 1);
    printf("args : \n");
    print_token_list(cmd->args, depth + 2);
    print_space(depth + 1);
    printf("rd_in : \n");
    print_token_list(cmd->rd_in, depth + 2);
    print_space(depth + 1);
    printf("rd_out : \n");
    print_token_list(cmd->rd_out, depth + 2);
    print_space(depth);
    printf("}\n");
}

void    print_cmd_list(t_list *cmds, int depth)
{
    t_list  *node;

    node = cmds->next;
    print_space(depth);
    printf("[\n");
    while (node)
    {
        print_cmd(node->data, depth + 1);
        node = node->next;
    }
    print_space(depth);
    printf("]\n");
}

void    print_token(t_token *token, int depth)
{
    char *c;

    if (token->type == T_ARG)
        c = "T_ARG";
    else if (token->type == T_LEFT_REDIR)
        c = "T_LEFT_REDIR";
    else if (token->type == T_RIGHT_REDIR)
        c = "T_RIGHT_REDIR";
    else if (token->type == T_LEFT_DOUBLE_REDIR)
        c = "T_LEFT_DOUBLE_REDIR";
    else if (token->type == T_RIGHT_DOUBLE_REDIR)
        c = "T_RIGHT_DOUBLE_REDIR";
    else
        c = "T_PIPE";
    print_space(depth);
    printf("{type: %s, value: %s}\n", c, token->value);
}

void    print_token_list(t_list *tokens, int depth)
{
    t_list  *node;

    node = tokens->next;
    print_space(depth);
    printf("[\n");
    while (node)
    {
        print_token(node->data, depth + 1);
        node = node->next;
    }
    print_space(depth);
    printf("]\n");
}

void	print_pp(char **arr)
{
	int idx;

	idx = -1;
	while (arr[++idx])
	{
		printf("{line[%d] : %s}\n", idx, arr[idx]);
	}
}

#ifndef DEBUG_H
# define DEBUG_H

# include "core/parse/cmd.h"
# include "core/parse/token.h"
# include "core/parse/parse.h"

void    print_token(t_token *token, int depth);
void    print_token_list(t_list *tokens, int depth);

void    print_cmd(t_cmd *cmd, int depth);
void    print_cmd_list(t_list *cmds, int depth);

void	print_pp(char **arr);

#endif

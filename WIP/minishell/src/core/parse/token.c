#include "core/parse/token.h"
#include "core/parse/parse.h"
#include "lib/libft.h"

t_token *init_token(int type, char *value)
{
    t_token *output;

    output = malloc(sizeof(t_token));
    if (!output)
        exit(12);
    output->type = type;
    output->value = value;
    return (output);
}

t_token *dup_token(t_token *token)
{
    return (init_token(token->type, ft_strdup(token->value)));
}

void    free_token(void *v_token)
{
    t_token *token;
    
    token = (t_token *)v_token;
    if (token->type == T_LEFT_DOUBLE_REDIR)
        ft_close(ft_atoi(token->value));
    if (token->value)
        free(token->value);
    free(token);
}

void    free_token_without_close(void *v_token)
{
    t_token *token;
    
    token = (t_token *)v_token;
    if (token->value)
        free(token->value);
    free(token);
}

char    *to_string_token(void *token)
{
    return (ft_strdup(((t_token *)token)->value));
}

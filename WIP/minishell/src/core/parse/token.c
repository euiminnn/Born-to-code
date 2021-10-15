#include "core/parse/token.h"
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

void    free_token(void *data)
{
    t_token *token;

    token = (t_token *)data;
    if (token->value)
        free(token->value);
    free(token);
}
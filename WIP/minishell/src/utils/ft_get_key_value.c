#include "utils/utils.h"

void    ft_get_key_value(char* line, char **key, char **value)
{
    char    *equal;

    equal = line;
    while (*equal && *equal != '=')
        equal++;
    if (*equal)
    {
        *equal = '\0';
        *key = ft_strdup(line);
        *value = ft_strdup(equal + 1);
        *equal = '=';
    }
    else
    {
        *key = ft_strdup(line);
        *value = NULL;
    }
}

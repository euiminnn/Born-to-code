#include "core/env/env.h"
#include "lib/libft.h"
#include "utils/utils.h"

#define KEY_MAX 1000000

t_env *init_env(char **envp)
{
    t_env   *ret;
    char    *key;
    char    *value;
    int     idx;

    ret = init_list();
    idx = -1;
    while (envp[++idx])
    {
        ft_get_key_value(envp[idx], &key, &value);
        insert_env(ret, key, value);
        free(key);
        free(value);
    }
    return (ret);
}

static t_env    *search_env_node(t_env *env, char *key)
{
    t_env *node;
    t_env_data  *data;

    node = env->next;
    while (node)
    {
        data = node->data;
        if (ft_strncmp(data->key, key, KEY_MAX) == 0)
            break;
        node = node->next;
    }
    return (node);
}

char    *search_env(t_env *env, char *key)
{
    t_env   *node;
    t_env_data  *data;
    
    node = search_env_node(env, key);
    if (!node)
        return (NULL);
    data = node->data;
    return (data->value);
}

int change_env(t_env *env, char *key, char *value)
{
    t_env   *node;
    t_env_data  *data;
    
    node = search_env_node(env, key);
    if (!node)
        return (ERROR);
    data = node->data;
    free(data->value);
    data->value = ft_strdup(value);
    return (OK);
}


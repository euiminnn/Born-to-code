#include "core/env.h"
#include "lib/libft.h"
#include "utils/utils.h"

#define KEY_MAX 1000000

static t_env *make_env_node(char *key, char *value)
{
    t_env *env;

    env = (t_env *)malloc(sizeof(t_env));
    if (!env)
        exit(12);
    env->key = key;
    env->value = value;
    env->next = NULL;
    return (env);
}

char **get_key_value(char* line)
{
    char    **output;
    char    *equal;

    output = malloc(sizeof(char *) * 2);
    equal = line;
    while (*equal && *equal != '=')
        equal++;
    if (*equal)
    {
        *equal = '\0';
        output[0] = ft_strdup(line);
        output[1] = ft_strdup(equal + 1);
    }
    else
    {
        output[0] = ft_strdup(line);
        output[1] = NULL;
    }
    return (output);
}

// TODO: key_value 변수 free 제대로 할것
t_env *init_env(char **envp)
{
    t_env   *output;
    char    **key_value;
    int     idx;

    output = make_env_node(NULL, NULL);
    idx = -1;
    while (envp[++idx])
    {
        key_value = get_key_value(envp[idx]);
        insert_env(output, key_value[0], key_value[1]);
        free(key_value);
    }
    return (output);
}

char    *search_env(t_env *env, char *key)
{
    t_env *node;

    node = env->next;
    while (node)
    {
        if (ft_strncmp(node->key, key, KEY_MAX) == 0)
            break;
        node = node->next;
    }
    if (!node)
        return (NULL);
    return (node->value);
}

static t_env    *search_env_position(t_env *env, char *key)
{
    t_env *node;

    node = env;
    while (node->next)
    {
        if (ft_strncmp(node->next->key, key, KEY_MAX) > 0)
            break;
        node = node->next;
    }
    return (node);
}

void    insert_env(t_env *env, char *key, char *value)
{
    t_env *insert_position;
    t_env *new_node;

    new_node = make_env_node(key, value);
    insert_position = search_env_position(env, key);
    new_node->next = insert_position->next;
    insert_position->next = new_node;
}

void remove_env(t_env *env, char *key)
{
    t_env *delete_position;
    t_env *del_node;

    delete_position = search_env_position(env, key);
    del_node = delete_position->next;
    delete_position->next = delete_position->next->next;
    free(del_node);
}

void free_env(t_env *env)
{
    if (env->next)
        free_env(env->next);
    free(env->key);
    if (env->value)
        free(env->value);
}

static int count_env(t_env *env)
{
	int		size;
	t_env	*node;

	size = 0;
	node = env->next;
	while (node)
	{
		++size;
		node = node->next;
	}
	return (size);
}

char    **export_env(t_env *env)
{
    char    **rt;
    int     size;
    int     idx;
    t_env	*node;

    size = count_env(env);
    rt = (char **)malloc(sizeof(char *) * (size + 1));
    if (!rt)
        ft_exit(12);
    idx = 0;
    node = env->next;
    while (node)
    {
        if (node->value)
            rt[idx] = ft_strjoins((char *[3]){node->key, "=", node->value}, 3);
        else
            rt[idx] = ft_strdup(node->key);
        node = node->next;
        ++idx;
    }
    rt[idx] = 0;
    return (rt);
}

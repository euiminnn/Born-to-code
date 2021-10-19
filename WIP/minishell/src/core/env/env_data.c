#include "core/env/env.h"
#include "lib/libft.h"
#include "utils/utils.h"

#define KEY_MAX 1000000

t_env_data   *init_env_data(char *key, char *value)
{
    t_env_data *data;

    data = (t_env_data *)malloc(sizeof(t_env_data));
    if (!data)
        exit(12);
    data->key = ft_strdup(key);
    data->value = ft_strdup(value);
    return (data);
}

void free_env_data(void *v_data)
{
    t_env_data  *data;
    
    data = (t_env_data *)v_data;
    free(data->key);
    free(data->value);
    free(data);
}

char	*to_string_env_data(t_env_data *data)
{
	if (!data->value)
		return (NULL);
	return (ft_strjoins((char *[3]){data->key, "=", data->value}, 3));
}

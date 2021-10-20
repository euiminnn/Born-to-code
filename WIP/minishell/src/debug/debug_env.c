#include "debug/debug_env.h"
#include "utils/utils.h"

static char	*to_string(t_env_data *data)
{
	if (data->value)
		return (ft_strjoins((char *[3]){data->key, "=", data->value}, 3));
	return (ft_strjoins((char *[3]){data->key, "=", "(null)"}, 3));
}

int    print_env(t_env *env)
{
	char	**envp;
	int		idx;
	
	envp = to_string_env(env, to_string);
	idx = -1;
	while (envp[++idx])
		printf("%s\n", envp[idx]);
	ft_free_strings(envp);
    return (OK);
}
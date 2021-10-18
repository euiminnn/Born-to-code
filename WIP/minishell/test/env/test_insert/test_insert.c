#include "core/env.h"
#include "debug/debug_utils.h"

t_env *env;

void test(char *test_name, char *key, char *value)
{
    int i;
    char **result;

    printf("----- %s -----\n", test_name);

    insert_env(env, key, value);

    result = export_env(env);
    i = -1;
    while (result[++i])
        printf("%s\n", result[i]);
    ft_free_strings(result);
}

int main(int ac, char **av, char **en)
{
    char **envp;

    envp = ft_split(
        "KEY=VALUE\n"
        "B=10\n"
        "A=20\n"
        "b=30\n"
        "a=40\n"
        "NOVALUE"
        , '\n');
    env = init_env(envp);

    test("normal", "normal");
    return (0);
}

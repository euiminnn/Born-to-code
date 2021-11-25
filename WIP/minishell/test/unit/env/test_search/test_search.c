#include "core/env/env.h"
#include "lib/libft.h"
#include "debug/debug_env.h"

t_env *env;

void test(char *test_name, char *key)
{
    char    *value;

    printf("----- %s -----\n", test_name);

    value = search_env(env, key);
    if (value)
        printf("%s\n", value);
    else
        printf("(null)\n");
}

int main(int ac, char **av, char **en)
{
    char **envp;

    envp = ft_split(
        "AAA=10\n"
        "BBB=10\n"
        "CCC=10\n"
        "aaa\n"
        "bbb=10\n"
        , '\n');
    env = init_mock_env(envp);

    test("search CCC", "CCC");

    test("search aaa", "aaa");

    test("search DDD", "DDD");
    return (0);
}

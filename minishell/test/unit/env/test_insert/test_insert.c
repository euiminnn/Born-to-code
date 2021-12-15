#include "core/env/env.h"
#include "lib/libft.h"
#include "debug/debug_env.h"

t_env *env;

void test(char *test_name, char *key, char *value)
{
    printf("----- %s -----\n", test_name);

    insert_env(env, key, value);

    print_env(env);
}

int main(int ac, char **av, char **en)
{
    char **envp;

    envp = ft_split("", '\n');
    env = init_mock_env(envp);

    test("normal", "BBB", "1");
    test("normal", "ddd", "2");
    test("normal", "FFF", "3");

    test("novalue", "CCC", 0);
    test("novalue", "DDD", "");
    return (0);
}

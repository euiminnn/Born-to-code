#include "core/env/env.h"
#include "lib/libft.h"
#include "debug/debug_env.h"

t_env *env;

void test(char *test_name, char *key)
{
    int ret;

    printf("----- %s -----\n", test_name);

    ret = remove_env(env, key);

    print_env(env);
    printf("->\n");
    printf("%d\n", ret);
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

    test("del CCC", "CCC");

    test("del aaa", "aaa");

    test("del DDD", "DDD");
    return (0);
}

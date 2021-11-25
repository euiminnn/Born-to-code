#include "core/env/env.h"
#include "lib/libft.h"
#include "debug/debug_env.h"

t_env *env;

void test(char *test_name, char *key, char *value)
{
    int ret;

    printf("----- %s -----\n", test_name);

    ret = change_env(env, key, value);

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

    test("change CCC", "CCC", "30");

    test("change aaa", "aaa", "40");

    test("change bbb", "bbb", 0);

    test("change AAA", "AAA", "");

    test("change DDD", "DDD", "50");
    return (0);
}

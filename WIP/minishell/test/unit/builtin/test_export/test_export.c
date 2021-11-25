#include "core/builtin.h"
#include "debug/debug_utils.h"
#include "debug/debug_env.h"

t_env *env;

static int get_argc(char **argv)
{
    int i;

    i = 0;
    while (*argv++)
        i++;
    return (i);
}

void test(char *test_name, char *line)
{
    int argc;
    char **argv;
    int ret;

    printf("----- %s -----\n", test_name);
    fflush(stdout);

    argv = ft_split(line, ' ');
    argc = get_argc(argv);
    ret = builtin_export(argc, argv, env, 1);

    fflush(stdout);
    printf("->\n");
    printf("%d\n", ret);
    printf("=>\n");
    print_env(env);
    fflush(stdout);
    ft_free_strings(argv);
}

int main(int ac, char **av, char **en)
{
    char **envp = ft_split(
        "A=10\n"
        "B=20",
        '\n');
    env = init_mock_env(envp);

    test("print", "export");

    test("add_1", "export TEST=10");
    test("add_2", "export test=yoyo=yaya");

    test("override_1", "export TEST=20");

    free_env(env);
    env = init_mock_env(envp);
    test("add_multi_1", "export TEST2=10 TEST3=10"); // 해도 되고 안해도 되고.. ->했어요

    free_env(env);
    env = init_mock_env(envp);
    test("novalue_1", "export TEST4");
    test("novalue_2", "export TEST5=");
	test("novalue_print", "export");

    test("error_1", "export 1TEST=20"); // 해도 되고 안해도 되고..
    test("error_2", "export TEST[=20"); // 해도 되고 안해도 되고..
    test("error_3", "export =20"); // 해도 되고 안해도 되고..
    test("error_4", "export ="); // 해도 되고 안해도 되고..


    return (0);
}

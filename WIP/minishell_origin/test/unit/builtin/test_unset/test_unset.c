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
    ret = builtin_unset(argc, argv, env, 1);

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
        "B=20\n"
        "C=30\n"
        "D=40\n"
        "E=50",
        '\n');
    env = init_mock_env(envp);
	test("normal", "unset A");

	free_env(env);
    env = init_mock_env(envp);
	test("multiple", "unset A B");

	free_env(env);
    env = init_mock_env(envp);
    test("with value", "unset A B=20");

    return (0);
}

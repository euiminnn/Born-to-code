#include "core/execute/execute.h"
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

void test(char *test_name, char *line, int willexit)
{
    int argc;
    char **argv;
    int ret;
    int status;

    printf("----- %s -----\n", test_name);
    fflush(stdout);

    argv = ft_split(line, ' ');
    argc = get_argc(argv);
    if (willexit)
    {
        if (fork() == 0)
        {
            exit(builtin_exit(argc, argv, env, 1));
        }
        wait(&status);
    }
    else
    {
        status = builtin_exit(argc, argv, env, 1);
        status <<= 8;
    }

    fflush(stdout);
    printf("->\n");
    printf("%d\n", WEXITSTATUS(status));
    fflush(stdout);
    ft_free_strings(argv);
}

int main(int ac, char **av, char **en)
{
    env = init_mock_env(en);

    g_exit_code = 42;
    test("normal", "exit", 1);

    test("number", "exit 42", 1);
    test("negative", "exit -42", 1);

    test("multi", "exit 42 42", 0); // shell 을 종료하지 않는다면, 적절한 exit_code 를 return 해야한다.
    test("alpha", "exit hi", 1);

    test("multi_alpha_1", "exit hi 42", 1);
    test("multi_alpha_2", "exit 42 hi", 0);
    test("multi_alpha_3", "exit hi hello", 1);

    return (0);
}

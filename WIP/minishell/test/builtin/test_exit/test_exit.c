#include "core/execute/execute.h"
#include "core/builtin.h"
#include "debug/debug_utils.h"

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

    ft_putstr_fd("----- ", 1);
    ft_putstr_fd(test_name, 1);
    ft_putstr_fd(" -----\n", 1);

    argv = ft_split(line, ' ');
    argc = get_argc(argv);
    if (willexit)
    {
        if (fork() == 0)
        {
            builtin_exit(argc, argv, env, 1);
            exit(0);
        }
        wait(&status);
    }
    else
    {
        status = builtin_exit(argc, argv, env, 1);
        status <<= 8;
    }

    ft_putstr_fd("->\n", 1);
    ft_putnbr_fd(status >> 8, 1);
    ft_putstr_fd("\n", 1);
    ft_free_strings(argv);
}

int main(int ac, char **av, char **en)
{
    env = init_env(en);

    test("normal", "exit", 1);

    test("number", "exit 42", 1);
    test("negative", "exit -42", 1);

    test("mutli", "exit 42 42", 0);
    test("alpha", "exit hi", 1);

    test("multi_alpha_1", "exit hi 42", 1);
    test("multi_alpha_2", "exit 42 hi", 0);
    test("multi_alpha_3", "exit hi hello", 1);

    return (0);
}

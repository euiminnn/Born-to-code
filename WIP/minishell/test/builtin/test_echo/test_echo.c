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

void test(char *test_name, char *line)
{
    int argc;
    char **argv;
    int ret;

    ft_putstr_fd("----- ", 1);
    ft_putstr_fd(test_name, 1);
    ft_putstr_fd(" -----\n", 1);

    argv = ft_split(line, ' ');
    argc = get_argc(argv);
    ret = builtin_echo(argc, argv, env, 1);

    ft_putstr_fd("$\n->\n", 1);
    ft_putnbr_fd(ret, 1);
    ft_putstr_fd("\n", 1);
    ft_free_strings(argv);
}

int main(int ac, char **av, char **en)
{
    env = init_env(en);

    test("normal_1", "echo hello");
    test("normal_2", "echo hello world");
    test("normal_3", "echo hello world world");
    test("normal_4", "echo -n hello");
    test("normal_5", "echo hello -n");

    test("other_1", "echo -b hello");
    test("other_2", "echo hello -b");

    test("several_1", "echo -nnnnn hello");
    test("several_2", "echo hello -nnnn");
    test("several_other_1", "echo -nnna hello");
    test("several_other_2", "echo -nann hello");
    test("several_other_3", "echo hello -nnna");
    test("several_other_4", "echo hello -nann");

    test("multi_1", "echo -n -n hello");
    test("multi_2", "echo -n -n -n hello");
    test("multi_3", "echo hello -n -n ");
    test("multi_4", "echo -n -n -n hello -n -n ");
    test("multi_other_1", "echo -b -n -n hello");
    test("multi_other_2", "echo -n -b -n hello");
    test("multi_other_3", "echo -n -n -b hello");
    test("multi_other_4", "echo hello -n -b -n");
    test("multi_other_5", "echo -n -b -n hello -n -b -n");

    test("several_multi_1", "echo -nnn -nn hello");
    test("several_multi_2", "echo hello -nnn -nn");
    test("several_multi_3", "echo -nnnn -nnn hello -nnn -nn");
    test("several_multi_other_1", "echo -nnn -nnb hello");
    test("several_multi_other_2", "echo -nbn -nnn hello");
    test("several_multi_other_3", "echo -nnnn -bnn -nnn hello");
    test("several_multi_other_4", "echo hello -nn -nb -b");

    return (0);
}

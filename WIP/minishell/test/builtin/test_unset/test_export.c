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
    ret = builtin_export(argc, argv, env, 1);

    ft_putstr_fd("->\n", 1);
    ft_putnbr_fd(ret, 1);
    ft_putstr_fd("\n", 1);
    ft_free_strings(argv);
}

int main(int ac, char **av, char **en)
{
    char **envp = ft_split(
        "A=10\n" 
        "B=20",
        '\n');
    env = init_env(envp);

    test("print", "export");

    test("add_1", "export TEST=10");
    test("add_1_print", "export");

    test("add_2", "export TEST2=10 TEST3=10");
    test("add_2_print", "export");

    test("add_3", "export test=yoyo=yaya");
    test("add_3_print", "export");

    // test("override_1", "export TEST=20");
    // test("override_1_print", "export");

    // test("plus_1", "export TEST+=20");
    // test("plus_1_print", "export");

    test("error_1", "export 1TEST=20");
    test("error_2", "export TEST[=20");

    test("novalue_1", "export TEST4");
    test("novalue_1_print", "export");

    test("novalue_2", "export TEST5=");
    test("novalue_2_print", "export");

    return (0);
}

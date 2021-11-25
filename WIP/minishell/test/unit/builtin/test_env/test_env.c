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
    ret = builtin_env(argc, argv, env, 1);

    fflush(stdout);
    printf("->\n");
    printf("%d\n", ret);
    fflush(stdout);
    ft_free_strings(argv);
}

int main(int ac, char **av, char **en)
{
	char **envp = ft_split(
			"TEST_A=10\n"
			"TEST_B=20\n"
			"TEST_C=30",
			'\n');
	env = init_mock_env(envp);

    test("env only", "env");

    test("key only", "env A");

	test("env with 1 set(key+value)", "env A=3");

	test("env with 2 sets", "env A=3 B=4");

	//test("env with spaces", "env "C = 5"");
    return (0);
}

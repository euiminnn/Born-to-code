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

    printf("----- %s -----\n", test_name);
    fflush(stdout);

    argv = ft_split(line, ' ');
    argc = get_argc(argv);
    ret = builtin_cd(argc, argv, env, 1);

    fflush(stdout);
    printf("->\n");
    printf("%d\n", ret);
    fflush(stdout);
    ft_free_strings(argv);
}

int main(int ac, char **av, char **en)
{
    env = init_env(en);
    
    test("env only", "env");
    
    test("key only", "env A");
    
	test("env with 1 set(key+value)", "env A=3");
	
	test("env with 2 sets", "env A=3 B=4");

    return (0);
}

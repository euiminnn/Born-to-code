#include "core/parse/parse.h"
#include "debug/debug_utils.h"

// 기본은 스페이스 단위, but "" 또는 ''로 묶여있는거 제외

void test(char *test_name, char *line)
{
    char **strs = 0;
    int ret;

    printf("----- %s -----\n", test_name);

    ret = tokenizer(line, &strs);

    print_strings(strs, 0);
    printf("->\n");
    printf("%d\n", ret);
    if (!ret)
        printf("errno %d\n", errno);
}

int main()
{
    test("test1", ft_strdup("echo hello"));
    test("test2", ft_strdup("echo hello world"));
    test("test2-1", ft_strdup("echo -n $USER"));
    test("test2-2", ft_strdup("echo \"$USER\""));

    test("test3", ft_strdup("\"echo\" hello"));
    test("test3-1", ft_strdup("\"e\"c\'h\'o hello"));
    test("test3-1-1", ft_strdup("\"e\"\'ch\'o hello"));
    test("test3-1-2", ft_strdup("\"\"\'\'o hello"));
    test("test3-2", ft_strdup("echo \"hello\" world"));
    test("test4", ft_strdup("echo \"hello world\""));
    test("test5", ft_strdup("echo \"hello world\"hello"));
    test("test6", ft_strdup("echo \"\"hello"));
    test("test6-1", ft_strdup("echo \"\""));
    test("test6-2", ft_strdup("echo abc\"\""));

    test("test7", ft_strdup("echo \"hello"));
    test("test8", ft_strdup("echo \'hello"));

    test("test9", ft_strdup("echo hello;"));
    test("test9-1", ft_strdup("echo hello\\"));
    test("test9-2", ft_strdup(";echo hello\\"));
    test("test10", ft_strdup(";ec\'ho hello\\"));


    test("test11", ft_strdup("echo hello > a | cat a | cat < a > b"));
    test("test11-1", ft_strdup("echo hello>a|cat a|cat<a>b"));

    test("test12", ft_strdup("echo hel\'lo>a|c\'at a|cat<a>b"));
    return (0);
}

#include "core/parse/parse.h"
#include "debug/debug_utils.h"

void test(char *test_name, char *line)
{
    char *input;
    char **strs = 0;
    int ret = 1;

    printf("----- %s -----\n", test_name);

    fflush(stdout);
    fflush(stderr);
    input = ft_strdup(line);
    tokenizer(input, &strs);
    free(input);

    fflush(stdout);
    fflush(stderr);
    print_strings(strs, 0);
    printf("->\n");
    printf("%d\n", ret);
    if (!ret)
        printf("errno %d\n", g_exit_code);

}

int main()
{
    test("normal_1", "echo hello");
    test("normal_2", "echo hello world");
    test("normal_3", "echo -n $USER");

    test("quote_1", "echo \"$USER\"");
    test("quote_2", "\"echo\" hello");
    test("quote_3", "\"e\"c\'h\'o hello");
    test("quote_4", "\"e\"\'ch\'o hello");
    test("quote_5", "\"\"\'\'o hello");
    test("quote_6", "echo \"hello\" world");
    test("quote_7", "echo \"hello world\"");
    test("quote_8", "echo \"hello world\"hello");
    test("quote_9", "echo \"\"hello");
    test("quote_10", "echo \"\"");
    test("quote_11", "echo abc\"\"");

    test("quote_mix_1", "echo \"aa\'bb\'cc\"");
    test("quote_mix_2", "echo \"aa\'bb\"cc\'");
    test("quote_mix_3", "echo \"aa\'bb\"cc\'dd\'");
    test("quote_mix_4", "echo \'aa\"bb\'cc\"dd\'");
    test("quote_mix_5", "echo \'aa\"bb\'c\'c\"dd\'");
    test("quote_mix_6", "echo aa\'aa\"bb\'c\'c\"dd\'ee");

    test("error_1", "echo \"hello");
    test("error_1_1", "echo \'hello");

    test("error_2", "echo hello;");
    test("error_2_1", "echo hello\\");
    test("error_2_2", ";echo hello\\");
    test("error_2_3", ";ec\'ho hello\\");

    test("complicate_1", "echo hello > a | cat a | cat < a > b");
    test("complicate_2", "echo hello>a|cat a|cat<a>b");

    test("complicate_3", "echo hel\'lo>a|c\'at a|cat<a>b");
    return (0);
}

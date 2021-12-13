#include "core/parse/parse.h"
#include "debug/debug_utils.h"
#include "debug/debug_env.h"

t_env *env;
t_token *token;

void test(char *test_name, char *str)
{
    printf("----- %s -----\n", test_name);

    token->value = ft_strdup(str);
    replace_tilde_in_token(token, env);
    replace_env_in_token(token, env);
    printf("%s\n", token->value);
    free(token->value);
}

int main(int ac, char **av, char **en)
{
    g_exit_code = 100;
    env = init_mock_env(en);
    token = init_token(T_ARG, 0);
    insert_env(env, "TEST", "yeah");

    test("normal_1", "echo_echo");

    test("env_1", "$TEST");
    test("env_1_1", "$NOTEST");
    test("env_2", "$TEST abc");
    test("env_2_1", "$NOTEST abc");
    test("env_3", "abc$TEST");
    test("env_3_1", "abc$NOTEST");
    test("env_4", "abc$TEST abc");
    test("env_4_1", "abc$NOTEST abc");
    test("env_5", "abc$TESTabc");
    test("env_6", "abc$TEST\"abc\"");
    test("env_7", "abc$TEST\'abc\'");
    test("env_8", "abc$TE[STa]bc");
    test("env_9", "abc$");
    test("env_10", "$");
    test("env_11", "$?");
    test("env_12", "$??");
    test("env_13", "$?hello");
    test("env_14", "$?$TEST");

    test("env_num_1", "$1");
    test("env_num_2", "$9");
    test("env_num_3", "$10");
    test("env_num_4", "$123");
    test("env_num_5", "$9$TEST");

    test("env_quote_1", "\"$TEST\"");
    test("env_quote_2", "\'$TEST\'");
    test("env_quote_3", "\"\'$TEST\'\"");
    test("env_quote_4", "\'\"$TEST\"\'");
    test("env_quote_5", "\"$TEST\"\'$TEST\'");
    // test("env_quote_3", "$\'TEST\'"); -- TEST GIVEUP!!

    test("quote_1", "echo \"hello\"");
    test("quote_2", "\"echo\" hello");
    test("quote_3", "\"e\"c\'h\'o hello");
    test("quote_4", "\"e\"\'ch\'o hello");
    test("quote_5", "\"\"\'\'o hello");
    test("quote_6", "echo \"hello\" world");
    test("quote_7", "echo \"hello world\"");
    test("quote_8", "echo \"hello world\"hello");
    test("quote_9", "echo \"\"hello");
    test("quote_10", "echo\"\"");
    test("quote_11", "echo abc\"\"");

    test("quote_mix_1", "\"\'\"\'hello\'");
    test("quote_mix_2", "echo \"aa\'bb\'cc\"");
    test("quote_mix_3", "echo \"aa\'bb\"cc\'dd\'");
    test("quote_mix_4", "echo \'aa\"bb\'c\'c\"dd\'");
    test("quote_mix_5", "echo aa\'aa\"bb\'c\'c\"dd\'ee");

    test("tilde_normal_1", "~");
    test("tilde_with_char_1", "~abc");
    test("tilde_with_char_2", "abc~");
    test("tilde_path_1", "~/abc");
    test("tilde_path_2", "abc/~");
    test("tilde_path_3", "~///");
    test("tilde_in_quote_1", "\"~\"");
    test("tilde_in_quote_2", "\"~/abc\"");
    test("tilde_in_quote_3", "abc\"~/abc\"");
    test("tilde_in_quote_4", "~\"/abc\"");

    test("unclosed_quote_1", "echo \"hello");
    test("unclosed_quote_2", "echo hello\"");
    test("unclosed_quote_3", "echo hello\"hello");
    test("unclosed_quote_4", "echo \"hello\"\'");
    test("unclosed_quote_5", "echo \'hello\'\"");

    return (0);
}

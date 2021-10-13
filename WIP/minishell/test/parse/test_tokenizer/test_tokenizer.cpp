#include "core/parse/parse.h"

// cat < a a < b b < c << hi > x >> y

/*

["cat", "<", "a", "a", "<"]

*/


// "echo"

/*

[""echo""]

*/

// echo "hello       world"env

/*

["echo", ""hello       world"env"]

*/

// echo -n hello

// echo hello > a | cat a | cat < a > b

// echo "$USER"

// 기본은 스페이스 단위, but "" 또는 ''로 묶여있는거 제외

int test1()
{
    char line[] = "echo \"hello     world\"env";
    char **ret;
    
    tokenizer(line, &ret);
}

int main()
{
    test1();
    return (0);
}
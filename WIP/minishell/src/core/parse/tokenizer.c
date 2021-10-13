#include "core/parse/parse.h"
#include "utils/utils.h"

#define BUFFER_SIZE 42000
#define SPACE 1

static int convert_quote(char *line);
static int convert_symbol(char *line, char *buf);
static void revert_quote(char *str);

/**
 * line 에 있는 기호 양 옆에 스페이스를 넣어주고, (따움표 제외)
 * 따움표 안의 스페이스를 SPACE로 바꾸고,
 * ' ' 기준으로 split 한다.
 * 마지막으로 lexer를 호출해서 토큰을 구한다.
 *
 * @example line : echo hello > abc | cat << abc
 * @example strings : ['echo', 'hello', '>', 'abc', '|', 'cat', '<<' ,'abc']
 */
int tokenizer(char *line, char ***strings)
{
    char    buf[BUFFER_SIZE];
    int     idx;

    if (!convert_quote(line))
        return (ERROR);
    if (!convert_symbol(line, buf))
        return (ERROR);
    idx = -1;
    *strings = ft_split(buf, ' ');
    while ((*strings)[++idx])
        revert_quote((*strings)[idx]);
    return (OK);
}

static int convert_quote(char *line)
{
    int     flag;
    char    quote;

    flag = 0;
    while (*line)
    {
        if (!flag)
        {
            if (*line == '\'' || *line == '\"')
                flag = 1;
            quote = *line;
        }
        else
        {
            if (*line == quote)
                flag = 0;
            else
                *line *= -1;
        }
        ++line;
    }
    if (flag)
        return (ERROR);
    return (OK);
}

static int convert_symbol(char *line, char *buf)
{
    while (*line)
    {
        if (ft_strchr("()?;\\", *line))
            return (ERROR);
        if (ft_strchr("<>|", *line))
        {
            *buf++ = ' ';
            *buf++ = *line;
            if (*line == *(line + 1))
                *buf++ = *line++;
            *buf = ' ';
        }
        else
            *buf = *line;
        ++buf;
        ++line;
    }
    *buf = '\0';
    return (OK);
}

static void revert_quote(char *str)
{
    while (*str)
    {
        if (*str < 0)
            *str *= -1;
        ++str;
    }
}

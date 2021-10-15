#include "lib/libft.h"
#include "core/parse/parse.h"
#include "core/parse/token.h"
#include "core/env.h"
#include "define.h"

#define BUFFER_SIZE 420000

static int find_dallor(char **ptr, char **buf);
static char	*find_key(char *str);
static char	*find_key_from_env(char **key_start, char *key_end, t_env *env);
static char *remove_quote(char *str);

/**
 * $ 나올때 까지 돌기 ('')
 * $ 나오면, key 찾기, (가능한 key 참고) [a-zA-Z_][a-zA-Z0-9_]*
 * key 에 해당하는 value 를 찾는다
 * value 를 buf 에 붙여넣는다
 * 마지막으로 따옴표를 뻰다.
 *
 * @example abc"hello$USER asdf"abc
 * @example abc"helloycha asdf"abc
 * @example abchelloycha asdfabc
 */

void replace_env_in_token(t_token *token, t_env *env)
{
	char	buf[BUFFER_SIZE];
	char	*buf_ptr;
	char	*str_ptr;
	char	*key_last_ptr;
	char	*value;

	buf_ptr = buf;
	str_ptr = token->value;
	while (find_dallor(&str_ptr, &buf_ptr))
	{
		key_last_ptr = find_key(str_ptr);
		if (str_ptr + 1 == key_last_ptr)
		{
			*buf_ptr++ = *str_ptr++;
			continue;
		}
		value = find_key_from_env(&str_ptr, key_last_ptr, env);
		if (!value)
			continue;
		ft_memcpy(buf_ptr, value, ft_strlen(value));
		buf_ptr += ft_strlen(value);
		free(value);
	}
	*buf_ptr = '\0';
	free(token->value);
	token->value = remove_quote(buf);
}

static int find_dallor(char **ptr, char **buf)
{
	while (**ptr)
	{
		if(**ptr == '$')
			return (TRUE);
		if (**ptr == '\'')
		{
			*(*buf)++ = *(*ptr)++;
			while (**ptr && **ptr != '\'')
				*(*buf)++ = *(*ptr)++;
		}
		if (**ptr)
			*(*buf)++ = *(*ptr)++;
	}
	return (FALSE);
}

static char	*find_key(char *str)
{
	int		index;
	char	*charset;

	index = 1;
 	while (str[index])
	{
		charset = CHARSET_WITH_DIGIT;
		if (index == 1)
			charset = CHARSET_WITH_Q;
		if (ft_strchr(charset, str[index]))
			++index;
		else
			break;
	}
	return (&str[index]);
}

static char	*find_key_from_env(char **key_start, char *key_end, t_env *env)
{
	char	key_end_value;
	char	*value;
	char	*ret;

	ret = 0;
	key_end_value = *key_end;
	*key_end = '\0';
	if (*(*key_start + 1) == '?')
	{
		ret = ft_itoa(errno);
		*key_start += 2;
	}
	else
	{
		value = search_env(env, *key_start + 1);
		if (value)
			ret = ft_strdup(value);
		*key_start = key_end;
	}
	*key_end = key_end_value;
	return (ret);
}

static char *remove_quote(char *str)
{
	char	buf[BUFFER_SIZE];
	char	quote;
	int		idx;

	idx = 0;
	while (*str)
	{
		if (*str == '\'' || *str == '\"')
		{
			quote = *str;
			str++;
			while (*str && *str != quote)
				buf[idx++] = *str++;
			if (*str)
				str++;
		}
		else
			buf[idx++] = *str++;
	}
	buf[idx] = '\0';
	return (ft_strdup(buf));
}
